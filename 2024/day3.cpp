/*
{
  echo '#include <jln/mp/list/pop_front.hpp>'
  echo 'using namespace jln::mp;'
  echo 'using input = pop_front<>::f<void'
  sed -E 's/./&\n/g' | sed -E "s/^([^'])/,number<'\\1'>/;t;s/./,number<'\\\''>/"
  echo '>;'
} < input > day2.txt
*/

#if 0
constexpr char s[] =
  "xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))"
;

#include <jln/mp/algorithm/make_int_sequence.hpp>
using namespace jln::mp;

struct to_input
{
  template<int_t... i>
  struct f
  {
    template<char const (&s)[sizeof...(i)+1]>
    using from = list<number<s[i]>...>;
  };
};

using input = emp::make_int_sequence_v_c<sizeof(s) - 1, to_input>::from<s>;
#else
#include "day3.txt"
#endif

#include <jln/mp/algorithm/make_int_sequence.hpp>
#include <jln/mp/algorithm/transform.hpp>
#include <jln/mp/algorithm/fold.hpp>
#include <jln/mp/algorithm/split_at.hpp>
#include <jln/mp/list/join.hpp>
#include <jln/mp/list/drop_front.hpp>

using m = number<'m'>;
using u = number<'u'>;
using l = number<'l'>;
using po = number<'('>;
using pc = number<')'>;
using comma = number<','>;

template<int N> struct num1
{
  using num1_marker = void;
  static constexpr int n1 = N;
};

template<int N1, int N2>
struct num2
{
  using num2_marker = void;
  static constexpr int n1 = N1;
  static constexpr int n2 = N2;
};

template<int, class = void>
struct state {};

template<class c> inline constexpr bool is_digit_v = '0' <= c::value && c::value <= '9';
template<class c> inline constexpr int to_digit_v = c::value - '0';

template<class> struct get_result;

// faster
#if 1

template<class state, class c> struct parse_next;

// @{
template<int r, class T, class U> struct parse_next<state<r, T>, U> { using type = state<r, void>; };

// m
template<int r, class T> struct parse_next<state<r, T>, m> { using type = state<r, m>; };
// mu
template<int r> struct parse_next<state<r, m>, u> { using type = state<r, u>; };
// mul
template<int r> struct parse_next<state<r, u>, l> { using type = state<r, l>; };
// mul(
template<int r> struct parse_next<state<r, l>, po> { using type = state<r, po>; };

// mul([0-9]
template<int r, class c> requires (is_digit_v<c>)
struct parse_next<state<r, po>, c> { using type = state<r, num1<to_digit_v<c>>>; };

// mul([0-9]+
template<int r, int n, class c> requires (is_digit_v<c>)
struct parse_next<state<r, num1<n>>, c> { using type = state<r, num1<n * 10 + to_digit_v<c>>>; };

// mul([0-9]+,
template<int r, int n>
struct parse_next<state<r, num1<n>>, comma> { using type = state<r, num2<n, -1>>; };

// mul([0-9]+,[0-9]+
template<int r, int n1, int n2, class c> requires (is_digit_v<c>)
struct parse_next<state<r, num2<n1, n2>>, c>
{ using type = state<r, num2<n1, (n2 < 0 ? 0 : n2 * 10) + to_digit_v<c>>>; };

// mul([0-9]+,[0-9]+)
template<int r, int n1, int n2>
struct parse_next<state<r, num2<n1, n2>>, pc> { using type = state<r + n1 * n2, void>; };
// @}

template<int r, class T> struct get_result<state<r, T>> { using type = number<r>; };

using part1 = push_front<state<0, void>, fold<lift_t<parse_next>, lift_t<get_result>>>;

#else

template<class T> inline constexpr T* ptr_v = nullptr;

