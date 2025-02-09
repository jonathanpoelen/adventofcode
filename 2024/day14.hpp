#include <jln/mp/number/numbers.hpp>
using namespace jln::mp;
using input = list<
  emp::numbers<81,85,-35,88>
, emp::numbers<89,76,-33,35>
, emp::numbers<79,21,92,-25>
, emp::numbers<64,67,-30,42>
, emp::numbers<18,21,31,52>
, emp::numbers<1,23,10,-13>
, emp::numbers<36,24,60,13>
, emp::numbers<89,34,-38,-51>
, emp::numbers<70,91,-82,96>
, emp::numbers<28,52,31,-5>
, emp::numbers<96,102,-39,86>
, emp::numbers<29,32,-71,52>
, emp::numbers<72,71,-5,-65>
, emp::numbers<93,26,-64,-55>
, emp::numbers<40,97,73,-50>
, emp::numbers<39,2,39,21>
, emp::numbers<45,49,-80,72>
, emp::numbers<82,29,-9,37>
, emp::numbers<94,70,-67,95>
, emp::numbers<31,77,5,84>
, emp::numbers<23,19,47,23>
, emp::numbers<85,0,91,97>
, emp::numbers<72,4,42,47>
, emp::numbers<89,89,-25,29>
, emp::numbers<50,51,-86,40>
, emp::numbers<1,93,35,-22>
, emp::numbers<39,70,-74,-34>
, emp::numbers<31,67,-98,61>
, emp::numbers<56,80,49,-95>
, emp::numbers<83,35,42,14>
, emp::numbers<74,54,25,-63>
, emp::numbers<1,24,-97,-94>
, emp::numbers<61,69,45,65>
, emp::numbers<61,50,-54,91>
, emp::numbers<96,26,-62,58>
, emp::numbers<83,25,-9,21>
, emp::numbers<89,46,15,-51>
, emp::numbers<56,59,11,62>
, emp::numbers<47,3,-24,-72>
, emp::numbers<3,68,-73,-73>
, emp::numbers<25,77,-97,-34>
, emp::numbers<39,69,-28,-95>
, emp::numbers<63,48,65,48>
, emp::numbers<80,26,92,14>
, emp::numbers<27,73,-73,53>
, emp::numbers<68,14,69,-59>
, emp::numbers<38,65,-24,98>
, emp::numbers<13,1,-12,-8>
, emp::numbers<55,79,97,-57>
, emp::numbers<88,19,41,82>
, emp::numbers<14,102,54,-10>
, emp::numbers<21,38,-95,-47>
, emp::numbers<31,100,-74,-83>
, emp::numbers<36,48,7,-75>
, emp::numbers<55,65,41,-31>
, emp::numbers<39,67,-74,61>
, emp::numbers<72,85,86,-37>
, emp::numbers<32,97,28,-83>
, emp::numbers<28,13,-68,-77>
, emp::numbers<25,37,-17,-93>
, emp::numbers<40,41,-66,4>
, emp::numbers<96,89,-73,-80>
, emp::numbers<5,36,-15,-32>
, emp::numbers<37,78,77,-53>
, emp::numbers<34,70,-95,-42>
, emp::numbers<79,48,42,-96>
, emp::numbers<75,75,18,-53>
, emp::numbers<29,25,-26,51>
, emp::numbers<32,85,16,-36>
, emp::numbers<75,3,17,36>
, emp::numbers<96,36,-90,83>
, emp::numbers<24,43,28,-74>
, emp::numbers<39,64,-81,12>
, emp::numbers<91,42,-38,-13>
, emp::numbers<32,35,-24,37>
, emp::numbers<57,1,-4,89>
, emp::numbers<5,75,84,-64>
, emp::numbers<56,41,49,98>
, emp::numbers<49,24,-26,2>
, emp::numbers<97,13,72,52>
, emp::numbers<72,19,-33,6>
, emp::numbers<61,76,37,-38>
, emp::numbers<80,81,-63,80>
, emp::numbers<58,44,47,-24>
, emp::numbers<85,17,91,75>
, emp::numbers<11,3,-74,-88>
, emp::numbers<47,96,65,-23>
, emp::numbers<66,67,-2,84>
, emp::numbers<15,91,-67,65>
, emp::numbers<37,33,-24,-66>
, emp::numbers<53,2,23,-33>
, emp::numbers<60,89,97,9>
, emp::numbers<27,42,-21,-54>
, emp::numbers<32,27,57,71>
, emp::numbers<84,45,89,18>
, emp::numbers<53,4,47,48>
, emp::numbers<8,52,-93,-39>
, emp::numbers<22,85,81,-26>
, emp::numbers<57,19,-78,82>
, emp::numbers<38,18,26,48>
, emp::numbers<18,64,56,28>
, emp::numbers<43,100,-50,-83>
, emp::numbers<40,6,91,76>
, emp::numbers<28,72,-23,-92>
, emp::numbers<71,91,35,45>
, emp::numbers<2,41,61,41>
, emp::numbers<80,64,16,99>
, emp::numbers<77,69,21,15>
, emp::numbers<16,94,83,35>
, emp::numbers<30,48,-73,38>
, emp::numbers<69,84,83,6>
, emp::numbers<98,17,-39,-13>
, emp::numbers<50,45,-27,10>
, emp::numbers<8,6,9,5>
, emp::numbers<88,50,87,-99>
, emp::numbers<21,100,-65,-47>
, emp::numbers<75,102,64,-63>
, emp::numbers<83,34,62,-81>
, emp::numbers<40,31,-32,47>
, emp::numbers<88,13,92,-93>
, emp::numbers<71,82,-61,10>
, emp::numbers<16,38,39,62>
, emp::numbers<23,16,47,59>
, emp::numbers<18,30,-48,22>
, emp::numbers<16,21,84,-63>
, emp::numbers<12,9,-87,-14>
, emp::numbers<84,57,90,49>
, emp::numbers<44,23,6,-14>
, emp::numbers<82,90,51,31>
, emp::numbers<48,12,24,74>
, emp::numbers<28,69,24,77>
, emp::numbers<68,61,-82,61>
, emp::numbers<91,98,-36,-22>
, emp::numbers<75,62,-59,72>
, emp::numbers<17,81,86,85>
, emp::numbers<75,55,68,-16>
, emp::numbers<21,23,-16,-17>
, emp::numbers<85,45,-59,-66>
, emp::numbers<24,74,-68,95>
, emp::numbers<97,21,-35,40>
, emp::numbers<54,65,7,8>
, emp::numbers<43,24,-27,-21>
, emp::numbers<23,100,33,59>
, emp::numbers<88,64,-33,-94>
, emp::numbers<22,63,4,19>
, emp::numbers<44,89,74,-30>
, emp::numbers<55,83,96,-34>
, emp::numbers<55,30,49,-13>
, emp::numbers<53,48,-25,33>
, emp::numbers<33,91,-5,97>
, emp::numbers<43,50,-72,57>
, emp::numbers<35,95,-81,-56>
, emp::numbers<65,91,-4,12>
, emp::numbers<67,37,-81,-89>
, emp::numbers<38,86,-96,23>
, emp::numbers<10,95,8,-45>
, emp::numbers<2,102,-33,10>
, emp::numbers<12,31,-68,-1>
, emp::numbers<78,82,-10,-30>
, emp::numbers<18,76,-94,-22>
, emp::numbers<10,99,12,-71>
, emp::numbers<43,76,77,-61>
, emp::numbers<23,32,-18,53>
, emp::numbers<26,86,-90,83>
, emp::numbers<28,54,40,-37>
, emp::numbers<61,7,-81,67>
, emp::numbers<66,23,-53,18>
, emp::numbers<1,52,-64,-96>
, emp::numbers<4,52,-95,18>
, emp::numbers<66,36,41,25>
, emp::numbers<68,0,-53,13>
, emp::numbers<10,55,-16,-12>
, emp::numbers<76,30,69,29>
, emp::numbers<45,5,-22,-79>
, emp::numbers<46,46,-25,-58>
, emp::numbers<73,1,-54,-88>
, emp::numbers<97,98,-14,-18>
, emp::numbers<36,98,56,74>
, emp::numbers<38,80,-53,-61>
, emp::numbers<93,80,38,12>
, emp::numbers<97,52,37,-87>
, emp::numbers<7,96,-91,-75>
, emp::numbers<85,0,-90,24>
, emp::numbers<23,22,-45,71>
, emp::numbers<82,72,42,-65>
, emp::numbers<71,71,68,46>
, emp::numbers<75,36,65,49>
, emp::numbers<2,63,86,-65>
, emp::numbers<78,28,-35,48>
, emp::numbers<27,87,76,-45>
, emp::numbers<5,65,89,23>
, emp::numbers<9,51,37,-47>
, emp::numbers<68,61,44,38>
, emp::numbers<2,60,57,-69>
, emp::numbers<11,52,58,45>
, emp::numbers<43,10,-99,-13>
, emp::numbers<31,67,-21,99>
, emp::numbers<6,91,-45,-79>
, emp::numbers<82,32,-42,-60>
, emp::numbers<79,29,17,71>
, emp::numbers<73,66,93,-35>
, emp::numbers<97,21,-13,90>
, emp::numbers<59,11,-84,-76>
, emp::numbers<94,40,13,56>
, emp::numbers<11,7,8,-71>
, emp::numbers<2,67,-41,10>
, emp::numbers<87,5,12,-56>
, emp::numbers<68,98,-60,-25>
, emp::numbers<49,81,48,50>
, emp::numbers<88,64,-87,91>
, emp::numbers<98,59,-13,-54>
, emp::numbers<61,94,94,8>
, emp::numbers<83,53,-60,-27>
, emp::numbers<90,60,-64,27>
, emp::numbers<73,37,72,-32>
, emp::numbers<93,5,9,-52>
, emp::numbers<75,43,-57,29>
, emp::numbers<92,3,88,28>
, emp::numbers<53,10,47,51>
, emp::numbers<12,34,6,-9>
, emp::numbers<67,92,-53,32>
, emp::numbers<96,89,84,-56>
, emp::numbers<66,54,41,79>
, emp::numbers<75,31,94,45>
, emp::numbers<92,33,88,-47>
, emp::numbers<40,91,76,81>
, emp::numbers<91,34,-61,28>
, emp::numbers<4,85,-66,-42>
, emp::numbers<69,69,15,15>
, emp::numbers<43,10,45,69>
, emp::numbers<27,9,-21,-71>
, emp::numbers<83,30,65,-78>
, emp::numbers<27,56,-25,-1>
, emp::numbers<20,21,8,7>
, emp::numbers<0,64,80,-58>
, emp::numbers<70,57,94,-77>
, emp::numbers<42,73,80,-97>
, emp::numbers<37,99,-56,-95>
, emp::numbers<61,87,66,58>
, emp::numbers<33,33,-96,21>
, emp::numbers<17,26,-15,-2>
, emp::numbers<62,87,46,-30>
, emp::numbers<22,6,-49,-67>
, emp::numbers<85,78,-86,-95>
, emp::numbers<13,78,-24,-92>
, emp::numbers<99,58,-88,-71>
, emp::numbers<8,74,54,-32>
, emp::numbers<3,3,35,97>
, emp::numbers<2,63,10,45>
, emp::numbers<32,68,-47,-84>
, emp::numbers<23,97,-21,70>
, emp::numbers<61,94,-26,66>
, emp::numbers<41,22,3,22>
, emp::numbers<73,5,6,52>
, emp::numbers<55,97,23,66>
, emp::numbers<52,41,-54,18>
, emp::numbers<72,94,-11,97>
, emp::numbers<79,45,66,68>
, emp::numbers<95,98,-29,75>
, emp::numbers<75,63,17,-8>
, emp::numbers<85,21,61,-58>
, emp::numbers<49,49,78,98>
, emp::numbers<53,67,19,-11>
, emp::numbers<15,13,31,55>
, emp::numbers<51,91,46,12>
, emp::numbers<58,46,39,79>
, emp::numbers<45,79,-51,84>
, emp::numbers<68,63,44,23>
, emp::numbers<71,96,-31,66>
, emp::numbers<65,60,-2,22>
, emp::numbers<81,92,-59,16>
, emp::numbers<75,35,-7,52>
, emp::numbers<97,31,-70,-40>
, emp::numbers<43,63,-72,-34>
, emp::numbers<4,34,53,53>
, emp::numbers<45,98,-22,24>
, emp::numbers<32,74,26,23>
, emp::numbers<24,99,29,-37>
, emp::numbers<28,4,29,97>
, emp::numbers<20,101,57,-18>
, emp::numbers<82,23,-96,-43>
, emp::numbers<85,10,8,-89>
, emp::numbers<98,78,88,-91>
, emp::numbers<77,2,41,-40>
, emp::numbers<50,88,-28,54>
, emp::numbers<77,17,-4,-58>
, emp::numbers<31,1,3,85>
, emp::numbers<97,52,-35,80>
, emp::numbers<80,67,-36,-69>
, emp::numbers<61,44,-28,76>
, emp::numbers<66,82,-2,-95>
, emp::numbers<18,88,83,-7>
, emp::numbers<46,6,-55,74>
, emp::numbers<99,51,-64,-77>
, emp::numbers<33,25,50,97>
, emp::numbers<71,29,17,71>
, emp::numbers<99,47,-96,-20>
, emp::numbers<45,57,1,68>
, emp::numbers<98,81,10,27>
, emp::numbers<70,0,-33,85>
, emp::numbers<2,32,-70,25>
, emp::numbers<71,93,43,47>
, emp::numbers<86,63,-11,57>
, emp::numbers<33,11,-21,32>
, emp::numbers<33,70,28,65>
, emp::numbers<11,44,65,-60>
, emp::numbers<57,22,46,-29>
, emp::numbers<72,40,92,-28>
, emp::numbers<16,58,3,-77>
, emp::numbers<63,58,24,91>
, emp::numbers<52,37,-6,87>
, emp::numbers<39,61,90,-50>
, emp::numbers<88,79,-81,17>
, emp::numbers<19,5,-88,-13>
, emp::numbers<31,81,53,96>
, emp::numbers<27,63,73,-48>
, emp::numbers<82,56,-89,60>
, emp::numbers<44,13,-42,68>
, emp::numbers<35,73,36,-79>
, emp::numbers<1,92,-38,-45>
, emp::numbers<51,31,84,30>
, emp::numbers<48,54,-77,-46>
, emp::numbers<45,82,-80,96>
, emp::numbers<50,38,-36,3>
, emp::numbers<52,87,-70,15>
, emp::numbers<99,26,12,36>
, emp::numbers<11,93,-35,24>
, emp::numbers<40,89,-3,85>
, emp::numbers<24,69,31,-4>
, emp::numbers<53,10,-28,-67>
, emp::numbers<20,10,-40,93>
, emp::numbers<87,53,96,-5>
, emp::numbers<65,85,-85,-53>
, emp::numbers<87,52,-28,-74>
, emp::numbers<56,31,-27,-93>
, emp::numbers<86,9,-87,51>
, emp::numbers<80,31,-83,48>
, emp::numbers<7,101,81,-18>
, emp::numbers<78,97,92,-41>
, emp::numbers<81,15,65,21>
, emp::numbers<87,99,18,-7>
, emp::numbers<94,82,38,65>
, emp::numbers<98,25,89,-6>
, emp::numbers<80,73,94,53>
, emp::numbers<1,29,-26,12>
, emp::numbers<56,60,-90,-34>
, emp::numbers<51,41,-77,22>
, emp::numbers<43,21,29,-93>
, emp::numbers<30,41,-50,-55>
, emp::numbers<87,26,41,-62>
, emp::numbers<99,99,35,-18>
, emp::numbers<95,53,37,-31>
, emp::numbers<78,86,15,96>
, emp::numbers<65,25,-81,10>
, emp::numbers<18,33,55,-32>
, emp::numbers<51,58,97,-57>
, emp::numbers<24,17,59,70>
, emp::numbers<48,69,-28,-84>
, emp::numbers<50,100,-34,-99>
, emp::numbers<29,65,-74,99>
, emp::numbers<26,74,-99,-3>
, emp::numbers<17,97,81,-45>
, emp::numbers<96,66,-60,34>
, emp::numbers<49,14,7,-16>
, emp::numbers<0,78,-15,-57>
, emp::numbers<87,73,-37,42>
, emp::numbers<45,69,25,-38>
, emp::numbers<44,42,-24,22>
, emp::numbers<95,27,-95,-52>
, emp::numbers<5,59,-38,51>
, emp::numbers<13,66,32,84>
, emp::numbers<95,47,-39,-31>
, emp::numbers<87,5,-55,-17>
, emp::numbers<83,80,-60,31>
, emp::numbers<29,80,-22,-61>
, emp::numbers<49,59,99,-92>
, emp::numbers<53,18,-53,48>
, emp::numbers<48,75,-85,52>
, emp::numbers<80,99,-34,-91>
, emp::numbers<87,64,39,-92>
, emp::numbers<91,90,44,83>
, emp::numbers<74,89,83,45>
, emp::numbers<75,85,64,-15>
, emp::numbers<48,82,-25,69>
, emp::numbers<29,79,-29,17>
, emp::numbers<79,50,-81,-73>
, emp::numbers<9,8,-68,74>
, emp::numbers<78,95,-84,1>
, emp::numbers<33,2,56,63>
, emp::numbers<35,49,66,-82>
, emp::numbers<47,64,-65,79>
, emp::numbers<43,5,-49,-45>
, emp::numbers<55,55,-77,-16>
, emp::numbers<14,57,76,57>
, emp::numbers<67,96,19,24>
, emp::numbers<14,62,-50,-86>
, emp::numbers<21,67,31,-65>
, emp::numbers<62,16,96,86>
, emp::numbers<48,41,-9,-73>
, emp::numbers<49,89,-23,-87>
, emp::numbers<82,40,-35,-70>
, emp::numbers<85,52,11,-39>
, emp::numbers<73,69,-59,-88>
, emp::numbers<25,102,30,-48>
, emp::numbers<47,32,-57,44>
, emp::numbers<89,53,-57,-21>
, emp::numbers<43,74,-86,-28>
, emp::numbers<35,72,77,-38>
, emp::numbers<71,29,22,-9>
, emp::numbers<86,50,-84,19>
, emp::numbers<97,25,-28,83>
, emp::numbers<56,33,73,10>
, emp::numbers<6,6,-89,-68>
, emp::numbers<17,63,-62,12>
, emp::numbers<93,23,-14,2>
, emp::numbers<40,21,27,-59>
, emp::numbers<78,50,-9,-16>
, emp::numbers<67,20,4,94>
, emp::numbers<27,58,-55,56>
, emp::numbers<79,0,93,28>
, emp::numbers<30,8,54,59>
, emp::numbers<92,49,71,-13>
, emp::numbers<89,17,-62,-17>
, emp::numbers<44,72,-77,46>
, emp::numbers<46,42,-27,83>
, emp::numbers<64,11,-28,-52>
, emp::numbers<63,53,-8,-61>
, emp::numbers<73,100,-83,51>
, emp::numbers<55,27,22,-5>
, emp::numbers<46,65,46,92>
, emp::numbers<41,53,51,-16>
, emp::numbers<100,90,-4,55>
, emp::numbers<40,39,-98,-9>
, emp::numbers<59,49,-54,53>
, emp::numbers<65,59,-80,-15>
, emp::numbers<24,20,79,26>
, emp::numbers<8,10,80,-25>
, emp::numbers<99,84,88,-87>
, emp::numbers<36,83,-23,-30>
, emp::numbers<64,75,-55,-61>
, emp::numbers<32,42,-99,-5>
, emp::numbers<74,57,41,-1>
, emp::numbers<57,76,65,-75>
, emp::numbers<51,67,-78,-4>
, emp::numbers<89,74,-40,-78>
, emp::numbers<37,41,28,-20>
, emp::numbers<66,26,-57,-74>
, emp::numbers<57,49,22,-92>
, emp::numbers<29,6,29,-83>
, emp::numbers<41,88,51,96>
, emp::numbers<53,24,72,58>
, emp::numbers<4,73,64,57>
, emp::numbers<12,69,26,-46>
, emp::numbers<35,93,42,60>
, emp::numbers<41,49,26,45>
, emp::numbers<59,79,-91,-70>
, emp::numbers<23,87,-45,39>
, emp::numbers<55,32,46,90>
, emp::numbers<19,44,6,72>
, emp::numbers<17,76,80,-27>
, emp::numbers<62,97,-59,24>
, emp::numbers<30,26,93,-66>
, emp::numbers<62,72,95,-61>
, emp::numbers<54,55,71,-16>
, emp::numbers<85,84,-90,78>
, emp::numbers<74,6,69,89>
, emp::numbers<19,45,98,-29>
, emp::numbers<42,84,10,-37>
, emp::numbers<88,84,61,-98>
, emp::numbers<7,17,10,70>
, emp::numbers<23,71,93,88>
, emp::numbers<43,0,29,40>
, emp::numbers<11,34,84,-36>
, emp::numbers<46,76,59,-61>
, emp::numbers<76,46,93,-24>
, emp::numbers<8,93,59,-68>
, emp::numbers<4,2,60,17>
, emp::numbers<84,83,-9,8>
, emp::numbers<25,44,82,98>
, emp::numbers<14,75,49,84>
, emp::numbers<91,97,60,-41>
, emp::numbers<27,14,53,-51>
, emp::numbers<14,7,38,62>
, emp::numbers<6,24,-92,40>
, emp::numbers<36,74,53,88>
, emp::numbers<97,30,62,3>
, emp::numbers<53,86,92,-73>
, emp::numbers<99,14,85,-29>
, emp::numbers<81,1,-24,60>
, emp::numbers<67,96,-16,10>
, emp::numbers<42,75,-83,-87>
, emp::numbers<5,73,29,40>
, emp::numbers<78,36,-87,-54>
, emp::numbers<69,88,35,52>
, emp::numbers<27,38,-96,60>
, emp::numbers<21,0,56,82>
, emp::numbers<67,48,71,-16>
, emp::numbers<97,8,-41,-75>
, emp::numbers<96,64,-96,-93>
, emp::numbers<52,101,-79,9>
>;
