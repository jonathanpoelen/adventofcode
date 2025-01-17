#include <jln/mp/list/list.hpp>
#include <jln/mp/number/numbers.hpp>
using namespace jln::mp;
using input = list<
  emp::numbers<
    12, 57, 
    56, 15, 
    14212, 3815 
  >,
  emp::numbers<
    17, 46, 
    98, 19, 
    3507, 4566 
  >,
  emp::numbers<
    60, 12, 
    23, 41, 
    3236, 2540 
  >,
  emp::numbers<
    13, 99, 
    84, 41, 
    3193, 10546 
  >,
  emp::numbers<
    30, 82, 
    35, 18, 
    2250, 3354 
  >,
  emp::numbers<
    24, 50, 
    60, 18, 
    8624, 9514 
  >,
  emp::numbers<
    26, 17, 
    17, 83, 
    1284, 4290 
  >,
  emp::numbers<
    18, 49, 
    52, 18, 
    16916, 4242 
  >,
  emp::numbers<
    36, 12, 
    18, 77, 
    3834, 6035 
  >,
  emp::numbers<
    53, 34, 
    26, 51, 
    3434, 2958 
  >,
  emp::numbers<
    71, 65, 
    21, 88, 
    2999, 5359 
  >,
  emp::numbers<
    14, 31, 
    91, 42, 
    2639, 1537 
  >,
  emp::numbers<
    43, 11, 
    41, 81, 
    6381, 3069 
  >,
  emp::numbers<
    46, 17, 
    24, 29, 
    3434, 3262 
  >,
  emp::numbers<
    22, 74, 
    50, 11, 
    19706, 6810 
  >,
  emp::numbers<
    46, 42, 
    18, 57, 
    4704, 6810 
  >,
  emp::numbers<
    43, 25, 
    19, 69, 
    3212, 6156 
  >,
  emp::numbers<
    29, 28, 
    22, 86, 
    2112, 2622 
  >,
  emp::numbers<
    25, 50, 
    57, 29, 
    3544, 5518 
  >,
  emp::numbers<
    15, 38, 
    31, 14, 
    11000, 9160 
  >,
  emp::numbers<
    70, 41, 
    14, 32, 
    7070, 6283 
  >,
  emp::numbers<
    22, 51, 
    31, 14, 
    16913, 1950 
  >,
  emp::numbers<
    64, 30, 
    19, 41, 
    17339, 16511 
  >,
  emp::numbers<
    13, 23, 
    44, 25, 
    14067, 1960 
  >,
  emp::numbers<
    56, 99, 
    42, 20, 
    5068, 7983 
  >,
  emp::numbers<
    94, 16, 
    50, 97, 
    9306, 9902 
  >,
  emp::numbers<
    92, 14, 
    56, 63, 
    9880, 5208 
  >,
  emp::numbers<
    44, 13, 
    29, 94, 
    4877, 6994 
  >,
  emp::numbers<
    13, 71, 
    70, 19, 
    3783, 1769 
  >,
  emp::numbers<
    93, 16, 
    70, 59, 
    8034, 3777 
  >,
  emp::numbers<
    27, 80, 
    63, 23, 
    6012, 7175 
  >,
  emp::numbers<
    11, 55, 
    70, 58, 
    4151, 4403 
  >,
  emp::numbers<
    72, 11, 
    12, 49, 
    7808, 4329 
  >,
  emp::numbers<
    13, 57, 
    78, 13, 
    2811, 6304 
  >,
  emp::numbers<
    88, 58, 
    11, 63, 
    1738, 4602 
  >,
  emp::numbers<
    18, 68, 
    74, 11, 
    11520, 10808 
  >,
  emp::numbers<
    11, 36, 
    77, 29, 
    7326, 3906 
  >,
  emp::numbers<
    65, 85, 
    87, 36, 
    9077, 7126 
  >,
  emp::numbers<
    57, 11, 
    11, 70, 
    15132, 13220 
  >,
  emp::numbers<
    60, 32, 
    16, 99, 
    2176, 5322 
  >,
  emp::numbers<
    37, 56, 
    30, 12, 
    17178, 13168 
  >,
  emp::numbers<
    72, 55, 
    21, 97, 
    5094, 8263 
  >,
  emp::numbers<
    89, 13, 
    70, 60, 
    14755, 6635 
  >,
  emp::numbers<
    46, 58, 
    56, 18, 
    3862, 4396 
  >,
  emp::numbers<
    27, 59, 
    50, 11, 
    6611, 1827 
  >,
  emp::numbers<
    29, 77, 
    61, 15, 
    9899, 17595 
  >,
  emp::numbers<
    46, 16, 
    24, 72, 
    3932, 512 
  >,
  emp::numbers<
    88, 13, 
    43, 63, 
    2104, 764 
  >,
  emp::numbers<
    81, 11, 
    57, 87, 
    6786, 2586 
  >,
  emp::numbers<
    18, 72, 
    56, 34, 
    1506, 4884 
  >,
  emp::numbers<
    95, 64, 
    29, 67, 
    5613, 8148 
  >,
  emp::numbers<
    66, 25, 
    19, 79, 
    5923, 3177 
  >,
  emp::numbers<
    11, 39, 
    52, 30, 
    1742, 8240 
  >,
  emp::numbers<
    82, 12, 
    85, 75, 
    9034, 3324 
  >,
  emp::numbers<
    24, 45, 
    31, 18, 
    9352, 16955 
  >,
  emp::numbers<
    11, 43, 
    57, 34, 
    7415, 12413 
  >,
  emp::numbers<
    59, 13, 
    16, 81, 
    2291, 13580 
  >,
  emp::numbers<
    15, 76, 
    79, 16, 
    19462, 10456 
  >,
  emp::numbers<
    66, 21, 
    24, 58, 
    5130, 4503 
  >,
  emp::numbers<
    24, 16, 
    27, 79, 
    3753, 8053 
  >,
  emp::numbers<
    97, 98, 
    20, 90, 
    5539, 9016 
  >,
  emp::numbers<
    43, 22, 
    28, 50, 
    18848, 3622 
  >,
  emp::numbers<
    92, 92, 
    14, 96, 
    9944, 16996 
  >,
  emp::numbers<
    92, 30, 
    37, 59, 
    10392, 6768 
  >,
  emp::numbers<
    70, 12, 
    14, 54, 
    7102, 9098 
  >,
  emp::numbers<
    16, 50, 
    80, 65, 
    2512, 4150 
  >,
  emp::numbers<
    48, 81, 
    67, 22, 
    6742, 8281 
  >,
  emp::numbers<
    22, 58, 
    93, 55, 
    3170, 4934 
  >,
  emp::numbers<
    84, 19, 
    86, 93, 
    6536, 3979 
  >,
  emp::numbers<
    53, 25, 
    17, 29, 
    10118, 1414 
  >,
  emp::numbers<
    30, 56, 
    43, 22, 
    2954, 1220 
  >,
  emp::numbers<
    38, 90, 
    95, 40, 
    5358, 7880 
  >,
  emp::numbers<
    99, 12, 
    18, 40, 
    9630, 4760 
  >,
  emp::numbers<
    41, 26, 
    20, 50, 
    3028, 3898 
  >,
  emp::numbers<
    52, 67, 
    11, 98, 
    3265, 8482 
  >,
  emp::numbers<
    14, 41, 
    57, 27, 
    5839, 7897 
  >,
  emp::numbers<
    22, 67, 
    61, 20, 
    6417, 9556 
  >,
  emp::numbers<
    37, 24, 
    21, 68, 
    4691, 8100 
  >,
  emp::numbers<
    88, 96, 
    13, 92, 
    6182, 8456 
  >,
  emp::numbers<
    67, 39, 
    22, 44, 
    14708, 13146 
  >,
  emp::numbers<
    69, 31, 
    20, 64, 
    4046, 16838 
  >,
  emp::numbers<
    52, 49, 
    15, 96, 
    2010, 4350 
  >,
  emp::numbers<
    17, 62, 
    79, 33, 
    17079, 17948 
  >,
  emp::numbers<
    97, 39, 
    65, 85, 
    8510, 4540 
  >,
  emp::numbers<
    21, 89, 
    98, 51, 
    3836, 7149 
  >,
  emp::numbers<
    22, 69, 
    65, 15, 
    3700, 4265 
  >,
  emp::numbers<
    49, 13, 
    27, 68, 
    15734, 15972 
  >,
  emp::numbers<
    17, 41, 
    46, 32, 
    8438, 3752 
  >,
  emp::numbers<
    79, 54, 
    13, 40, 
    17365, 4550 
  >,
  emp::numbers<
    16, 74, 
    79, 13, 
    5714, 11376 
  >,
  emp::numbers<
    78, 25, 
    31, 83, 
    10011, 10442 
  >,
  emp::numbers<
    21, 75, 
    75, 22, 
    6959, 5453 
  >,
  emp::numbers<
    62, 35, 
    15, 27, 
    5517, 4695 
  >,
  emp::numbers<
    28, 72, 
    54, 13, 
    2408, 4622 
  >,
  emp::numbers<
    23, 70, 
    55, 15, 
    10833, 18120 
  >,
  emp::numbers<
    22, 59, 
    61, 20, 
    2132, 12212 
  >,
  emp::numbers<
    79, 20, 
    19, 73, 
    3217, 6233 
  >,
  emp::numbers<
    87, 80, 
    13, 42, 
    2575, 5102 
  >,
  emp::numbers<
    82, 97, 
    69, 18, 
    3228, 3564 
  >,
  emp::numbers<
    42, 17, 
    31, 62, 
    17600, 6945 
  >,
  emp::numbers<
    25, 37, 
    27, 13, 
    17558, 13118 
  >,
  emp::numbers<
    29, 72, 
    52, 18, 
    19463, 458 
  >,
  emp::numbers<
    18, 44, 
    73, 41, 
    6553, 5985 
  >,
  emp::numbers<
    86, 54, 
    39, 78, 
    8187, 8940 
  >,
  emp::numbers<
    47, 16, 
    19, 60, 
    742, 1652 
  >,
  emp::numbers<
    30, 64, 
    55, 15, 
    15750, 9424 
  >,
  emp::numbers<
    14, 44, 
    56, 25, 
    17336, 8337 
  >,
  emp::numbers<
    22, 99, 
    90, 51, 
    2242, 6549 
  >,
  emp::numbers<
    53, 15, 
    20, 42, 
    14769, 3629 
  >,
  emp::numbers<
    32, 78, 
    42, 13, 
    4234, 4511 
  >,
  emp::numbers<
    27, 73, 
    83, 13, 
    9202, 5430 
  >,
  emp::numbers<
    53, 32, 
    29, 93, 
    2375, 5133 
  >,
  emp::numbers<
    28, 58, 
    51, 28, 
    6187, 5346 
  >,
  emp::numbers<
    15, 31, 
    64, 26, 
    10129, 3111 
  >,
  emp::numbers<
    11, 39, 
    36, 23, 
    19551, 5522 
  >,
  emp::numbers<
    20, 75, 
    61, 19, 
    6457, 15468 
  >,
  emp::numbers<
    13, 74, 
    72, 18, 
    1941, 2820 
  >,
  emp::numbers<
    18, 35, 
    76, 29, 
    7878, 5341 
  >,
  emp::numbers<
    72, 19, 
    60, 69, 
    4668, 4156 
  >,
  emp::numbers<
    27, 38, 
    40, 11, 
    4463, 2114 
  >,
  emp::numbers<
    17, 68, 
    87, 21, 
    1562, 1016 
  >,
  emp::numbers<
    64, 26, 
    12, 70, 
    5376, 3226 
  >,
  emp::numbers<
    78, 63, 
    21, 85, 
    7281, 7990 
  >,
  emp::numbers<
    72, 24, 
    59, 85, 
    5018, 4678 
  >,
  emp::numbers<
    13, 55, 
    70, 15, 
    1665, 3770 
  >,
  emp::numbers<
    31, 96, 
    87, 39, 
    11086, 12441 
  >,
  emp::numbers<
    30, 60, 
    42, 15, 
    19412, 6455 
  >,
  emp::numbers<
    76, 12, 
    12, 85, 
    17016, 16304 
  >,
  emp::numbers<
    58, 14, 
    27, 56, 
    9151, 8908 
  >,
  emp::numbers<
    24, 90, 
    47, 29, 
    3654, 7518 
  >,
  emp::numbers<
    26, 53, 
    54, 22, 
    4656, 15833 
  >,
  emp::numbers<
    78, 57, 
    22, 70, 
    2200, 4897 
  >,
  emp::numbers<
    15, 29, 
    58, 24, 
    5471, 6517 
  >,
  emp::numbers<
    98, 27, 
    43, 76, 
    7983, 3290 
  >,
  emp::numbers<
    61, 20, 
    20, 90, 
    7573, 10410 
  >,
  emp::numbers<
    42, 68, 
    54, 29, 
    386, 955 
  >,
  emp::numbers<
    71, 98, 
    78, 21, 
    13197, 10416 
  >,
  emp::numbers<
    96, 38, 
    21, 84, 
    10857, 9520 
  >,
  emp::numbers<
    62, 66, 
    94, 12, 
    14506, 7428 
  >,
  emp::numbers<
    60, 31, 
    11, 35, 
    10331, 18137 
  >,
  emp::numbers<
    57, 93, 
    70, 32, 
    8231, 9319 
  >,
  emp::numbers<
    91, 72, 
    17, 60, 
    2633, 2316 
  >,
  emp::numbers<
    18, 38, 
    61, 32, 
    14969, 512 
  >,
  emp::numbers<
    44, 17, 
    36, 68, 
    5380, 5310 
  >,
  emp::numbers<
    98, 17, 
    53, 98, 
    10686, 6294 
  >,
  emp::numbers<
    55, 31, 
    50, 92, 
    6400, 6862 
  >,
  emp::numbers<
    96, 74, 
    17, 85, 
    5568, 11194 
  >,
  emp::numbers<
    34, 12, 
    38, 78, 
    9900, 19352 
  >,
  emp::numbers<
    91, 13, 
    79, 69, 
    9464, 6604 
  >,
  emp::numbers<
    12, 70, 
    80, 47, 
    3404, 3070 
  >,
  emp::numbers<
    46, 13, 
    30, 61, 
    10174, 6525 
  >,
  emp::numbers<
    71, 33, 
    21, 97, 
    998, 3430 
  >,
  emp::numbers<
    22, 47, 
    76, 50, 
    9974, 18515 
  >,
  emp::numbers<
    15, 20, 
    71, 29, 
    3480, 2670 
  >,
  emp::numbers<
    80, 77, 
    15, 87, 
    1855, 8824 
  >,
  emp::numbers<
    41, 70, 
    47, 15, 
    8343, 7085 
  >,
  emp::numbers<
    91, 53, 
    30, 83, 
    3673, 7578 
  >,
  emp::numbers<
    86, 94, 
    52, 12, 
    9842, 8426 
  >,
  emp::numbers<
    57, 12, 
    37, 84, 
    5657, 1572 
  >,
  emp::numbers<
    96, 48, 
    11, 18, 
    9294, 5172 
  >,
  emp::numbers<
    73, 56, 
    11, 73, 
    1407, 3339 
  >,
  emp::numbers<
    11, 22, 
    47, 23, 
    8054, 16714 
  >,
  emp::numbers<
    38, 23, 
    14, 39, 
    12668, 5818 
  >,
  emp::numbers<
    83, 28, 
    22, 31, 
    5683, 3827 
  >,
  emp::numbers<
    88, 11, 
    18, 58, 
    3154, 896 
  >,
  emp::numbers<
    75, 51, 
    11, 35, 
    707, 9275 
  >,
  emp::numbers<
    45, 70, 
    69, 14, 
    8886, 6916 
  >,
  emp::numbers<
    49, 17, 
    47, 77, 
    13273, 11885 
  >,
  emp::numbers<
    79, 29, 
    22, 77, 
    8077, 4757 
  >,
  emp::numbers<
    48, 15, 
    33, 51, 
    6807, 5016 
  >,
  emp::numbers<
    92, 16, 
    52, 75, 
    8208, 2153 
  >,
  emp::numbers<
    84, 30, 
    37, 98, 
    1788, 1656 
  >,
  emp::numbers<
    60, 91, 
    89, 32, 
    10221, 8396 
  >,
  emp::numbers<
    26, 50, 
    58, 31, 
    4466, 16784 
  >,
  emp::numbers<
    54, 25, 
    25, 62, 
    17082, 5538 
  >,
  emp::numbers<
    12, 37, 
    60, 53, 
    1308, 2581 
  >,
  emp::numbers<
    29, 19, 
    11, 35, 
    1061, 7527 
  >,
  emp::numbers<
    41, 37, 
    97, 14, 
    7816, 4112 
  >,
  emp::numbers<
    26, 80, 
    99, 41, 
    5754, 7160 
  >,
  emp::numbers<
    42, 29, 
    27, 86, 
    5139, 10082 
  >,
  emp::numbers<
    42, 46, 
    57, 13, 
    3465, 3449 
  >,
  emp::numbers<
    52, 96, 
    67, 35, 
    6802, 4930 
  >,
  emp::numbers<
    22, 47, 
    61, 27, 
    15433, 9291 
  >,
  emp::numbers<
    57, 81, 
    81, 31, 
    4758, 2472 
  >,
  emp::numbers<
    64, 13, 
    24, 69, 
    1680, 2778 
  >,
  emp::numbers<
    68, 15, 
    12, 40, 
    7244, 5825 
  >,
  emp::numbers<
    11, 80, 
    80, 18, 
    8042, 6616 
  >,
  emp::numbers<
    15, 98, 
    99, 18, 
    7272, 7896 
  >,
  emp::numbers<
    22, 43, 
    46, 24, 
    3806, 4664 
  >,
  emp::numbers<
    44, 90, 
    65, 37, 
    5461, 5317 
  >,
  emp::numbers<
    21, 62, 
    59, 11, 
    14054, 8436 
  >,
  emp::numbers<
    15, 88, 
    68, 64, 
    6337, 7368 
  >,
  emp::numbers<
    44, 24, 
    18, 48, 
    7068, 19448 
  >,
  emp::numbers<
    20, 45, 
    64, 43, 
    1724, 1758 
  >,
  emp::numbers<
    31, 74, 
    64, 21, 
    9475, 8615 
  >,
  emp::numbers<
    59, 14, 
    66, 68, 
    6576, 3968 
  >,
  emp::numbers<
    28, 14, 
    15, 39, 
    4301, 15029 
  >,
  emp::numbers<
    33, 34, 
    24, 96, 
    2280, 5984 
  >,
  emp::numbers<
    35, 14, 
    32, 43, 
    17749, 10973 
  >,
  emp::numbers<
    61, 53, 
    17, 87, 
    4325, 9175 
  >,
  emp::numbers<
    59, 15, 
    14, 36, 
    17016, 2144 
  >,
  emp::numbers<
    17, 58, 
    39, 14, 
    17790, 508 
  >,
  emp::numbers<
    18, 58, 
    97, 74, 
    3921, 4762 
  >,
  emp::numbers<
    48, 16, 
    30, 35, 
    5766, 3647 
  >,
  emp::numbers<
    26, 11, 
    40, 63, 
    1616, 8276 
  >,
  emp::numbers<
    87, 41, 
    47, 79, 
    11997, 9747 
  >,
  emp::numbers<
    18, 37, 
    68, 38, 
    14592, 2516 
  >,
  emp::numbers<
    22, 98, 
    45, 42, 
    6235, 12404 
  >,
  emp::numbers<
    81, 52, 
    20, 58, 
    8570, 8392 
  >,
  emp::numbers<
    19, 47, 
    42, 25, 
    2978, 13948 
  >,
  emp::numbers<
    16, 41, 
    45, 31, 
    7050, 3925 
  >,
  emp::numbers<
    60, 23, 
    15, 30, 
    10520, 4953 
  >,
  emp::numbers<
    25, 58, 
    55, 36, 
    6520, 6516 
  >,
  emp::numbers<
    45, 12, 
    46, 74, 
    11032, 18174 
  >,
  emp::numbers<
    62, 53, 
    13, 48, 
    2328, 3318 
  >,
  emp::numbers<
    18, 55, 
    43, 23, 
    14000, 4702 
  >,
  emp::numbers<
    29, 45, 
    32, 14, 
    361, 2419 
  >,
  emp::numbers<
    46, 21, 
    27, 54, 
    9472, 18698 
  >,
  emp::numbers<
    17, 42, 
    75, 23, 
    2577, 1011 
  >,
  emp::numbers<
    70, 63, 
    69, 14, 
    9105, 5068 
  >,
  emp::numbers<
    90, 33, 
    13, 97, 
    3502, 4420 
  >,
  emp::numbers<
    25, 40, 
    38, 17, 
    6711, 9549 
  >,
  emp::numbers<
    78, 44, 
    28, 58, 
    7876, 7144 
  >,
  emp::numbers<
    54, 56, 
    58, 11, 
    2396, 2239 
  >,
  emp::numbers<
    26, 57, 
    42, 24, 
    3734, 2808 
  >,
  emp::numbers<
    29, 11, 
    47, 68, 
    18519, 8721 
  >,
  emp::numbers<
    49, 71, 
    72, 28, 
    5571, 3569 
  >,
  emp::numbers<
    42, 14, 
    34, 51, 
    18090, 7904 
  >,
  emp::numbers<
    42, 42, 
    72, 14, 
    6960, 4466 
  >,
  emp::numbers<
    70, 29, 
    22, 62, 
    10018, 17853 
  >,
  emp::numbers<
    17, 16, 
    22, 75, 
    2685, 7685 
  >,
  emp::numbers<
    85, 23, 
    72, 91, 
    7363, 2636 
  >,
  emp::numbers<
    69, 22, 
    28, 71, 
    6942, 12417 
  >,
  emp::numbers<
    37, 64, 
    44, 12, 
    4914, 3820 
  >,
  emp::numbers<
    68, 52, 
    32, 82, 
    4392, 9054 
  >,
  emp::numbers<
    23, 55, 
    60, 14, 
    7368, 14398 
  >,
  emp::numbers<
    15, 48, 
    56, 48, 
    3381, 6096 
  >,
  emp::numbers<
    96, 21, 
    17, 18, 
    2357, 1044 
  >,
  emp::numbers<
    58, 25, 
    40, 73, 
    4576, 4675 
  >,
  emp::numbers<
    81, 83, 
    16, 64, 
    9072, 13152 
  >,
  emp::numbers<
    66, 20, 
    19, 60, 
    17847, 12420 
  >,
  emp::numbers<
    14, 76, 
    79, 15, 
    10499, 15257 
  >,
  emp::numbers<
    16, 70, 
    97, 51, 
    2993, 6747 
  >,
  emp::numbers<
    73, 34, 
    22, 61, 
    5227, 6241 
  >,
  emp::numbers<
    68, 16, 
    13, 43, 
    19722, 17918 
  >,
  emp::numbers<
    40, 17, 
    27, 67, 
    18624, 9360 
  >,
  emp::numbers<
    43, 40, 
    15, 59, 
    4377, 4432 
  >,
  emp::numbers<
    47, 68, 
    94, 43, 
    3196, 3880 
  >,
  emp::numbers<
    81, 52, 
    13, 40, 
    18712, 2644 
  >,
  emp::numbers<
    71, 20, 
    54, 71, 
    6311, 2503 
  >,
  emp::numbers<
    50, 16, 
    15, 31, 
    13350, 8128 
  >,
  emp::numbers<
    61, 16, 
    78, 83, 
    11083, 8223 
  >,
  emp::numbers<
    23, 37, 
    46, 20, 
    18937, 4341 
  >,
  emp::numbers<
    45, 17, 
    54, 93, 
    5247, 5467 
  >,
  emp::numbers<
    91, 52, 
    21, 88, 
    3353, 9440 
  >,
  emp::numbers<
    11, 35, 
    70, 38, 
    12575, 2599 
  >,
  emp::numbers<
    40, 23, 
    22, 38, 
    4572, 7330 
  >,
  emp::numbers<
    34, 59, 
    51, 29, 
    14558, 4320 
  >,
  emp::numbers<
    63, 19, 
    20, 72, 
    13945, 7281 
  >,
  emp::numbers<
    17, 46, 
    45, 20, 
    3806, 12178 
  >,
  emp::numbers<
    14, 35, 
    45, 29, 
    12968, 4771 
  >,
  emp::numbers<
    38, 16, 
    12, 33, 
    11866, 1245 
  >,
  emp::numbers<
    13, 61, 
    34, 37, 
    2072, 6659 
  >,
  emp::numbers<
    57, 41, 
    29, 83, 
    3206, 4046 
  >,
  emp::numbers<
    22, 66, 
    66, 28, 
    8746, 2528 
  >,
  emp::numbers<
    72, 21, 
    15, 94, 
    5076, 4707 
  >,
  emp::numbers<
    15, 64, 
    68, 25, 
    11124, 1417 
  >,
  emp::numbers<
    27, 80, 
    82, 34, 
    3377, 3946 
  >,
  emp::numbers<
    46, 70, 
    94, 38, 
    10856, 9272 
  >,
  emp::numbers<
    73, 14, 
    12, 61, 
    7045, 18795 
  >,
  emp::numbers<
    18, 51, 
    65, 28, 
    15231, 15784 
  >,
  emp::numbers<
    15, 46, 
    75, 39, 
    2895, 5249 
  >,
  emp::numbers<
    64, 53, 
    95, 15, 
    14909, 6043 
  >,
  emp::numbers<
    91, 31, 
    27, 34, 
    3457, 2765 
  >,
  emp::numbers<
    73, 27, 
    16, 55, 
    18944, 3264 
  >,
  emp::numbers<
    59, 86, 
    80, 32, 
    4048, 3616 
  >,
  emp::numbers<
    51, 16, 
    39, 68, 
    1004, 1332 
  >,
  emp::numbers<
    36, 11, 
    39, 63, 
    16187, 17368 
  >,
  emp::numbers<
    17, 30, 
    63, 31, 
    5166, 3905 
  >,
  emp::numbers<
    83, 37, 
    18, 88, 
    6398, 3252 
  >,
  emp::numbers<
    17, 60, 
    48, 29, 
    1107, 818 
  >,
  emp::numbers<
    36, 17, 
    26, 51, 
    14926, 17397 
  >,
  emp::numbers<
    53, 11, 
    32, 59, 
    5039, 4868 
  >,
  emp::numbers<
    53, 94, 
    80, 37, 
    12182, 12166 
  >,
  emp::numbers<
    14, 55, 
    76, 23, 
    3132, 2977 
  >,
  emp::numbers<
    64, 84, 
    30, 12, 
    8956, 10976 
  >,
  emp::numbers<
    82, 66, 
    16, 45, 
    6990, 6654 
  >,
  emp::numbers<
    22, 22, 
    68, 13, 
    4858, 1943 
  >,
  emp::numbers<
    31, 72, 
    61, 17, 
    6507, 7009 
  >,
  emp::numbers<
    62, 55, 
    19, 62, 
    1727, 4015 
  >,
  emp::numbers<
    34, 51, 
    97, 47, 
    1160, 1149 
  >,
  emp::numbers<
    23, 89, 
    78, 42, 
    5451, 3165 
  >,
  emp::numbers<
    25, 75, 
    71, 14, 
    3992, 6603 
  >,
  emp::numbers<
    80, 11, 
    17, 84, 
    1730, 14714 
  >,
  emp::numbers<
    88, 12, 
    61, 66, 
    3142, 1236 
  >,
  emp::numbers<
    16, 81, 
    69, 48, 
    5643, 9585 
  >,
  emp::numbers<
    16, 58, 
    49, 13, 
    5657, 8699 
  >,
  emp::numbers<
    24, 75, 
    47, 21, 
    5888, 7323 
  >,
  emp::numbers<
    91, 29, 
    39, 58, 
    1482, 1885 
  >,
  emp::numbers<
    12, 68, 
    24, 27, 
    660, 3304 
  >,
  emp::numbers<
    18, 15, 
    22, 77, 
    1278, 1593 
  >,
  emp::numbers<
    62, 18, 
    25, 61, 
    7461, 6065 
  >,
  emp::numbers<
    77, 24, 
    83, 99, 
    8910, 4386 
  >,
  emp::numbers<
    19, 64, 
    56, 23, 
    565, 1075 
  >,
  emp::numbers<
    95, 53, 
    26, 74, 
    6101, 5843 
  >,
  emp::numbers<
    92, 22, 
    38, 70, 
    8148, 6456 
  >,
  emp::numbers<
    75, 31, 
    11, 33, 
    17592, 16140 
  >,
  emp::numbers<
    21, 94, 
    63, 63, 
    2037, 4738 
  >,
  emp::numbers<
    46, 19, 
    16, 38, 
    3836, 2432 
  >,
  emp::numbers<
    93, 28, 
    13, 21, 
    5256, 1890 
  >,
  emp::numbers<
    36, 75, 
    80, 43, 
    7996, 4910 
  >,
  emp::numbers<
    49, 60, 
    46, 12, 
    2817, 1632 
  >,
  emp::numbers<
    21, 32, 
    73, 34, 
    5481, 3486 
  >,
  emp::numbers<
    60, 40, 
    11, 67, 
    2172, 5744 
  >,
  emp::numbers<
    17, 60, 
    51, 22, 
    13810, 1748 
  >,
  emp::numbers<
    69, 15, 
    13, 40, 
    10017, 12420 
  >,
  emp::numbers<
    30, 59, 
    63, 29, 
    16784, 14306 
  >,
  emp::numbers<
    56, 17, 
    33, 61, 
    5469, 5178 
  >,
  emp::numbers<
    73, 25, 
    11, 66, 
    7120, 10367 
  >,
  emp::numbers<
    36, 76, 
    56, 12, 
    19412, 2980 
  >
>;
