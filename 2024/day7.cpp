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
#include <jln/mp/list/take_front.hpp>
#include <jln/mp/list/drop_front.hpp>
#include <jln/mp/number/operators.hpp>


template<int_t v, class U>
static constexpr int_t select_value = v;

template<class U>
static constexpr int_t select_value<0, U> = U::value;


template<uint_t a, uint_t b>
inline constexpr uint_t umax_c_v = a < b ? b : a;

template<uint_t a, uint_t b>
inline constexpr int_t umin_c_v = a < b ? a : b;


template<uint_t r, int_t step, int_t... ns>
inline constexpr uint_t remaining_max_value = step;

template<uint_t r, int_t step, int_t n, int_t... ns>
inline constexpr uint_t remaining_max_value<r, step, n, ns...> =
  remaining_max_value<
    r,
    umin_c_v<
      step * n < step + n
        ? step + n
        : step * n,
      r
    >,
    ns...
  >;


template<int_t r, int_t step, int_t... ns>
struct count_result1;

template<int_t r, int_t step, int_t n, int_t... ns>
struct count_result1<r, step, n, ns...>
{
  static constexpr int_t value = select_value<
    count_result1<
      step * n <= r && r <= remaining_max_value<r, step * n, ns...> ? r : 0,
      step * n, ns...
    >::value,
    count_result1<
      step + n <= r && r <= remaining_max_value<r, step + n, ns...> ? r : 0,
      step + n, ns...
    >
  >;
};

template<int_t step, int_t n, int_t... ns>
struct count_result1<0, step, n, ns...>
  : false_
{};

// for optimization
template<int_t r, int_t step, int_t n>
struct count_result1<r, step, n>
  : number<r == step + n || r == step * n ? r : 0>
{};

template<int_t step, int_t n>
struct count_result1<0, step, n>
  : false_
{};

template<int_t r, int_t step>
struct count_result1<r, step>
  : number<r == step ? r : 0>
{};


#if !defined(PART) || PART == 1

using algo = transform<unpack<lift_v<count_result1>>, add<>>; // 6392012777720 | 6s | 662Mio

#else

template<int_t n>
inline constexpr int_t shift_v
  = n < 10 ? 10
  : n < 100 ? 100
  : n < 1000 ? 1000
  : 10000;


template<uint_t r, int_t step, int_t... ns>
inline constexpr uint_t remaining_max_value2 = step;

template<uint_t r, int_t step, int_t n, int_t... ns>
inline constexpr uint_t remaining_max_value2<r, step, n, ns...> =
  remaining_max_value2<
    r,
    umin_c_v<
      umax_c_v<
        step * n < step + n
          ? step + n
          : step * n,
        step * shift_v<n> + n
      >,
      r
    >,
    ns...
  >;


template<int_t r, int_t step, int_t... ns>
struct count_result2_impl;

template<int_t r, int_t step, int_t n, int_t... ns>
struct count_result2_impl<r, step, n, ns...>
{
  static constexpr bool cont = r <= remaining_max_value2<r, step, n, ns...>;

  static constexpr int_t value = select_value<
    select_value<
      count_result2_impl<
        step * shift_v<n> + n <= r && cont ? r : 0,
        step * shift_v<n> + n,
        ns...
      >::value,
      count_result2_impl<
        step * n <= r && cont ? r : 0,
        step * n,
        ns...
      >
    >,
    count_result2_impl<
      step + n <= r && cont ? r : 0,
      step + n,
      ns...
    >
  >;
};

template<int_t step, int_t n, int_t... ns>
struct count_result2_impl<0, step, n, ns...>
  : false_
{};

template<int_t r, int_t step>
struct count_result2_impl<r, step>
  : number<r == step ? r : 0>
{};

// for optization
template<int_t r, int_t step, int_t n>
struct count_result2_impl<r, step, n>
{
  static constexpr int_t value =
    r == step * shift_v<n> + n
    ||
    r == step * n
    ||
    r == step + n

    ? r
    : 0
    ;
};

// fix ambiguity (for optization)
template<int_t step, int_t n>
struct count_result2_impl<0, step, n>
  : false_
{};

// for optization
template<int_t r, int_t step, int_t n, int_t nn>
struct count_result2_impl<r, step, n, nn>
{
  static constexpr int_t value =
    r == (step * shift_v<n> + n) * shift_v<nn> + nn
    ||
    r == (step * shift_v<n> + n) * nn
    ||
    r == (step * shift_v<n> + n) + nn

    ||

    r == (step * n) * shift_v<nn> + nn
    ||
    r == (step * n) * nn
    ||
    r == (step * n) + nn

    ||

    r == (step + n) * shift_v<nn> + nn
    ||
    r == (step + n) * nn
    ||
    r == (step + n) + nn

    ? r
    : 0
    ;
};

// fix ambiguity (for optization)
template<int_t step, int_t n, int_t nn>
struct count_result2_impl<0, step, n, nn>
  : false_
{};



template<int_t r, int_t step, int_t n, int_t... ns>
struct count_result2
{
  static constexpr int_t value = select_value<
    count_result1<r, step, n, ns...>::value,
    count_result2_impl<r, step, n, ns...>
  >;
};

using algo = transform<unpack<lift_v<count_result2>>, add<>>; // 61561126043536 | 2 min | 10 Gio

#endif

using Result = unpack<algo>::f<input>;
Result result = 1;
