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
} < input > day6.hpp
*/

#if defined(TEST) && TEST
#include <jln/mp/number/numbers.hpp>
#include <jln/mp/algorithm/make_int_sequence.hpp>
using namespace jln::mp;

constexpr char s[] =
  "....#....." // 0
  ".........#" // 1
  ".........." // 2
  "..#......." // 3
  ".......#.." // 4
  ".........." // 5
  ".#.O^....." // 6
  "......OO#." // 7
  "#O.O......" // 8
  "......#O.." // 9
// 0123456789

// 63 76 83 81 77 97
;

using namespace jln::mp;

struct to_input
{
  template<int_t... i>
  struct f
  {
    template<int n, char const (&s)[101]>
    using line = list<number<s[n+i]>...>;

    template<char const(&s)[101]>
    using from = list<line<i*10, s>...>;
  };
};

using input = emp::make_int_sequence_v_c<10, to_input>::from<s>;
#else
#include "day6.hpp"
#endif

#include <jln/mp/algorithm/transform.hpp>
#include <jln/mp/algorithm/zip.hpp>
#include <jln/mp/algorithm/unique.hpp>
#include <jln/mp/algorithm/index.hpp>
#include <jln/mp/algorithm/reverse.hpp>
#include <jln/mp/algorithm/fold.hpp>
#include <jln/mp/algorithm/repeat.hpp>
#include <jln/mp/algorithm/arrange.hpp>
#include <jln/mp/algorithm/remove.hpp>
#include <jln/mp/list/take_front.hpp>
#include <jln/mp/list/push_front.hpp>
#include <jln/mp/list/push_back.hpp>
#include <jln/mp/list/lookup.hpp>
#include <jln/mp/list/join.hpp>
#include <jln/mp/list/size.hpp>
#include <jln/mp/list/at.hpp>
#include <jln/mp/number/operators.hpp>
#include <jln/mp/utility/is_base_of.hpp>
#include <jln/mp/utility/flat_inheritance.hpp>

#ifndef ENABLE_TRACE
# define ENABLE_TRACE 0
#endif

#if ENABLE_TRACE
#  define TRACE(...) , __VA_ARGS__
#else
#  define TRACE(...)
#endif

struct make_arrange
{
  template<int_t... i>
  using f = arrange_c_with<join<>, i * 2 ...>;
};

template<class R TRACE(class... step)>
struct traverse_result;

template<class... Ls TRACE(class... step)>
struct traverse_result<list<Ls...> TRACE(step...)>
{
  using next = traverse_result;

  using paths = list<Ls...>;

  //using type = join<unique<size<>>>::f<L...>; // too long when the list is too large with few duplicates
  using arrange = emp::make_int_sequence_v_c<sizeof...(Ls) / 2 + 1, make_arrange>;
  using indices = transform<unpack<at1<>>>::f<Ls...>;
  using l1 = emp::unpack_append<indices, arrange, list<>>;
  using l2 = emp::unpack<indices, arrange, list<>>;
  using set1 = unpack<lift<flat_inheritance>>::f<l1>;
  using duplicate = typename unpack<transform<is_base_of<set1>, add0<>>>::template f<l2>;
  using type = number<emp::size_v<l1> + emp::size_v<l2> - duplicate::value>;
};


template<int m, int start>
struct visitation
{
  template<int_t... i>
  using f = list<number<start + i * m>...>;
};


template<int orientation>
inline constexpr int x_multiplier
  = orientation == 1 ? 1 : orientation == 3 ? -1 : 0;

template<int orientation>
inline constexpr int y_multiplier
  = orientation == 0 ? -1 : orientation == 2 ? 1 : 0;

template<int orientation, int x, int y, int wh>
inline constexpr int compute_shift
  = orientation == 0    ? wh-y
  : orientation == 1    ? x+1
  : orientation == 2    ? y+1
  /*: orientation == 3*/: wh-x;

using obstacle = number<'#'>;

