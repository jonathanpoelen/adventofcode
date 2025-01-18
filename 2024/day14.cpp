/*
{
  echo '#include <jln/mp/number/numbers.hpp>'
  echo 'using namespace jln::mp;'
  echo 'using input = list<'
  sed -E '
    s/p=(-?[0-9]+),(-?[0-9]+) v=(-?[0-9]+),(-?[0-9]+)/, emp::numbers<\1,\2,\3,\4>/g
    1s/,/ /
  '
  echo '>;'
} < input > day14.hpp
*/

#if defined(TEST) && TEST
#include <jln/mp/number/numbers.hpp>
using namespace jln::mp;

using input = list<
  emp::numbers<0,4, 3,-3>,
  emp::numbers<6,3, -1,-3>,
  emp::numbers<10,3, -1,2>,
  emp::numbers<2,0, 2,-1>,
  emp::numbers<0,0, 1,3>,
  emp::numbers<3,0, -2,-2>,
  emp::numbers<7,6, -1,-3>,
  emp::numbers<3,0, -1,-2>,
  emp::numbers<9,3, 2,3>,
  emp::numbers<7,3, -1,2>,
  emp::numbers<2,4, 2,-3>,
  emp::numbers<9,5, -3,-3>
>;

constexpr int_t width = 11;
constexpr int_t height = 7;
#else
#include "day14.hpp"
constexpr int_t width = 101;
constexpr int_t height = 103;
#endif

#include <jln/mp/algorithm/iota.hpp>
#include <jln/mp/algorithm/fold.hpp>
#include <jln/mp/algorithm/transform.hpp>
#include <jln/mp/algorithm/remove.hpp>
#include <jln/mp/algorithm/repeat.hpp>
#include <jln/mp/algorithm/zip.hpp>
#include <jln/mp/algorithm/drop_while.hpp>
#include <jln/mp/algorithm/same.hpp>
#include <jln/mp/utility/conditional.hpp>
#include <jln/mp/utility/is_base_of.hpp>
#include <jln/mp/list/at.hpp>
#include <jln/mp/number/operators.hpp>

constexpr int_t midx = width / 2;
constexpr int_t midy = height / 2;

#if !defined(PART) || PART == 1

template<int_t xx, int_t yy,
  int_t x = xx < 0 ? xx + width : xx,
  int_t y = yy < 0 ? yy + height : yy>
using quadrant = emp::numbers<
  (x < midx && y < midy),
  (x > midx && y < midy),
  (x < midx && y > midy),
  (x > midx && y > midy)
>;

struct part1
{
  template<class px, class py, class vx, class vy>
  using f = quadrant<
    (px::value + vx::value * 100) % width,
    (py::value + vy::value * 100) % height
  >;
};

using algo = transform<
  unpack<part1>,
  jln::mp::remove<
    emp::numbers<0,0,0,0>,
    zip_with<add<>, mul<>>
  >
>; // _231221760

#else

template<int_t px, int_t py, int_t vx, int_t vy>
struct robot
{
  template<int_t i>
  using f = int_seq_c<
    (px + vx * i) % width,
    (py + vy * i) % height
  >;
};


struct make_robot
{
  template<class px, class py, class vx, class vy>
  using f = robot<
    px::value,
    py::value,
    vx::value < 0 ? vx::value + width : vx::value,
    vy::value < 0 ? vy::value + height : vy::value
  >;
};


template<class s, class x>
struct Set : s, x
{};


struct has_overlaps_stop
{
  template<class>
  using f = has_overlaps_stop;

  using type = has_overlaps_stop;
};


template<int_t i, class S>
struct has_overlaps_state
{
  template<class R, class n = typename R::template f<i>, bool = JLN_MP_IS_BASE_OF(n, S)>
  struct f
  {
    using type = has_overlaps_state<i, Set<S, n>>;
  };

  template<class R, class n>
  struct f<R,n,true>
    : has_overlaps_stop
  {};
};


struct has_overlaps_state_t
{
  template<class S, class R>
  using f = typename S::template f<R>::type;
};


template<class... R>
struct has_overlaps
{
  template<class i>
  using f = number<
    JLN_MP_IS_SAME(
      typename fold<
        // this always gives has_overlaps_state_t,
        // but without it, clang takes a huge amount of time...
        JLN_MP_CONDITIONAL_C_T(JLN_MP_IS_SAME(i,i), has_overlaps_state_t, void)
      >
      ::template f<
        has_overlaps_state<i::value, list<>>,
        R...
      >,
      has_overlaps_stop
    )
  >;
};


struct part2
{
  template<class... R>
  using f =
    emp::iota_c<
      6500, 500, 1, // 500 loop turns => 10s and 2.4GiB
      drop_while<
        has_overlaps<emp::unpack<R, make_robot>...>,
        at0<>,
        always<list<>>
      >
    >;
};

using algo = part2; // _6771

#endif

using Result = unpack<algo>::f<input>;
Result result = 1;
