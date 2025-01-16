/*
{
  echo '#include <jln/mp/list/list.hpp>'
  echo '#include <jln/mp/number/numbers.hpp>'
  echo 'using namespace jln::mp;'
  echo 'using input = list<'
  echo '  emp::numbers<'
  sed -E '
    s/^B[^0-9]+([0-9]+)[^0-9]+([0-9]+)/    \1, \2, /g
    s/^P[^0-9]+([0-9]+)[^0-9]+([0-9]+)/    \1, \2 /g
    s/^$/  >,\n  emp::numbers</
  '
  echo '  >'
  echo '>;'
} < input > day13.hpp
*/

#if defined(TEST) && TEST
#include <jln/mp/number/numbers.hpp>
using namespace jln::mp;

using input = list<
  emp::numbers<
    94, 34,
    22, 67,
    8400, 5400
  >,
  emp::numbers<
    26, 66,
    67, 21,
    12748, 12176
  >,
  emp::numbers<
    17, 86,
    84, 37,
    7870, 6450
  >,
  emp::numbers<
    69, 23,
    27, 71,
    18641, 10279
  >
>;
#else
#include "day13.hpp"
#endif

#include <jln/mp/algorithm/transform.hpp>
#include <jln/mp/number/operators.hpp>


template<int_t aX, int_t aY, int_t bX, int_t bY, int_t prizeX, int_t prizeY, int_t offset,
  int_t a = ((prizeX + offset) * bY - (prizeY + offset) * bX) / (aX * bY - aY * bX),
  int_t b = ((prizeY + offset) - aY * a) / bY
>
inline constexpr int_t solve_machine_v
  = (aX * a + bX * b == prizeX + offset && aY * a + bY * b == prizeY + offset)
    ? a * 3 + b
    : 0;

template<int_t offset>
struct solve_machine
{
  template<class... n>
  using f = number<solve_machine_v<n::value..., offset>>;
};

#if !defined(PART) || PART == 1

inline constexpr int_t offset = 0; // _39996

#else

inline constexpr int_t offset = 10000000000000; // _73267584326867

#endif

using algo = transform<unpack<solve_machine<offset>>, add<>>;

using Result = unpack<algo>::f<input>;
Result result = 1;
