/*
{
  echo '#include <jln/mp/list/list.hpp>'
  echo '#include <jln/mp/number/number.hpp>'
  echo 'using namespace jln::mp;'
  echo 'using input = list<'
  sed -E '
    s/./, number<&>/g
    s/^,/ /
  '
  echo '>;'
} < input > day9.hpp
*/

#if defined(TEST) && TEST
#include <jln/mp/number/numbers.hpp>
using namespace jln::mp;

using input = emp::numbers<2,3,3,3,1,3,3,1,2,1,4,1,4,1,3,1,4,0,2>;
// 00...111...2...333.44.5555.6666.777.888899
// 0099811188827773336446555566..............
// 012345678901234567890123456789012345678901
// 0        10        20        30        40
#else
#include "day9.hpp"
#endif

#include <jln/mp/algorithm/make_int_sequence.hpp>
#include <jln/mp/algorithm/fold.hpp>
#include <jln/mp/algorithm/zip.hpp>
#include <jln/mp/algorithm/reverse.hpp>
#include <jln/mp/algorithm/scan.hpp>
#include <jln/mp/algorithm/merge.hpp>
#include <jln/mp/algorithm/take_while.hpp>
#include <jln/mp/list/push_front.hpp>
#include <jln/mp/list/pop_front.hpp>
#include <jln/mp/list/join.hpp>
#include <jln/mp/list/wrap_in_list.hpp>
#include <jln/mp/list/take_front.hpp>
#include <jln/mp/functional/lift.hpp>
#include <jln/mp/utility/conditional.hpp>
#include <jln/mp/number/operators.hpp>


template<int_t n>
inline constexpr int_t add_until = (n * n + n) / 2 - n;


#if !defined(PART) || PART == 1

template<int_t i, int_t free, class parent>
struct stack;


template<int_t checksum, int_t i, int_t n, class S, int_t limit>
struct accu_file {};

template<int_t checksum, int_t n, class S>
struct fill_space
{
  using type = number<checksum>;
};


/*
00...111...2...333.44.5555.6666.777.888899
009..111...2...333.44.5555.6666.777.88889.
0099.111...2...333.44.5555.6666.777.8888..
00998111...2...333.44.5555.6666.777.888...
009981118..2...333.44.5555.6666.777.88....
0099811188.2...333.44.5555.6666.777.8.....
009981118882...333.44.5555.6666.777.......
0099811188827..333.44.5555.6666.77........
00998111888277.333.44.5555.6666.7.........
009981118882777333.44.5555.6666...........
009981118882777333644.5555.666............
00998111888277733364465555.66.............
0099811188827773336446555566..............
                            ^ limit
*/

template<class s, class e, bool = true>
struct part1_iter;

// stage 1: count the number of files until limit
template<
  int_t checksum, int_t i, int_t n, class S, int_t limit,
  int_t file, int_t free
>
struct part1_iter<
  accu_file<checksum, i, n, S, limit>,
  list<number<file>, number<free>>,
  i + file < limit
>
{
  using type = accu_file<
    checksum + (add_until<i + file> - add_until<i>) * n,
    i + file + free,
    n + 1,
    stack<i+file, free, S>,
    limit
  >;
};

// stage 2: deal with limit
template<
  int_t checksum, int_t i, int_t n, int_t ii, int_t free, class S, int_t limit,
  int_t file, class T
>
struct part1_iter<
  accu_file<checksum, i, n, stack<ii, free, S>, limit>,
  list<number<file>, T>,
  !(i + file < limit)
>
: part1_iter<
    fill_space<
      checksum + (add_until<limit> - add_until<i * 2 - limit>) * n,
      n,
      S
    >,
    list<number<file + i - limit - free>, T>
  >
{};

// stage 3: fill free spaces
template<
  int_t checksum, int_t n, int_t i, int_t free, class S,
  int_t file, class T
>
struct part1_iter<
  fill_space<checksum, n, stack<i, free, S>>,
  list<number<file>, T>,
  file <= free
>
{
  using type = fill_space<
    checksum + (add_until<i + free> - add_until<i + free - file>) * n,
    n + 1,
    stack<i, free - file, S>
  >;
};

template<
  int_t checksum, int_t n, int_t i, int_t free, class S,
  int_t file, class T
