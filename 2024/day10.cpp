/*
{
  echo '#include <jln/mp/list/list.hpp>'
  echo '#include <jln/mp/number/number.hpp>'
  echo 'using namespace jln::mp;'
  echo 'using input = list<'
  sed -E "
    s/./, number<&>/g
    s/^,/, list</
    s/\$/>/
    1s/,/ /
  "
  echo '>;'
} < input > day10.hpp
*/

#if defined(TEST) && TEST
#include <jln/mp/number/numbers.hpp>
#include <jln/mp/algorithm/make_int_sequence.hpp>
using namespace jln::mp;

constexpr char s[] =
  "89010123"
  "78121874"
  "87430965"
  "96549874"
  "45678903"
  "32019012"
  "01329801"
  "10456732"
;

constexpr int wh = 8;

struct to_input
{
  template<int_t... i>
  struct f
  {
    template<int n, char const (&s)[wh*wh+1]>
    using line = list<number<s[n+i] - '0'>...>;

    template<char const(&s)[wh*wh+1]>
    using from = list<line<i*wh, s>...>;
  };
};

using input = emp::make_int_sequence_v_c<wh, to_input>::from<s>;
#else
#include "day10.hpp"
#endif


#include <jln/mp/algorithm/make_int_sequence.hpp>
#include <jln/mp/algorithm/unique.hpp>
#include <jln/mp/list/lookup.hpp>
#include <jln/mp/list/join.hpp>
#include <jln/mp/list/size.hpp>
#include <jln/mp/number/operators.hpp>


template<class G, int wh, int x, int y, bool is_valid = 0 <= x && x < wh && 0 <= y && y < wh>
inline constexpr int grid_get = -1;

template<class G, int wh, int x, int y>
inline constexpr int grid_get<G, wh, x, y, true> = G::template f<y>::template f<x>::value;


#if !defined(PART) || PART == 1

template<int i, class G, int wh, int x, int y, int = grid_get<G, wh, x, y>>
struct count_trailhead
{
  using type = list<>;
};

template<int i, class G, int wh, int x, int y>
struct count_trailhead<i, G, wh, x, y, i>
{
  using type = join<unique<>>::f<
    typename count_trailhead<i+1, G, wh, x-1, y>::type,
    typename count_trailhead<i+1, G, wh, x+1, y>::type,
    typename count_trailhead<i+1, G, wh, x, y-1>::type,
    typename count_trailhead<i+1, G, wh, x, y+1>::type
  >;
};

template<class G, int wh, int x, int y>
struct count_trailhead<0, G, wh, x, y, 0>
{
  using type = list<
    join<unique<size<>>>::f<
      typename count_trailhead<1, G, wh, x-1, y>::type,
      typename count_trailhead<1, G, wh, x+1, y>::type,
      typename count_trailhead<1, G, wh, x, y-1>::type,
      typename count_trailhead<1, G, wh, x, y+1>::type
    >
  >;
};

template<class G, int wh, int x, int y>
struct count_trailhead<9, G, wh, x, y, 9>
{
  using type = list<list<number<x>, number<y>>>;
};


template<class... l>
struct part1
{
  using grid = build_indexed_v<emp::build_indexed_v<l>...>;
  static constexpr int wh = sizeof...(l);

  struct count
  {
    template<int_t... p>
    using f = join<add<>>
      ::f<typename count_trailhead<0, grid, wh, p % wh, p / wh>::type...>;
  };

  using type = emp::make_int_sequence_v_c<wh*wh, count>;
};

using algo = lift_t<part1>; // _593

#else

template<int i, class G, int wh, int x, int y, int = grid_get<G, wh, x, y>>
struct count_trailhead2
  : number<0>
{};

template<int i, class G, int wh, int x, int y>
struct count_trailhead2<i, G, wh, x, y, i>
: number<
    count_trailhead2<i+1, G, wh, x-1, y>::value
    +
    count_trailhead2<i+1, G, wh, x+1, y>::value
    +
    count_trailhead2<i+1, G, wh, x, y-1>::value
    +
    count_trailhead2<i+1, G, wh, x, y+1>::value
  >
{};

template<class G, int wh, int x, int y>
struct count_trailhead2<9, G, wh, x, y, 9>
  : number<1>
{};


template<class... l>
struct part2
{
  using grid = build_indexed_v<emp::build_indexed_v<l>...>;
  static constexpr int wh = sizeof...(l);

  struct count
  {
    template<int_t... p>
    using f = number<
      (count_trailhead2<0, grid, wh, p % wh, p / wh>::value + ...)
    >;
  };

  using type = emp::make_int_sequence_v_c<wh*wh, count>;
};

using algo = lift_t<part2>; // _1192

#endif

using Result = unpack<algo>::f<input>;
Result result = 1;