template<int r, class T, int_t c>
constexpr auto parse(state<r, T>*, number<c>*)
{
  // mul([0-9]+
  if constexpr (requires { typename T::num1_marker; }) {
    if constexpr ('0' <= c && c <= '9') return ptr_v<state<r, num1<T::n1 * 10 + c - '0'>>>;
    else if constexpr (c == ',') return ptr_v<state<r, num2<T::n1, -1>>>;
    else return ptr_v<state<r, void>>;
  }
  // mul([0-9]+,[0-9]+
  else if constexpr (requires { typename T::num2_marker; }) {
    if constexpr ('0' <= c && c <= '9') return ptr_v<state<r, num2<T::n1, (T::n2 == -1 ? 0 : T::n2 * 10) + c - '0'>>>;
    else if constexpr (c == ')') return ptr_v<state<r + T::n1 * T::n2, void>>;
    else return ptr_v<state<r, void>>;
  }
  // m
  else if constexpr (JLN_MP_IS_SAME(T, void) && c == 'm') return ptr_v<state<r, m>>;
  // mu
  else if constexpr (JLN_MP_IS_SAME(T, m) && c == 'u') return ptr_v<state<r, u>>;
  // mul
  else if constexpr (JLN_MP_IS_SAME(T, u) && c == 'l') return ptr_v<state<r, l>>;
  // mul(
  else if constexpr (JLN_MP_IS_SAME(T, l) && c == '(') return ptr_v<state<r, po>>;
  // mul([0-9]+,[0-9]+)
  else if constexpr (JLN_MP_IS_SAME(T, po) && '0' <= c && c <= '9') return ptr_v<state<r, num1<c-'0'>>>;
  else return ptr_v<state<r, void>>;
}

template<class state, class c>
using parse_next = decltype(parse(state{}, ptr_v<c>));

template<int r, class T> struct get_result<state<r, T>*> { using type = number<r>; };

using part1 = push_front<state<0, void>*, fold<lift<parse_next>, lift_t<get_result>>>;
#endif

using algo = part1; // 179834255
#if !defined(PART) || PART == 1
#else

using d = number<'d'>;
using o = number<'o'>;
using n = number<'n'>;
using t = number<'t'>;
using squote = number<'\''>;

using Do = number<(1 << 8)>;
using Don = number<(2 << 8)>;
using Don_ = number<(3 << 8)>;
using Dont = number<(4 << 8)>;
using Donto = number<(5 << 8)>;
using Doo = number<(6 << 9)>;

template<class> class dont;

// parse "don't"
template<int r, class T> struct parse_next<state<r, T>, d> { using type = state<r, d>; };
template<int r> struct parse_next<state<r, d>, o> { using type = state<r, Do>; };
template<int r> struct parse_next<state<r, Do>, n> { using type = state<r, Don>; };
template<int r> struct parse_next<state<r, Don>, squote> { using type = state<r, Don_>; };
template<int r> struct parse_next<state<r, Don_>, t> { using type = state<r, Dont>; };
template<int r> struct parse_next<state<r, Dont>, po> { using type = state<r, Donto>; };
template<int r> struct parse_next<state<r, Donto>, pc> { using type = state<r, dont<void>>; };

// ignore when "don't"
template<int r, class s, class T> struct parse_next<state<r, dont<s>>, T> { using type = state<r, dont<void>>; };
// fix ambiguity
template<int r, class s> struct parse_next<state<r, dont<s>>, m> { using type = state<r, dont<void>>; };

// parse "do"
template<int r, class s> struct parse_next<state<r, dont<s>>, d> { using type = state<r, dont<d>>; };
template<int r> struct parse_next<state<r, dont<d>>, o> { using type = state<r, dont<Do>>; };
template<int r> struct parse_next<state<r, dont<Do>>, po> { using type = state<r, dont<Doo>>; };
template<int r> struct parse_next<state<r, dont<Doo>>, pc> { using type = state<r, void>; };

#endif

using Result = unpack<algo>::f<input>;
Result result = 1;
