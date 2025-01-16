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
} < input > day12.hpp
*/

#if defined(TEST) && TEST
#include <jln/mp/algorithm/make_int_sequence.hpp>
using namespace jln::mp;

constexpr char s[] =
  "RRRRIICCFF"
  "RRRRIICCCF"
  "VVRRRCCFFF"
  "VVRCCCJFFF"
  "VVVVCJJCFE"
  "VVIVCCJJEE"
  "VVIIICJJEE"
  "MIIIIIJJEE"
  "MIIISIJEEE"
  "MMMISSJEEE"
;

constexpr int wh = 10;

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
#include "day12.hpp"
#endif

#include <jln/mp/algorithm/unique.hpp>
#include <jln/mp/algorithm/repeat.hpp>
#include <jln/mp/algorithm/transform.hpp>
#include <jln/mp/algorithm/make_int_sequence.hpp>
#include <jln/mp/algorithm/same.hpp>
#include <jln/mp/list/at.hpp>
#include <jln/mp/list/join.hpp>
#include <jln/mp/list/push_front.hpp>
#include <jln/mp/list/wrap_in_list.hpp>
#include <jln/mp/utility/is_base_of.hpp>


template<class G, int wh, int x, int y, bool is_valid = 0 <= x && x < wh && 0 <= y && y < wh>
inline constexpr int map_get = -1;

template<class G, int wh, int x, int y>
inline constexpr int map_get<G, wh, x, y, true>
  = G::template f<y>::template f<x>::value;


template<class S, class x>
struct Set : x, S
{};


template<int_t PerimeterOrSidesOrResult, int_t AreaOrZero, class S>
struct region
{
  using set = S;
  static constexpr int_t perimeter_or_sides = PerimeterOrSidesOrResult;
  static constexpr int_t area = AreaOrZero;
};

template<class a, class b>
using merge_region = region<
  a::perimeter_or_sides + b::perimeter_or_sides * b::area,
  0,
  Set<typename a::set, typename b::set>
>;


template<int,int> struct coord {};


template<class S, class F, int n, class G, int wh, int x, int y,
  int r = map_get<G, wh, x, y>,
  bool = JLN_MP_IS_BASE_OF(coord<x, y>, typename S::set)
>
struct find_region
{
  using type = S;
};

template<
  int_t perimeter_or_sides, int_t area, class S,
  class F, int n, class G, int wh, int x, int y
>
struct find_region<region<perimeter_or_sides, area, S>, F, n, G, wh, x, y, n, false>
: find_region<
    typename find_region<
      typename find_region<
        typename find_region<
          region<
            perimeter_or_sides + F::template v<n, G, wh, x, y>,
            area + 1,
            Set<S, coord<x,y>>
          >,
          F, n, G, wh, x+1, y
        >::type,
        F, n, G, wh, x-1, y
      >::type,
      F, n, G, wh, x, y+1
    >::type,
    F, n, G, wh, x, y-1
  >
{};


template<class F, class S, class G, int wh, int x, int y,
  int r = map_get<G, wh, x, y>,
  bool = JLN_MP_IS_BASE_OF(coord<x, y>, typename S::set)
>
struct find_regions_impl
{
  using type = S;
};

template<class F, class S, class G, int wh, int x, int y, int n>
struct find_regions_impl<F, S, G, wh, x, y, n, false>
{
  using type = merge_region<
    S,
    typename find_region<
      region<0, 0, coord<-x,-y>>,
      F, n, G, wh, x, y
    >::type
  >;
};

template<class, class>
struct find_regions;

template<class S, class G, int_t wh, class F, int_t pos>
struct find_regions<list<S, G, number<wh>, F>, number<pos>>
{
  using type = list<
    typename find_regions_impl<F, S, G, wh, pos % wh, pos / wh>::type,
    G, number<wh>, F
  >;
};


template<class, class>
struct extract_indices_impl;

template<class... xs, class... i>
struct extract_indices_impl<list<xs...>, list<i...>>
{
  template<class x>
  using f = join<>::f<
    typename wrap_in_list_c<JLN_MP_IS_SAME(x,xs)>::template f<i>
    ...
  >;
};

struct extract_indices
{
  template<class... xs>
  using f = typename
    unique<
      transform<
        extract_indices_impl<
          list<xs...>,
          emp::make_int_sequence_c<sizeof...(xs)>
        >
      >
    >
    ::template f<xs...>
    ;
};


struct add_result
{
  template<class... xs>
  using f = number<(xs::perimeter_or_sides + ...)>;
};

template<class F, class... Lines>
struct solve
{
  static constexpr int wh = sizeof...(Lines);

  using indices_by_letter = join<extract_indices>::f<Lines...>;

  using grid = build_indexed_v<unpack<lift<build_indexed_v>>::f<Lines>...>;

  using region_finder =
    push_front<
      list<region<0,0,list<>>, grid, number<wh>, F>,
      fold<
        lift_t<find_regions>,
        unpack<at0<>>
      >
    >;

  using type = typename
    unpack<
      transform<
        unpack<region_finder>,
        add_result
      >
    >
    ::f<indices_by_letter>;
};


#if !defined(PART) || PART == 1

struct count_neighbors
{
  template<int n, class G, int wh, int x, int y>
  static constexpr int_t v =
    (map_get<G, wh, x+1, y> != n)
    +
    (map_get<G, wh, x-1, y> != n)
    +
    (map_get<G, wh, x, y+1> != n)
    +
    (map_get<G, wh, x, y-1> != n)
    ;
};

using algo = count_neighbors; // _1485656

#else

template<int n, int side1, int side2, int corner>
inline constexpr int_t is_corner
  = (n != side1 && n != side2) || (n == side1 && n == side2 && n != corner);

struct count_corners
{
  template<int n, class G, int wh, int x, int y,
    int up = map_get<G, wh, x, y-1>,
    int right = map_get<G, wh, x+1, y>,
    int down = map_get<G, wh, x, y+1>,
    int left = map_get<G, wh, x-1, y>
  >
  static constexpr int_t v
    = is_corner<n, up, right, map_get<G, wh, x+1, y-1>>
    + is_corner<n, right, down, map_get<G, wh, x+1, y+1>>
    + is_corner<n, down, left, map_get<G, wh, x-1, y+1>>
    + is_corner<n, left, up, map_get<G, wh, x-1, y-1>>
    ;
};

using algo = count_corners; // _899196

#endif

using Result = unpack<push_front<algo, lift_t<solve>>>::f<input>;
Result result = 1;

