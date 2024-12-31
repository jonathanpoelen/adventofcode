/*
{
  echo '#include <jln/mp/list/list.hpp>'
  echo '#include <jln/mp/number/number.hpp>'
  echo 'using namespace jln::mp;'
  echo 'using input = list<'
  sed -E '
    s/ />, number</g
    s/^/, list<number</;s/$/>>/
    1s/,/ /
  '
  echo '>;'
} < input > day2.hpp
*/

#if 0
#include <jln/mp/list/list.hpp>
#include <jln/mp/number/numbers.hpp>
using namespace jln::mp;
using input = list<
  emp::numbers<7, 6, 4, 2, 1>,
  emp::numbers<1, 2, 7, 8, 9>,
  emp::numbers<9, 7, 6, 2, 1>,
  emp::numbers<1, 3, 2, 4, 5>,
  emp::numbers<8, 6, 4, 4, 1>,
  emp::numbers<1, 3, 6, 7, 9>,
  emp::numbers<9, 1, 2>
>;
#else
#include "day2.hpp"
#endif

#include <jln/mp/algorithm/transform.hpp>
#include <jln/mp/algorithm/arrange.hpp>
#include <jln/mp/algorithm/all_of.hpp>
#include <jln/mp/algorithm/any_of.hpp>
#include <jln/mp/algorithm/remove.hpp>
#include <jln/mp/algorithm/pairwise.hpp>
#include <jln/mp/algorithm/make_int_sequence.hpp>
#include <jln/mp/functional/capture_front.hpp>
#include <jln/mp/list/at.hpp>
#include <jln/mp/list/pop_front.hpp>
#include <jln/mp/number/operators.hpp>

struct part1 // 463
{
  template<int_t prev, int_t next>
  using check_inc = number<prev + 1 <= next && next <= prev + 3>;
  using pair_check_inc = unpack<lift_v<check_inc>>;

  template<int_t prev, int_t next>
  using check_dec = check_inc<-prev, -next>;
  using pair_check_dec = unpack<lift_v<check_dec>>;

  template<class prev, class next>
  using make_checker = emp::conditional_c<
    prev::value < next::value,
    pair_check_inc,
    pair_check_dec
  >;

  template<class a, class b, class... i>
  using f = typename pairwise<all_of<make_checker<a, b>>>
    ::template f<a, b, i...>;
};

#if !defined(PART) || PART == 1
using part = part1;
#else
struct part
{
  struct checker
  {
    struct make_arrange
    {
      template<class... i>
      using f = arrange_c_with<part1, i::value...>;
    };

    template<class... i>
    using f = capture_front<typename remove<i, make_arrange>::template f<i...>...>;
  };

  template<std::size_t i>
  struct make_checker
    : emp::make_int_sequence_c<i, checker>
  {};

  template<class... i>
  using f = typename make_checker<sizeof...(i)>
    ::template f<any_of<capture_front<i...>>>;
};
#endif

using algo = transform<unpack<part>, add<>>;

using Result = unpack<algo>::f<input>;
Result result = 1;