>
struct part1_iter<
  fill_space<checksum, n, stack<i, free, S>>,
  list<number<file>, T>,
  free < file
>
: part1_iter<
    fill_space<
      checksum + (add_until<i + free> - add_until<i>) * n,
      n,
      S
    >,
    list<number<file - free>, T>
  >
{};


template<class s, class e>
using part1_next = typename part1_iter<s, e>::type;


template<int_t, int_t... i>
struct file_space_impl
{
  template<int_t... n>
  using f = number<( ((i & 1) * n) + ... )>;
};

template<class... n>
inline constexpr int_t file_space_v =
  emp::make_int_sequence_v_c<
    sizeof...(n)+1,
    lift_v_c<file_space_impl>
  >
  ::template f<n::value...>
  ::value;



// please, optimize jln::mp::batched_c<2>
template<class... F>
struct batched2_impl
{
  template<class C, class... n>
  using f = typename zip<C>::template f<
    typename join<>::f<typename F::template f<list<>, list<n>>...>,
    typename join<>::f<typename F::template f<list<n>, list<>>...>
  >;
};

template<int_t... i>
struct batched2 : batched2_impl<conditional_c<i & 1>...>
{};


template<class... n>
struct part1
: emp::make_int_sequence_v_c<
    sizeof...(n)+1,
    lift_v_c<batched2>
  >
  ::template f<
    push_front<
      accu_file<0, 0, 0, void, file_space_v<n...>>,
      fold<lift<part1_next>>
    >,
    n..., false_ // add false_ because sizeof...(n) is odd
  >
{};

using algo = lift_t<part1>; // 6346871685398

#else

constexpr int_t imax = 0xffffff;

struct make_space_map
{
  template<class... xs>
  struct f;

  template<class... i, int_t... n>
  struct f<list<number<n>, i>...>
  {
    using type = list<
      typename join<>::f<typename wrap_in_list_c<n == 1>::template f<i>...>,
      typename join<>::f<typename wrap_in_list_c<n == 2>::template f<i>...>,
      typename join<>::f<typename wrap_in_list_c<n == 3>::template f<i>...>,
      typename join<>::f<typename wrap_in_list_c<n == 4>::template f<i>...>,
      typename join<>::f<typename wrap_in_list_c<n == 5>::template f<i>...>,
      typename join<>::f<typename wrap_in_list_c<n == 6>::template f<i>...>,
      typename join<>::f<typename wrap_in_list_c<n == 7>::template f<i>...>,
      typename join<>::f<typename wrap_in_list_c<n == 8>::template f<i>...>,
      typename join<>::f<typename wrap_in_list_c<n == 9>::template f<i>...>
    >;
  };
};


template<int_t a, int_t b>
inline constexpr int_t min_v = a < b ? a : b;


template<int_t last>
struct before_last
{
  template<class a>
  using f = number<a::value < last>;
};


template<int_t, class s>
struct part2_next_map
{
  using type = s;
};

template<class ispace1, class... ispaces1, class... ispaces>
struct part2_next_map<1, list<list<ispace1, ispaces1...>, ispaces...>>
{
  using type = list<list<ispaces1...>, ispaces...>;
};

template<class ispaces1, class ispace2, class... ispaces2, class... ispaces>
struct part2_next_map<2, list<ispaces1, list<ispace2, ispaces2...>, ispaces...>>
{
  using type = list<ispaces1, list<ispaces2...>, ispaces...>;
};

template<class ispaces1, class ispaces2, class ispace3, class... ispaces3, class... ispaces>
struct part2_next_map<3, list<ispaces1, ispaces2, list<ispace3, ispaces3...>, ispaces...>>
{
  using type = list<ispaces1, ispaces2, list<ispaces3...>, ispaces...>;
};

template<
  class ispaces1, class ispaces2, class ispaces3, class ispace4, class... ispaces4,
  class... ispaces
>
struct part2_next_map<
  4, list<ispaces1, ispaces2, ispaces3, list<ispace4, ispaces4...>, ispaces...>
>
{
  using type = list<ispaces1, ispaces2, ispaces3, list<ispaces4...>, ispaces...>;
};

template<
  class ispaces1, class ispaces2, class ispaces3, class ispaces4,
  class ispace5, class... ispaces5, class... ispaces
