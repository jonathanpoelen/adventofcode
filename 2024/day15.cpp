/*
{
  echo '#include <jln/mp/number/numbers.hpp>'
  echo 'using namespace jln::mp;'
  echo 'using input = list<'
  echo '  list<'
  sed -E "
    /^#/{
      s/./, '&'/g
      s/, (.*)/  , emp::numbers<\1>/
      1s/  ,/   /
      t
    }
    /^[^#]/{
      s/./'&', /g
      s/^/    /
      \$s/, \$//
    }
    /^\$/{
      s//  >,\n  emp::numbers</
      t
    }
  "
  echo '  >'
  echo '>;'
} <input >day15.hpp
*/

#if defined(TEST) && TEST
#include <jln/mp/number/numbers.hpp>
using namespace jln::mp;

# if TEST == 1

using input = list<
  list<
    emp::numbers<'#', '#', '#', '#', '#', '#', '#', '#'>
  , emp::numbers<'#', '.', '.', 'O', '.', 'O', '.', '#'>
  , emp::numbers<'#', '#', '@', '.', 'O', '.', '.', '#'>
  , emp::numbers<'#', '.', '.', '.', 'O', '.', '.', '#'>
  , emp::numbers<'#', '.', '#', '.', 'O', '.', '.', '#'>
  , emp::numbers<'#', '.', '.', '.', 'O', '.', '.', '#'>
  , emp::numbers<'#', '.', '.', '.', '.', '.', '.', '#'>
  , emp::numbers<'#', '#', '#', '#', '#', '#', '#', '#'>
  >,
  emp::numbers<
    '<', '^', '^', '>', '>', '>', 'v', 'v', '<', 'v', '>', '>', 'v', '<', '<'
  >
>;

# else

