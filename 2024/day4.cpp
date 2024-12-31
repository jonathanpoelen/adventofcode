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
} < input > day4.hpp
*/

#if 0
constexpr char s[] =
  "MMMSXXMASM"
  "MSAMXMSMSA"
  "AMXSXMAAMM"
  "MSAMASMSMX"
  "XMASAMXAMM"
  "XXAMMXXAMA"
  "SMSMSASXSS"
  "SAXAMASAAA"
  "MAMMMXMMMM"
  "MXMXAXMASX"
;

#include <jln/mp/algorithm/make_int_sequence.hpp>
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
#include "day4.hpp"
#endif

#include <jln/mp/list/join.hpp>
#include <jln/mp/list/sliding.hpp>
#include <jln/mp/algorithm/repeat.hpp>
#include <jln/mp/algorithm/fold.hpp>
#include <jln/mp/algorithm/zip.hpp>
#include <jln/mp/algorithm/same_xs.hpp>
#include <jln/mp/functional/lift.hpp>
#include <jln/mp/functional/tee.hpp>
#include <jln/mp/number/operators.hpp>

using c_x = number<'X'>;
using c_m = number<'M'>;
using c_a = number<'A'>;
using c_s = number<'S'>;

#if !defined(PART) || PART == 1
template<class,class,class,class> struct is_xmas_or_samx { using type = false_; };
template<> struct is_xmas_or_samx<c_x, c_m, c_a, c_s> { using type = true_; };
template<> struct is_xmas_or_samx<c_s, c_a, c_m, c_x> { using type = true_; };

using count_xmas_line = sliding_with_c<4, lift_t<is_xmas_or_samx>, add<>>;

struct count_xmas_col
{
  template<class, class, class, class>
  struct f;

  using counter = zip_with<lift_t<is_xmas_or_samx>, add<>>;

  template<class... a, class... b, class... c, class... d>
  struct f<list<a...>, list<b...>, list<c...>, list<d...>>
  : number<
      counter::f<
        list<a...>,
        list<b...>,
        list<c...>,
        list<d...>
      >::value
      +
      counter::f<
        list<a..., void, void, void>,
        list<void, b..., void, void>,
        list<void, void, c..., void>,
        list<void, void, void, d...>
      >::value
      +
      counter::f<
        list<void, void, void, a...>,
        list<void, void, b..., void>,
        list<void, c..., void, void>,
        list<d..., void, void, void>
      >::value
      +
      count_xmas_line::f<d...>::value
    >
  {};
};

using algo = tee<
  take_front_c<3, transform<unpack<count_xmas_line>, add<>>>,
  sliding_with_c<4, count_xmas_col, add<>>,
  add<>
>; // _2462

#else

template<class,class,class> struct is_mas_or_sam { using type = false_; };
template<> struct is_mas_or_sam<c_m, c_a, c_s> { using type = true_; };
template<> struct is_mas_or_sam<c_s, c_a, c_m> { using type = true_; };

struct count_x_mas
{
  template<class, class, class>
  struct f;

  template<class... a, class... b, class... c>
  struct f<list<a...>, list<b...>, list<c...>>
  : zip_with<and_<>, add<>>::f<
      zip_with<lift_t<is_mas_or_sam>>::f<
        list<a..., void, void>,
        list<void, b..., void>,
        list<void, void, c...>
      >,
      zip_with<lift_t<is_mas_or_sam>>::f<
        list<void, void, a...>,
        list<void, b..., void>,
        list<c..., void, void>
      >,
      list<false_, number<JLN_MP_IS_SAME(b, c_a)>..., false_>
    >
  {};
};

using algo = sliding_with_c<3, count_x_mas, add<>>; // 1877
#endif

using Result = unpack<algo>::f<input>;
Result result = 1;