>
struct part2_next_map<
  5,
  list<
    ispaces1, ispaces2, ispaces3, ispaces4, list<ispace5, ispaces5...>, ispaces...
  >
>
{
  using type = list<
    ispaces1, ispaces2, ispaces3, ispaces4, list<ispaces5...>, ispaces...
  >;
};

template<
  class ispaces1, class ispaces2, class ispaces3, class ispaces4, class ispaces5,
  class ispace6, class... ispaces6, class... ispaces
>
struct part2_next_map<
  6,
  list<
    ispaces1, ispaces2, ispaces3, ispaces4, ispaces5,
    list<ispace6, ispaces6...>, ispaces...
  >
>
{
  using type = list<
    ispaces1, ispaces2, ispaces3, ispaces4, ispaces5,
    //typename take_while<before_last<last>>::template f<ispaces6...>,
    list<ispaces6...>,
    ispaces...
  >;
};

template<
  class ispaces1, class ispaces2, class ispaces3, class ispaces4, class ispaces5,
  class ispaces6, class ispace7, class... ispaces7, class... ispaces
>
struct part2_next_map<
  7,
  list<
    ispaces1, ispaces2, ispaces3, ispaces4, ispaces5, ispaces6,
    list<ispace7, ispaces7...>, ispaces...
  >
>
{
  using type = list<
    ispaces1, ispaces2, ispaces3, ispaces4, ispaces5, ispaces6,
    //typename take_while<before_last<last>>::template f<ispaces7...>,
    list<ispaces7...>,
    ispaces...
  >;
};

template<
  class ispaces1, class ispaces2, class ispaces3, class ispaces4, class ispaces5,
  class ispaces6, class ispaces7, class ispace8, class... ispaces8, class ispaces9
>
struct part2_next_map<
  8,
  list<
    ispaces1, ispaces2, ispaces3, ispaces4, ispaces5, ispaces6,
    ispaces7, list<ispace8, ispaces8...>, ispaces9
  >
>
{
  using type = list<
    ispaces1, ispaces2, ispaces3, ispaces4, ispaces5, ispaces6, ispaces7,
    //typename take_while<before_last<last>>::template f<ispaces8...>,
    list<ispaces8...>,
    ispaces9
  >;
};

template<
  class ispaces1, class ispaces2, class ispaces3, class ispaces4, class ispaces5,
  class ispaces6, class ispaces7, class ispaces8, class ispace9, class... ispaces9
>
struct part2_next_map<
  9,
  list<
    ispaces1, ispaces2, ispaces3, ispaces4, ispaces5, ispaces6,
    ispaces7, ispaces8, list<ispace9, ispaces9...>
  >
>
{
  using type = list<
    ispaces1, ispaces2, ispaces3, ispaces4, ispaces5, ispaces6,
    ispaces7, ispaces8,
    //typename take_while<before_last<last>>::template f<ispaces9...>
    list<ispaces9...>
  >;
};


template<int_t n, int_t i, int_t last, class m>
struct part2_updated_map
{
  using type = m;
};

template<int_t i, int_t last, class... ispaces1, class... ispaces>
struct part2_updated_map<
  1, i, last,
  list<list<ispaces1...>, ispaces...>
>
{
  using type = list<
    merge<>::f<
      list<number<i>>,
      //typename take_while<before_last<last>>::template f<ispaces1...>
      join<>::f<typename wrap_in_list_c<ispaces1::value < last>::template f<ispaces1>...>
      //list<ispaces1...>
    >,
    ispaces...
  >;
};

template<int_t i, int_t last, class ispaces1, class... ispaces2, class... ispaces>
struct part2_updated_map<
  2, i, last,
  list<ispaces1, list<ispaces2...>, ispaces...>
>
{
  using type = list<
    ispaces1,
    merge<>::f<
      list<number<i>>,
      //typename take_while<before_last<last>>::template f<ispaces2...>
      join<>::f<typename wrap_in_list_c<ispaces2::value < last>::template f<ispaces2>...>
      //list<ispaces2...>
    >,
    ispaces...
  >;
};

template<
  int_t i, int_t last,
  class ispaces1, class ispaces2, class... ispaces3, class... ispaces
>
struct part2_updated_map<
  3, i, last,
  list<ispaces1, ispaces2, list<ispaces3...>, ispaces...>
