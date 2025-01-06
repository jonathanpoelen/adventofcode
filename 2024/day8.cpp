/*
{
  echo '#include <jln/mp/list/list.hpp>'
  echo '#include <jln/mp/number/number.hpp>'
  echo 'using namespace jln::mp;'
  echo 'using input = list<'
  sed -E "
    s/./, number<'&'>/g
    s/^,/, list</
    s/\$/>/
    1s/,/ /
  "
  echo '>;'
} < input > day8.hpp
*/

#if defined(TEST) && TEST
#include <jln/mp/algorithm/make_int_sequence.hpp>
using namespace jln::mp;

constexpr char s[] =
//           10
// 0123456789 11
  "............" // 0
  "........0..." // 1
  ".....0......" // 2
  ".......0...." // 3
  "....0......." // 4
  "......A....." // 5
  "............" // 6
  "............" // 7
  "........A..." // 8
  ".........A.." // 9
  "............" // 10
  "............" // 11
// 0123456789 11
//           10
/*
// 0123456789 11
  "##....#....#" // 0
  ".#.#....0..." // 1
  "..#.#0....#." // 2
  "..##...0...." // 3
  "....0....#.." // 4
  ".#...#A....#" // 5
  "...#..#....." // 6
  "#....#.#...." // 7
  "..#.....A..." // 8
  "....#....A.." // 9
  ".#........#." // 10
  "...#......##" // 11
// 0123456789 11
//           10
*/
;

constexpr int wh = 12;

struct to_input
{
  template<int_t... i>
  struct f
  {
    template<int n, char const (&s)[wh*wh+1]>
    using line = list<number<s[n+i]>...>;

    template<char const(&s)[wh*wh+1]>
    using from = list<line<i*wh, s>...>;
  };
};

using input = emp::make_int_sequence_v_c<wh, to_input>::from<s>;
#else
#include "day8.hpp"
#endif

#include <jln/mp/algorithm/make_int_sequence.hpp>
#include <jln/mp/algorithm/transform.hpp>
#include <jln/mp/algorithm/fold_xs.hpp>
#include <jln/mp/algorithm/remove.hpp>
#include <jln/mp/algorithm/unique.hpp>
#include <jln/mp/algorithm/same.hpp>
#include <jln/mp/list/join.hpp>
#include <jln/mp/list/push_front.hpp>


template<int wh, int x, int y, bool = 0 <= x && x < wh && 0 <= y && y < wh>
struct wrapped_case_or_empty
{
  using type = list<>;
};

template<int wh, int x, int y>
struct wrapped_case_or_empty<wh, x, y, true>
{
  using type = list<number<y * wh + x>>;
  //using type = list<list<number<x>, number<y>>>;
};


template<class C>
struct frequency_for
{
  template<class s, class x, class... xs>
  using f = typename join<>::f<s, typename C::template f<x::value, xs::value>...>;
};


template<class C, class, class>
struct compute_frequencies;

template<class C, class... antennas, class... indices>
struct compute_frequencies<C, list<antennas...>, list<indices...>>
{
  using impl = join<fold_xs<frequency_for<C>>>;

  template<class antenna>
  using f =
    typename impl
    ::template f<
      list<list<>>,
      emp::wrap_in_list_c<emp::same_xs_v<antenna, antennas>, indices>...
    >;
};

template<template<int> class C>
struct compute
{
  template<class... Lines>
  struct f
  {
    static constexpr int wh = sizeof...(Lines);
    using flat = join<>::f<Lines...>;
    using get_freqs = compute_frequencies<C<wh>, flat, emp::make_int_sequence_c<wh*wh>>;

    using type = typename
      unpack<
        remove_if<
          is<number<'.'>>,
          unique<
            transform<
              get_freqs,
              join<
                unique<
                  size<>
                >
              >
            >
          >
        >
      >
      ::template f<flat>;
  };
};


#if !defined(PART) || PART == 1

template<int wh>
struct compute_part1
{
  template<int i, int ii,
    int x = i % wh,
    int y = i / wh,

    int xx = ii % wh,
    int yy = ii / wh,

    int dx = x < xx ? xx - x : -(x - xx),
    int dy = y < yy ? yy - y : -(y - yy)
  >
  using f = typename
    join<>::f<
      typename wrapped_case_or_empty<wh,  x - dx,  y - dy>::type,
      typename wrapped_case_or_empty<wh, xx + dx, yy + dy>::type
    >;
};

using algo = lift_t<compute<compute_part1>::f>; // 259

#else

template<int wh, int x, int y, int xx, int yy, int dx, int dy>
struct expand
{
  template<int, int... i>
  using f = typename
    join<>::f<
      typename wrapped_case_or_empty<wh,  x - dx * i,  y - dy * i>::type...,
      typename wrapped_case_or_empty<wh, xx + dx * i, yy + dy * i>::type...,
      typename wrapped_case_or_empty<wh,  x , y>::type,
      typename wrapped_case_or_empty<wh, xx, yy>::type
    >;
};

template<int wh>
struct compute_part2
{
  template<int i, int ii,
    int x = i % wh,
    int y = i / wh,

    int xx = ii % wh,
    int yy = ii / wh,

    int dx = x < xx ? xx - x : -(x - xx),
    int dy = y < yy ? yy - y : -(y - yy)
  >
  using f = emp::make_int_sequence_v_c<wh, expand<wh, x, y, xx, yy, dx, dy>>;
};

using algo = lift_t<compute<compute_part2>::f>; // 927

#endif

using Result = unpack<algo>::f<input>;
Result result = 1;