template<int shift, class L>
using step_until_obstacle = typename
  unpack<
    drop_front_c<
      shift,
      index_of<obstacle, identity, listify>
    >
  >
  ::template f<L>;

template<int x, int y, int orientation, class Grid, class R TRACE(class... step)>
struct traverse
{
  static constexpr int mx = x_multiplier<orientation>;
  static constexpr int my = y_multiplier<orientation>;

  template<int_t n>
  using next_visitations = join<>::f<
    R,
    list<list<
      number<orientation>,
      emp::make_int_sequence_v_c<n, visitation<mx + my * Grid::wh, x + y * Grid::wh>>
    >>
  >;

  template<class N>
  struct next_impl
  {
    using type = traverse<
      x + N::value * mx, y + N::value * my, (orientation+1) % 4, Grid,
      next_visitations<N::value>
      TRACE(step..., list<N, number<x + N::value * mx>, number<y + N::value * my>>)
    >;
  };

  template<class... xs>
  struct next_impl<list<xs...>>
  {
    using type = traverse_result<
      next_visitations<sizeof...(xs)+1>
      TRACE(step..., list<
        number<sizeof...(xs)+1>,
        number<x + (sizeof...(xs)+1) * mx>,
        number<y + (sizeof...(xs)+1) * my>
      >)
    >;
  };

  using next = typename
    next_impl<
      step_until_obstacle<
        compute_shift<orientation, x, y, Grid::wh>,
        typename Grid::template get_list<orientation>::template f<my ? x : y>
      >
    >
    ::type;
};


template<int WH, class RColumns, class Lines, class Columns, class RLines>
struct grid
{
  static constexpr int wh = WH;

  template<int orientation>
  using get_list = typename at_c<orientation>::template f<RColumns, Lines, Columns, RLines>;

};


template<class st, class>
using next_step = typename st::next;

template<class... Lines>
struct part1
{
  using lines = build_indexed_v<Lines...>;
  using columns = zip<lift<build_indexed_v>>::f<Lines...>;
  using rev_lines = build_indexed_v<emp::reverse<Lines>...>;
  using rev_columns = zip_with<reverse<>, lift<build_indexed_v>>::f<Lines...>;

  static constexpr int_t wh = emp::size_v<at0<>::f<Lines...>>;
  static constexpr int_t guard_index = join<index_of<number<'^'>>>::f<Lines...>::value;
  static constexpr int_t x = guard_index % wh;
  static constexpr int_t y = guard_index / wh;

  using Grid = grid<wh, rev_columns, lines, columns, rev_lines>;

  using state = traverse<x, y, 0, Grid, list<> TRACE(list<number<0>, number<x>, number<y>>)>;

  using Result = typename
    repeat_c<
      wh * sizeof...(Lines) / 4,
      push_front<
        state,
        fold<lift<next_step>>
      >
    >
    ::template f<void>;

  using type = Result::type;
};

#if !defined(PART) || PART == 1
using algo = lift_t<part1>; // 5086
#else

using obj = number<'#'>;

inline constexpr int Empty = 0;
inline constexpr int Obj = 1;
inline constexpr int Invalid = 2;

template<class G, int wh, int x, int y, bool is_valid = 0 <= x && x < wh && 0 <= y && y < wh>
inline constexpr int position_state = Invalid;

template<class G, int wh, int x, int y>
inline constexpr int position_state<G, wh, x, y, true>
  = JLN_MP_IS_SAME(obj, typename G::template f<y>::template f<x>);


template<class G, int wh, int x, int y, int orientation,
  int = position_state<G,wh,x,y>>
inline constexpr int search_obj_pos/*<Obj>*/ = x + y * wh;

template<class G, int wh, int x, int y, int orientation>
inline constexpr int search_obj_pos<G, wh, x, y, orientation, Invalid> = -1;