using input = list<
  list<
    emp::numbers<'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'>
  , emp::numbers<'#', '.', '.', 'O', '.', '.', 'O', '.', 'O', '#'>
  , emp::numbers<'#', '.', '.', '.', '.', '.', '.', 'O', '.', '#'>
  , emp::numbers<'#', '.', 'O', 'O', '.', '.', 'O', '.', 'O', '#'>
  , emp::numbers<'#', '.', '.', 'O', '@', '.', '.', 'O', '.', '#'>
  , emp::numbers<'#', 'O', '#', '.', '.', 'O', '.', '.', '.', '#'>
  , emp::numbers<'#', 'O', '.', '.', 'O', '.', '.', 'O', '.', '#'>
  , emp::numbers<'#', '.', 'O', 'O', '.', 'O', '.', 'O', 'O', '#'>
  , emp::numbers<'#', '.', '.', '.', '.', 'O', '.', '.', '.', '#'>
  , emp::numbers<'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'>
  >,
  emp::numbers<
    '<', 'v', 'v', '>', '^', '<', 'v', '^', '>', 'v', '>', '^', 'v', 'v', '^', 'v', '>', 'v', '<', '>', 'v', '^', 'v', '<', 'v', '<', '^', 'v', 'v', '<', '<', '<', '^', '>', '<', '<', '>', '<', '>', '>', 'v', '<', 'v', 'v', 'v', '<', '>', '^', 'v', '^', '>', '^', '<', '<', '<', '>', '<', '<', 'v', '<', '<', '<', 'v', '^', 'v', 'v', '^', 'v', '>', '^',
    'v', 'v', 'v', '<', '<', '^', '>', '^', 'v', '^', '^', '>', '<', '<', '>', '>', '>', '<', '>', '^', '<', '<', '>', '<', '^', 'v', 'v', '^', '^', '<', '>', 'v', 'v', 'v', '<', '>', '>', '<', '^', '^', 'v', '>', '^', '>', 'v', 'v', '<', '>', 'v', '<', '<', '<', '<', 'v', '<', '^', 'v', '>', '^', '<', '^', '^', '>', '>', '>', '^', '<', 'v', '<', 'v',
    '>', '<', '>', 'v', 'v', '>', 'v', '^', 'v', '^', '<', '>', '>', '<', '>', '>', '>', '>', '<', '^', '^', '>', 'v', 'v', '>', 'v', '<', '^', '^', '^', '>', '>', 'v', '^', 'v', '^', '<', '^', '^', '>', 'v', '^', '^', '>', 'v', '^', '<', '^', 'v', '>', 'v', '<', '>', '>', 'v', '^', 'v', '^', '<', 'v', '>', 'v', '^', '^', '<', '^', '^', 'v', 'v', '<',
    '<', '<', 'v', '<', '^', '>', '>', '^', '^', '^', '^', '>', '>', '>', 'v', '^', '<', '>', 'v', 'v', 'v', '^', '>', '<', 'v', '<', '<', '<', '>', '^', '^', '^', 'v', 'v', '^', '<', 'v', 'v', 'v', '>', '^', '>', 'v', '<', '^', '^', '^', '^', 'v', '<', '>', '^', '>', 'v', 'v', 'v', 'v', '>', '<', '>', '>', 'v', '^', '<', '<', '^', '^', '^', '^', '^',
    '^', '>', '<', '^', '>', '<', '>', '>', '>', '<', '>', '^', '^', '<', '<', '^', '^', 'v', '>', '>', '>', '<', '^', '<', 'v', '>', '^', '<', 'v', 'v', '>', '>', 'v', '>', '>', '>', '^', 'v', '>', '<', '>', '^', 'v', '>', '<', '<', '<', '<', 'v', '>', '>', 'v', '<', 'v', '<', 'v', '>', 'v', 'v', 'v', '>', '^', '<', '>', '<', '<', '>', '^', '>', '<',
    '^', '>', '>', '<', '>', '^', 'v', '<', '>', '<', '^', 'v', 'v', 'v', '<', '^', '^', '<', '>', '<', 'v', '<', '<', '<', '<', '<', '>', '<', '^', 'v', '<', '<', '<', '>', '<', '<', '<', '^', '^', '<', 'v', '<', '^', '^', '^', '>', '<', '^', '>', '>', '^', '<', 'v', '^', '>', '<', '<', '<', '^', '>', '>', '^', 'v', '<', 'v', '^', 'v', '<', 'v', '^',
    '>', '^', '>', '>', '^', 'v', '>', 'v', 'v', '>', '^', '<', '<', '^', 'v', '<', '>', '>', '<', '<', '>', '<', '<', 'v', '<', '<', 'v', '>', '<', '>', 'v', '<', '^', 'v', 'v', '<', '<', '<', '>', '^', '^', 'v', '^', '>', '^', '^', '>', '>', '>', '<', '<', '^', 'v', '>', '>', 'v', '^', 'v', '>', '<', '^', '^', '>', '>', '^', '<', '>', 'v', 'v', '^',
    '<', '>', '<', '^', '^', '>', '^', '^', '^', '<', '>', '<', 'v', 'v', 'v', 'v', 'v', '^', 'v', '<', 'v', '<', '<', '>', '^', 'v', '<', 'v', '>', 'v', '<', '<', '^', '>', '<', '<', '>', '<', '<', '>', '<', '<', '<', '^', '^', '<', '<', '<', '^', '<', '<', '>', '>', '<', '<', '>', '<', '^', '^', '^', '>', '^', '^', '<', '>', '^', '>', 'v', '<', '>',
    '^', '^', '>', 'v', 'v', '<', '^', 'v', '^', 'v', '<', 'v', 'v', '>', '^', '<', '>', '<', 'v', '<', '^', 'v', '>', '^', '^', '^', '>', '>', '>', '^', '^', 'v', 'v', 'v', '^', '>', 'v', 'v', 'v', '<', '>', '>', '>', '^', '<', '^', '>', '>', '>', '>', '>', '^', '<', '<', '^', 'v', '>', '^', 'v', 'v', 'v', '<', '>', '^', '<', '>', '<', '<', 'v', '>',
    'v', '^', '^', '>', '>', '>', '<', '<', '^', '^', '<', '>', '>', '^', 'v', '^', '<', 'v', '^', 'v', 'v', '<', '>', 'v', '^', '<', '<', '>', '^', '<', '^', 'v', '^', 'v', '>', '<', '^', '<', '<', '<', '>', '<', '<', '^', '<', 'v', '>', '<', 'v', '<', '>', 'v', 'v', '>', '>', 'v', '>', '<', 'v', '^', '<', 'v', 'v', '<', '>', 'v', '^', '<', '<', '^'
  >
>;
# endif
#else
#include "day15.hpp"
#endif

#include <jln/mp/list/join.hpp>
#include <jln/mp/list/push_front.hpp>
#include <jln/mp/list/take_front.hpp>
#include <jln/mp/algorithm/fold.hpp>
#include <jln/mp/algorithm/index.hpp>
#include <jln/mp/algorithm/transform.hpp>
#include <jln/mp/algorithm/make_int_sequence.hpp>

using robot = number<'@'>;

using wall_ = number<'#'>; // 35
using box_ = number<'O'>; // 79
using pan_ = number<'.'>; // 46

#if 1
class wall {};
class box {};
class pan {};

