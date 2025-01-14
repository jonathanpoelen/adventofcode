/*
{
  echo '#include <jln/mp/list/list.hpp>'
  echo '#include <jln/mp/number/number.hpp>'
  echo 'using namespace jln::mp;'
  echo 'using input = list<'
  sed -E '
    s/ />, number</g
    s/^/  number</
    s/$/>/
  '
  echo '>;'
} < input > day11.hpp
*/

#if defined(TEST) && TEST
#include <jln/mp/number/numbers.hpp>
using namespace jln::mp;

using input = emp::numbers<125, 17>;
#else
#include "day11.hpp"
#endif

#include <jln/mp/algorithm/transform.hpp>
#include <jln/mp/number/operators.hpp>


#if !defined(PART) || PART == 1

constexpr int blinking_times = 25; // _207683

#else

constexpr int blinking_times = 75; // _244782991106220

#endif


template<int_t n>
inline constexpr int even_digits5
  = n < 10 ? 1
  : n < 100 ? 2
  : n < 1000 ? 3
  : n < 10000 ? 4
  : 5
  ;

template<int_t n>
inline constexpr int even_digits10
  = 100000 <= n
  ? 5 + even_digits5<n / 100000>
  : even_digits5<n>
  ;

template<int_t n>
inline constexpr int even_digits
  = 10000000000 <= n
  ? 10 + even_digits10<n / 10000000000>
  : even_digits10<n>
  ;


template<int n>
inline constexpr int_t mid_pow10/*<2>*/ = 10;

template<> inline constexpr int_t mid_pow10<4> = 100;
template<> inline constexpr int_t mid_pow10<6> = 1000;
template<> inline constexpr int_t mid_pow10<8> = 10000;
template<> inline constexpr int_t mid_pow10<10> = 100000;
template<> inline constexpr int_t mid_pow10<12> = 1000000;
template<> inline constexpr int_t mid_pow10<14> = 10000000;
template<> inline constexpr int_t mid_pow10<16> = 100000000;
template<> inline constexpr int_t mid_pow10<18> = 1000000000;


template<int_t i, int_t n, bool = even_digits<n> % 2>
struct blink_impl
  : blink_impl<i-1, n ? n * 2024 : 1>
{};

template<int_t n> struct blink_impl<0, n, false> : number<1> {};
template<int_t n> struct blink_impl<0, n, true> : number<1> {};

template<int_t i, int_t n>
struct blink_impl<i, n, false>
 : number<
     blink_impl<i-1, n / mid_pow10<even_digits<n>>>::value
     +
     blink_impl<i-1, n % mid_pow10<even_digits<n>>>::value
   >
{};


struct blink
{
  template<class n>
  using f = blink_impl<blinking_times, n::value>;
};

using algo = transform<blink, add<>>;

using Result = unpack<algo>::f<input>;
Result result = 1;