template<class G, int wh,  int x, int y, int orientation>
inline constexpr int search_obj_pos<G, wh, x, y, orientation, Empty>
  = search_obj_pos<G, wh, x + x_multiplier<orientation>, y + y_multiplier<orientation>, orientation>;


struct is_traversable_marker
{
  using next = is_traversable_marker;
};

struct is_loop_marker
{
  using next = is_loop_marker;
};


template<bool enable, int p, int p_obj, int p_found, int m>
inline constexpr int next_coord_obj
  = (enable && m && p * m <= p_obj * m && p_obj * m <= p_found * m)
  ? p_obj - m
  : p_found - m;


template<class G, int wh, int x, int y, int orientation, int x_obj, int y_obj,
  int pos = search_obj_pos<G,wh,x,y,orientation>
>
struct is_traversable_state
{
  using next =
    is_traversable_state<
      G, wh,
      next_coord_obj<y == y_obj, x, x_obj, pos % wh, x_multiplier<orientation>>,
      next_coord_obj<x == x_obj, y, y_obj, pos / wh, y_multiplier<orientation>>,
      (orientation + 1) % 4,
      x_obj,
      y_obj
    >;
};

template<class G, int wh, int y, int orientation, int x_obj, int y_obj>
struct is_traversable_state<G, wh, x_obj, y, orientation, x_obj, y_obj, -1>
: conditional_c<
    y_multiplier<orientation>
    &&
    y * y_multiplier<orientation> <= y_obj * y_multiplier<orientation>
  >
  ::template f<
    is_traversable_state<
      G, wh,
      x_obj - x_multiplier<orientation>,
      y_obj - y_multiplier<orientation>,
      (orientation + 1) % 4,
      x_obj,
      y_obj
    >,
    is_traversable_marker
  >
{};

template<class G, int wh, int x, int orientation, int x_obj, int y_obj>
struct is_traversable_state<G, wh, x, y_obj, orientation, x_obj, y_obj, -1>
: conditional_c<
  x_multiplier<orientation>
  &&
  x * x_multiplier<orientation> <= x_obj * x_multiplier<orientation>>
  ::template f<
    is_traversable_state<
      G, wh,
      x_obj - x_multiplier<orientation>,
      y_obj - y_multiplier<orientation>,
      (orientation + 1) % 4,
      x_obj,
      y_obj
    >,
    is_traversable_marker
  >
{};

template<class G, int wh, int x, int y, int orientation, int x_obj, int y_obj>
struct is_traversable_state<G, wh, x, y, orientation, x_obj, y_obj, -1>
  : is_traversable_marker
{};


using fold_next_step = fold<lift<next_step>>;


template<class st, class>
using next_step2 = typename st
  ::next::next::next::next::next::next::next::next
  ::next::next::next::next::next::next::next::next
  ::next::next::next::next::next::next::next::next
  ::next::next::next::next::next::next::next::next
;
using fold_next_step2 = fold<lift<next_step2>>;

template<class St>
struct is_traversable_impl
{
  template<class, int... xs>
  using impl = fold_next_step2::f<St, decltype(xs)...>;
};

template<int wh,
  int n = (wh * wh + 32 * 4)
        / 4  // because an entire line is covered in one go ("random" value)
        / 32 // because next_step2
>
struct is_traversable
{
  template<class St>
  using f =
    JLN_MP_D_MAKE_INTEGER_SEQUENCE_T(int, n, is_traversable_impl<St>::template impl)
  ;
};


template<class R>
struct count_loop_result
{
  using next = count_loop_result;
  using type = R;
};


template<class G, int wh, int x, int y, int orientation, class R = list<>, int counter = 0,
  int = position_state<G,wh,x,y>
>
struct count_loop_state;

#if ( !defined(TEST) || !TEST ) && 0
inline constexpr int stop_iteration = 40;

template<class G, int wh, int x, int y, int orientation, class R>
struct count_loop_state<G, wh, x, y, orientation, R, stop_iteration, Empty>
{
  using next = count_loop_result<R>;
};