template<class T> struct named_impl { using type = T; };
template<> struct named_impl<wall_> { using type = wall; };
template<> struct named_impl<box_> { using type = box; };
template<> struct named_impl<pan_> { using type = pan; };

template<class T> using named = unpack<transform<lift_t<named_impl>>>::f<T>;
#else
template<class T> using named = T;
#endif

using up = number<'^'>;
using right = number<'>'>;
using down = number<'v'>;
using left = number<'<'>;


#if !defined(PART) || PART == 1

template<class G>
struct Grid
{
  template<class x, class y>
  static G::template f<y::value>::template f<x::value> get(x*, y*);
};

template<class G, int x1, int y1, int x2, int y2>
struct updated_map : G
{
  using G::get;

  static pan get(number<x1>*, number<y1>*);

  static box get(number<x2>*, number<y2>*);
};


template<int_t i> inline constexpr number<i>* num = nullptr;


template<int x, int y>
struct move;

template<class> struct make_move;
template<> struct make_move<up> { using type = move<0,-1>; };
template<> struct make_move<right> { using type = move<1,0>; };
template<> struct make_move<down> { using type = move<0,1>; };
template<> struct make_move<left> { using type = move<-1,0>; };


template<class G, int x, int y>
struct state {};


template<class G, int x, int y, int xx, int yy, class = decltype(G::get(num<x>, num<y>))>
inline constexpr int count_box_v = 0;

template<class G, int x, int y, int xx, int yy>
inline constexpr int count_box_v<G, x, y, xx, yy, box> = count_box_v<G, x+xx, y+yy, xx, yy> + 1;

template<class G, int x, int y, int xx, int yy>
inline constexpr int count_box_v<G, x, y, xx, yy, wall> = 0x10'0000;


template<class G, int x, int y, int xx, int yy, int n, bool = n < 0x10'0000>
struct update_grid_and_state
{
  using type = state<G, x, y>;
};

template<class G, int x, int y, int xx, int yy, int n>
struct update_grid_and_state<G, x, y, xx, yy, n, true>
{
  using type = state<updated_map<G, x+xx, y+yy, x+xx*(n+2), y+yy*(n+2)>, x+xx, y+yy>;
};


template<class G, int x, int y, int xx, int yy, class c> // c = '.' / '@'
struct dispatch
{
  using type = state<G, x+xx, y+yy>;
};

template<class G, int x, int y, int xx, int yy>
struct dispatch<G, x, y, xx, yy, wall>
{
  using type = state<G, x, y>;
};

template<class G, int x, int y, int xx, int yy>
struct dispatch<G, x, y, xx, yy, box>
  : update_grid_and_state<G, x, y, xx, yy, count_box_v<G, x+xx*2, y+yy*2, xx, yy>>
{};


template<class, class>
struct next_state;

template<class G, int x, int y, int xx, int yy>
struct next_state<state<G, x, y>, move<xx, yy>>
  : dispatch<G, x, y, xx, yy, decltype(G::get(num<x+xx>, num<y+yy>))>
{};


template<class s, class move>
using next_state_t = typename next_state<s,move>::type;


template<int wh, class, class>
struct count_result;


template<int wh>
struct count_result_impl
{
  template<class... p>
  using f = number<(... + (p::value / wh * 100 + p::value % wh))>;
};

template<int wh, class G, int x, int y, class... p>
struct count_result<wh, state<G, x, y>, list<p...>>
{
  using type =
    typename join<count_result_impl<wh>>
    ::template f<
      typename conditional_c<
        JLN_MP_IS_SAME(box, decltype(G::get(num<p::value % wh>, num<p::value / wh>)))
      >
      ::template f<list<p>, list<>>
      ...
    >;
};


template<class, class>
struct part1;

template<class... l, class... d>
struct part1<list<l...>, list<d...>>
{
  using grid = build_indexed_v<emp::build_indexed_v<named<l>>...>;
  static const int wh = sizeof...(l);

  static const int pos = join<index_of<number<'@'>>>::f<l...>::value;

  using impl = push_front<
    state<Grid<grid>, pos % wh, pos / wh>,
    fold<lift<next_state_t>>
  >;

  using st = typename take_front_c<1000, impl>
    ::template f<typename make_move<d>::type...>;

  #if 0
  using type = st;
  #else
  using type = typename count_result<wh, st, emp::make_int_sequence_c<wh * wh>>::type;
  #endif
};

using algo = lift_t<part1>; // _1487337

#else

using algo = part2;

#endif

using Result = unpack<algo>::f<input>;
Result result = 1;