>
{
  using type = list<
    ispaces1, ispaces2,
    merge<>::f<
      list<number<i>>,
      //typename take_while<before_last<last>>::template f<ispaces3...>
      join<>::f<typename wrap_in_list_c<ispaces3::value < last>::template f<ispaces3>...>
      //list<ispaces3...>
    >,
    ispaces...
  >;
};

template<
  int_t i, int_t last,
  class ispaces1, class ispaces2, class ispaces3, class... ispaces4, class... ispaces
>
struct part2_updated_map<
  4, i, last,
  list<ispaces1, ispaces2, ispaces3, list<ispaces4...>, ispaces...>
>
{
  using type = list<
    ispaces1, ispaces2, ispaces3,
    merge<>::f<
      list<number<i>>,
      //typename take_while<before_last<last>>::template f<ispaces4...>
      join<>::f<typename wrap_in_list_c<ispaces4::value < last>::template f<ispaces4>...>
      //list<ispaces4...>
    >,
    ispaces...
  >;
};

template<
  int_t i, int_t last,
  class ispaces1, class ispaces2, class ispaces3, class ispaces4, class... ispaces5,
  class... ispaces
>
struct part2_updated_map<
  5, i, last,
  list<ispaces1, ispaces2, ispaces3, ispaces4, list<ispaces5...>, ispaces...>
>
{
  using type = list<
    ispaces1, ispaces2, ispaces3, ispaces4,
    merge<>::f<
      list<number<i>>,
      //typename take_while<before_last<last>>::template f<ispaces5...>
      join<>::f<typename wrap_in_list_c<ispaces5::value < last>::template f<ispaces5>...>
    >,
    ispaces...
  >;
};

template<
  int_t i, int_t last,
  class ispaces1, class ispaces2, class ispaces3, class ispaces4, class ispaces5,
  class... ispaces6, class... ispaces
>
struct part2_updated_map<
  6, i, last,
  list<
    ispaces1, ispaces2, ispaces3, ispaces4, ispaces5,
    list<ispaces6...>, ispaces...
  >
>
{
  using type = list<
    ispaces1, ispaces2, ispaces3, ispaces4, ispaces5,
    merge<>::f<
      list<number<i>>,
      //typename take_while<before_last<last>>::template f<ispaces6...>
      join<>::f<typename wrap_in_list_c<ispaces6::value < last>::template f<ispaces6>...>
    >,
    ispaces...
  >;
};

template<
  int_t i, int_t last,
  class ispaces1, class ispaces2, class ispaces3, class ispaces4, class ispaces5,
  class ispaces6, class... ispaces7, class... ispaces
>
struct part2_updated_map<
  7, i, last,
  list<
    ispaces1, ispaces2, ispaces3, ispaces4, ispaces5,
    ispaces6, list<ispaces7...>, ispaces...
  >
>
{
  using type = list<
    ispaces1, ispaces2, ispaces3, ispaces4, ispaces5, ispaces6,
    merge<>::f<
      list<number<i>>,
      //typename take_while<before_last<last>>::template f<ispaces7...>
      join<>::f<typename wrap_in_list_c<ispaces7::value < last>::template f<ispaces7>...>
    >,
    ispaces...
  >;
};

template<
  int_t i, int_t last,
  class ispaces1, class ispaces2, class ispaces3, class ispaces4, class ispaces5,
  class ispaces6, class ispaces7, class... ispaces8, class ispaces9
>
struct part2_updated_map<
  8, i, last,
  list<
    ispaces1, ispaces2, ispaces3, ispaces4, ispaces5,
    ispaces6, ispaces7, list<ispaces8...>, ispaces9
  >
>
{
  using type = list<
    ispaces1, ispaces2, ispaces3, ispaces4, ispaces5, ispaces6, ispaces7,
    merge<>::f<
      list<number<i>>,
      //typename take_while<before_last<last>>::template f<ispaces8...>
      join<>::f<typename wrap_in_list_c<ispaces8::value < last>::template f<ispaces8>...>
    >,
    ispaces9
  >;
};


template<class m>
inline constexpr int_t get_ispace = imax;

template<int_t ispace, class... ispaces>
inline constexpr int_t get_ispace<list<number<ispace>, ispaces...>> = ispace;