template<class G, int wh, int x, int y, int orientation, class R>
struct count_loop_state<G, wh, x, y, orientation, R, stop_iteration, Obj>
{
  using next = count_loop_result<R>;
};
#endif

template<class G, int wh, int x, int y, int orientation, class R, int counter>
struct count_loop_state<G, wh, x, y, orientation, R, counter, Invalid>
{
  //using next = count_loop_result<number<counter>>;
  using next = count_loop_result<R>;
};

template<class G, int wh, int x, int y, int orientation, class R, int counter>
struct count_loop_state<G, wh, x, y, orientation, R, counter, Obj>
{
  using next =
    count_loop_state<
      G, wh,
      x - x_multiplier<orientation>,
      y - y_multiplier<orientation>,
      (orientation + 1) % 4,
      R, counter
    >;
};

template<class... xs> struct Set : xs... {};

template<bool known, int pos_st>
struct traverse_if_unknown_and_add;

template<int counter, class G, int wh, int x, int y, int orientation, class R>
struct count_loop_state<G, wh, x, y, orientation, R, counter, Empty>
{
  static constexpr int x_next = x + x_multiplier<orientation>;
  static constexpr int y_next = y + y_multiplier<orientation>;

  using next =
    count_loop_state<
      G, wh,
      x_next,
      y_next,
      orientation,
      typename traverse_if_unknown_and_add<
        JLN_MP_IS_BASE_OF(number<x_next + y_next * wh>, R),
        position_state<G, wh, x_next, y_next>
      >
      ::template f<
        R,
        number<x_next + y_next * wh>,
        is_traversable_state<
          G, wh,
          G::x_start,
          G::y_start,
          0,
          x_next,
          y_next
        >,
        wh
      >,
      counter + 1
    >;
};


template<bool> struct add_elem_if_not { template<class S, class x> using f = S; };
template<> struct add_elem_if_not<false> { template<class S, class x> using f = Set<S, x>; };

template<>
struct traverse_if_unknown_and_add</*know=*/false, /*pos_st=*/Empty>
{
  template<class S, class x, class St, int wh>
  using f = typename
    add_elem_if_not<
      emp::same_xs_v<
        is_traversable_marker,
        typename is_traversable<wh>::template f<St>
      >
    >
    ::template f<S, x>;
};

template<bool, int>
struct traverse_if_unknown_and_add
{
  template<class S, class x, class St, int wh>
  using f = S;
};

template<class S>
struct Unset
{
  using type = S;
};

template<class S, class x1>
struct Unset<Set<S, x1>>
{
  using type = join<>::f<typename Unset<S>::type, list<x1>>;
};

template<class S, class x1, class x2, class x3, class x4, class x5, class x6, class x7, class x8>
struct Unset<Set<Set<Set<Set<Set<Set<Set<Set<S, x8>, x7>, x6>, x5>, x4>, x3>, x2>, x1>>
{
  using type = join<>::f<typename Unset<S>::type, list<x1, x2, x3, x4, x5, x6, x7, x8>>;
};

template<class... Lines>
struct part2
{
  static constexpr int guard_index = join<index_of<number<'^'>>>::f<Lines...>::value;

  struct Grid
    : build_indexed_v<unpack<lift<build_indexed_v>>::f<Lines>...>
  {
    static constexpr int wh = sizeof...(Lines);
    static constexpr int x_start = guard_index % wh;
    static constexpr int y_start = guard_index / wh;
  };

  using type = emp::size<
    typename Unset<
      typename repeat_c<
        (Grid::wh * Grid::wh + 31) / 32,
        push_front<
          count_loop_state<Grid, Grid::wh, Grid::x_start, Grid::y_start, 0>,
          fold_next_step2
        >
      >
      ::template f<void>
      ::type
    >
    ::type
  >
  ;
};


using algo = lift_t<part2>; // 1770 | /!\ 6.1Gio | 1min 7s
#endif

using Result = unpack<algo>::f<input>;
Result result = 1;
