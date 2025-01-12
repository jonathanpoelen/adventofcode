/*
{
  echo '#include <jln/mp/list/list.hpp>'
  echo '#include <jln/mp/number/number.hpp>'
  echo 'using namespace jln::mp;'
  echo 'using input = list<'
  sed -E '
    s/:? />, number</g
    s/^/, list<number</
    s/$/>>/
    1s/,/ /
  '
  echo '>;'
} < input > day7.hpp
*/

#if defined(TEST) && TEST
#include <jln/mp/number/numbers.hpp>
using namespace jln::mp;
using input = list<
  emp::numbers<190, 10, 19>,          // 10 * 19
  emp::numbers<3267, 81, 40, 27>,     // 81 + 40 * 27  |  81 * 40 + 27
  emp::numbers<83, 17, 5>,
  emp::numbers<156, 15, 6>,
  emp::numbers<7290, 6, 8, 6, 15>,
  emp::numbers<161011, 16, 10, 13>,
  emp::numbers<192, 17, 8, 14>,
  emp::numbers<21037, 9, 7, 18, 13>,
  emp::numbers<292, 11, 6, 16, 20>    // 11 + 6 * 16 + 20
>;
#else
#include "day7.hpp"
#endif

#include <jln/mp/algorithm/transform.hpp>
#include <jln/mp/algorithm/reverse.hpp>
#include <jln/mp/algorithm/rotate.hpp>
#include <jln/mp/list/push_back.hpp>
#include <jln/mp/functional/if.hpp>
#include <jln/mp/number/operators.hpp>


template<int_t v, class U>
static constexpr int_t select_value = v;

template<class U>
static constexpr int_t select_value<0, U> = U::value;


template<int_t n>
inline constexpr int_t shift_v
  = n < 10 ? 10
  : n < 100 ? 100
  : n < 1000 ? 1000
  : 10000;


template<int_t part, int_t step, int_t n, int_t... ns>
struct check_reversed
{
  static constexpr int_t value =
    select_value<
      select_value<
        check_reversed<part, step / n * n == step ? step / n : -1, ns...>::value,
        check_reversed<part, n <= step ? step - n : -1, ns...>
      >,
      check_reversed<
        part,
        part == 2 && step % shift_v<n> == n ? step / shift_v<n> : -1,
        ns...
      >
    >;
};

template<int_t part, int_t n, int_t... ns>
struct check_reversed<part, -1, n, ns...>
  : false_
{};

template<int_t part, int_t n>
struct check_reversed<part, -1, n>
  : false_
{};

template<int_t part, int_t step, int_t n>
struct check_reversed<part, step, n>
  : number<step == n>
{};


template<int_t part>
using resolve =
  transform<
    unpack<
      if_<
        rotate_c<
          1,
          push_back<
            number<part>,
            reverse<lift_v<check_reversed>>
          >
        >,
        front<>
      >
    >,
    add<>
  >;


#if !defined(PART) || PART == 1

using algo = resolve<1>; // 6392012777720

#else

using algo = resolve<2>; // 61561126043536

#endif

using Result = unpack<algo>::f<input>;
Result result = 1;