#if defined(TRACE) && TRACE
#  undef TRACE
#  define DEBUG(...) , __VA_ARGS__
#else
#  define DEBUG(...)
#endif

template<class, class>
struct part2_next_state;

template<
  int_t r, int_t n,
  class m1, class m2, class m3, class m4, class m5,
  class m6, class m7, class m8, class m9,
  int_t nfile, int_t ifile
  DEBUG(class... l)
>
struct part2_next_state<
  list<
    number<r>,
    number<n>,
    list<m1,m2,m3,m4,m5,m6,m7,m8,m9>
    DEBUG(list<l...>)
  >,
  list<number<nfile>, number<ifile>>
>
{

  static constexpr int_t ispace =
    min_v<
      min_v<
        min_v<
          min_v<
            get_ispace<m1> < ifile && nfile <= 1 ? (get_ispace<m1> << 4) + 1 : imax,
            get_ispace<m2> < ifile && nfile <= 2 ? (get_ispace<m2> << 4) + 2 : imax
          >,
          min_v<
            get_ispace<m3> < ifile && nfile <= 3 ? (get_ispace<m3> << 4) + 3 : imax,
            get_ispace<m4> < ifile && nfile <= 4 ? (get_ispace<m4> << 4) + 4 : imax
          >
        >,
        min_v<
          min_v<
            get_ispace<m5> < ifile && nfile <= 5 ? (get_ispace<m5> << 4) + 5 : imax,
            get_ispace<m6> < ifile && nfile <= 6 ? (get_ispace<m6> << 4) + 6 : imax
          >,
          min_v<
            get_ispace<m7> < ifile && nfile <= 7 ? (get_ispace<m7> << 4) + 7 : imax,
            get_ispace<m8> < ifile && nfile <= 8 ? (get_ispace<m8> << 4) + 8 : imax
          >
        >
      >,
      get_ispace<m9> < ifile ? (get_ispace<m9> << 4) + 9 : imax
    >;

  using next_map = typename
    part2_next_map<
      ispace < imax ? ispace & 0xf : 0,
      list<m1,m2,m3,m4,m5,m6,m7,m8,m9>
    >::type;

  using updated_map = typename
    part2_updated_map<
      ispace < imax ? (ispace & 0xf) - nfile : 0,
      ispace < imax ? (ispace >> 4) + nfile : 0,
      ispace < imax ? ifile : 0,
      next_map
    >::type;

  using type =
    list<
      number<
        ispace < imax
          ? r + (add_until<(ispace >> 4) + nfile> - add_until<(ispace >> 4)>) * n
          : r + (add_until<ifile + nfile> - add_until<ifile>) * n
      >,
      number<n-1>,
      updated_map
      DEBUG(list<l...,
        list<int, number<ifile>, number<nfile>, number<(ispace >> 4)>, number<(ispace & 0xf)>, updated_map>
      >)
    >;
};


template<class s, class x>
using part2_next_state_t = typename part2_next_state<s, x>::type;


template<class b, class i>
struct part2_impl;

template<int_t... b, int_t... i>
struct part2_impl<list<number<b>...>, list<number<i>...>>
{
  template<class... n>
  using f =
    emp::fold<
    //list<
      // files
      typename join<reverse<>>::f<
        typename wrap_in_list_c<!(b & 1)>
        ::template f<list<n, number<(b & 1) ? 0 : i>>>...
      >,

      list<
        number<0>,
        number<sizeof...(n) / 2>,
        // spaces without 0
        typename join<make_space_map>::f<
          typename wrap_in_list_c<(b & 1) && n::value>
          ::template f<list<n, number<n::value ? i : 0>>>
          ...
        >::type
        DEBUG(list<>)
      >,

      lift<part2_next_state_t>
    >;
};

template<class... n>
struct part2
{
  using type = typename
    part2_impl<
      emp::make_int_sequence_c<sizeof...(n)>,
      scan<
        add<>,
        rotate_c<-1, pop_front<push_front<false_>>>
      >::f<n...>
    >
    ::template f<n...>;
};

using algo = lift_t<part2, unpack<front<>>>; // 6373055193464 | 1 min | 12 GiB

#endif

using Result = unpack<algo>::f<input>;
Result result = 1;
