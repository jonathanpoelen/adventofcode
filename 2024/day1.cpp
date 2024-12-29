/*
{
  echo '#include <jln/mp/list/pop_front.hpp>'
  echo 'using namespace jln::mp;'
  echo 'using input = pop_front<>::f<void'
  rg '^(\d+)\s+(\d+)' -r', list<number<$1>, number<$2>>' input
  echo '>;'
} > day1.txt
*/

/*
duration timeout 8 g++ -I ~/projects/jln.mpl/include -fdiagnostics-color=always -std=c++17 \
  -fsyntax-only test.cpp \
| sed -E 's/jln::mp:://g;s/number<([0-9]+)>/_\1/g'
*/

#if 0
#include <jln/mp/list/list.hpp>
#include <jln/mp/number/number.hpp>
using namespace jln::mp;
using input = list<
  list<number<10>, number<20>>,
  list<number<11>, number<21>>,
  list<number<12>, number<22>>,
  list<number<13>, number<23>>
>;
#else
#include "day1.txt"
#endif

#include <jln/mp/algorithm/sort.hpp>
#include <jln/mp/algorithm/zip.hpp>
#include <jln/mp/algorithm/transform.hpp>
#include <jln/mp/algorithm/count.hpp>
#include <jln/mp/algorithm/counter.hpp>
#include <jln/mp/map/map_find.hpp>
#include <jln/mp/list/at.hpp>
#include <jln/mp/functional/tee.hpp>
#include <jln/mp/number/operators.hpp>
#include <jln/mp/number/math.hpp>

#if !defined(PART) || PART == 1
using part = zip_with<sort<>, zip_with<sub<abs<>>, add<>>>; // 765748
#else
struct part2_impl
{
  template<class... kvs>
  struct map_counter
  {
    template<class x>
    using f = typename map_find<x, unpack<at1<>>, always<number<0>>>::template f<kvs...>;
  };

  template<class l1, class l2>
  using f = typename unpack<
    transform<
      tee<
        identity,
        unpack<counter<lift<map_counter>>>::f<l2>,
        mul<>
      >,
      add<>
    >
  >::template f<l1>;
};
using part = zip<part2_impl>; // 27732508
#endif

using Result = unpack<part>::f<input>;
Result result = 1;
