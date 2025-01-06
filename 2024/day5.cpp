/*
{
  echo '#include <jln/mp/list/list.hpp>'
  echo '#include <jln/mp/number/number.hpp>'
  echo 'using namespace jln::mp;'
  echo 'using input = list<'
  echo '  list<'
  sed -E '
    s/([0-9]+)\|([0-9]+)/  , list<number<\1>, number<\2>>/
    /^$/{
      s/^$/  >,\n  list</
      n
      s/^/    list</
    }
    s/^[0-9]/  , list<&/
    s/([0-9]+),/number<\1>,/g
    s/([0-9]+)$/number<\1>>/
    1s/,/ /
  '
  echo '  >'
  echo '>;'
} < input > day5.hpp
*/

#if 0
#include <jln/mp/number/numbers.hpp>
using namespace jln::mp;

using input = list<
list<
  emp::numbers<47,53>,
  emp::numbers<97,13>,
  emp::numbers<97,61>,
  emp::numbers<97,47>,
  emp::numbers<75,29>,
  emp::numbers<61,13>,
  emp::numbers<75,53>,
  emp::numbers<29,13>,
  emp::numbers<97,29>,
  emp::numbers<53,29>,
  emp::numbers<61,53>,
  emp::numbers<97,53>,
  emp::numbers<61,29>,
  emp::numbers<47,13>,
  emp::numbers<75,47>,
  emp::numbers<97,75>,
  emp::numbers<47,61>,
  emp::numbers<75,61>,
  emp::numbers<47,29>,
  emp::numbers<75,13>,
  emp::numbers<53,13>
>,
list<
  emp::numbers<75,47,61,53,29>,
  emp::numbers<97,61,53,29,13>,
  emp::numbers<75,29,13>,
  emp::numbers<75,97,47,61,53>,
  emp::numbers<61,13,29>,
  emp::numbers<97,13,75,29,47>
>
>;
#else
#include "day5.hpp"
#endif

#include <jln/mp/algorithm/transform.hpp>
#include <jln/mp/algorithm/is_sorted.hpp>
#include <jln/mp/algorithm/sort.hpp>
#include <jln/mp/functional/tee.hpp>
#include <jln/mp/functional/if.hpp>
#include <jln/mp/number/operators.hpp>
#include <jln/mp/utility/is_base_of.hpp>
#include <jln/mp/list/at.hpp>

struct midpoint
{
  template<class... xs>
  using f = typename at_c<sizeof...(xs) / 2>::template f<xs...>;
};

template<class Set>
struct comparator
{
  template<class x, class y>
  using f = emp::is_base_of<list<x, y>, Set>;
};

#if !defined(PART) || PART == 1

template<class page_ordering_rules, class pages>
struct part1;

template<class... page_ordering_rules, class... pages>
struct part1<list<page_ordering_rules...>, list<pages...>>
{
  struct Set : page_ordering_rules... {};

  using type = typename transform<
    unpack<
      if_<
        is_sorted<comparator<Set>>,
        midpoint,
        always<false_>
      >
    >,
    add<>
  >::template f<pages...>;
};

using algo = lift_t<part1>; // 4957

#else

template<class page_ordering_rules, class pages>
struct part2;

template<class... page_ordering_rules, class... pages>
struct part2<list<page_ordering_rules...>, list<pages...>>
{
  struct Set : page_ordering_rules... {};

  using type = typename transform<
    unpack<
      if_<
        is_sorted<comparator<Set>>,
        always<false_>,
        sort<comparator<Set>, midpoint>
      >
    >,
    add<>
  >::template f<pages...>;
};

using algo = lift_t<part2>; // 6938

#endif

using Result = unpack<algo>::f<input>;
Result result = 1;
