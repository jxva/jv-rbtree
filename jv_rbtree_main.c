#include <jv_rbtree.h>

jv_uint_t tiny[] = {4, 9, 7, 13, 14, 2, 12, 8, 5, 0};
jv_uint_t lump[] = {54, 90, 82, 43, 31, 92, 96, 74, 8,  18, 92, 98, 67, 89, 41, 13, 46, 47, 93, 45, 88, 77, 59, 38, 2,  93,
                    38, 36, 13, 40, 14, 42, 45, 79, 15, 24, 58, 87, 91, 22, 23, 7,  61, 99, 72, 5,  22, 82, 79, 62, 25, 86,
                    1,  31, 52, 89, 27, 40, 84, 15, 90, 14, 44, 52, 70, 53, 94, 42, 56, 94, 52, 42, 79, 83, 14, 31, 76, 30,
                    6,  9,  83, 98, 96, 41, 7,  51, 54, 38, 63, 13, 76, 99, 44, 28, 79, 41, 53, 51, 62, 34, 0};
jv_uint_t huge[] = {
    865, 924, 943, 880, 181, 396, 600, 507, 260, 477, 315, 487, 50,  359, 373, 737, 244, 889, 33,  503, 28,  938, 729, 139, 481, 637, 917, 904, 965,
    190, 425, 173, 831, 490, 556, 878, 948, 467, 986, 817, 470, 192, 768, 661, 923, 264, 479, 546, 88,  903, 322, 923, 771, 788, 539, 184, 563, 97,
    672, 327, 650, 826, 627, 714, 176, 809, 949, 939, 78,  787, 832, 498, 187, 0,   694, 461, 239, 535, 765, 972, 137, 468, 252, 432, 761, 52,  178,
    661, 310, 369, 72,  860, 190, 280, 814, 547, 255, 656, 132, 132, 301, 890, 310, 549, 574, 396, 680, 861, 200, 966, 550, 730, 158, 181, 764, 776,
    797, 232, 188, 829, 918, 647, 944, 938, 382, 651, 238, 717, 540, 838, 405, 657, 414, 886, 226, 639, 475, 724, 456, 613, 803, 256, 805, 929, 197,
    648, 953, 701, 48,  858, 346, 758, 535, 216, 428, 600, 712, 937, 498, 462, 839, 415, 942, 703, 863, 793, 977, 163, 749, 2,   19,  951, 544, 540,
    794, 331, 870, 999, 834, 274, 46,  250, 540, 253, 452, 445, 936, 300, 953, 125, 990, 58,  827, 527, 67,  887, 509, 850, 602, 64,  158, 245, 633,
    475, 538, 41,  126, 291, 529, 569, 404, 686, 445, 690, 142, 894, 82,  234, 635, 262, 125, 789, 277, 557, 977, 759, 366, 657, 628, 975, 549, 939,
    177, 671, 365, 116, 27,  911, 659, 321, 45,  573, 730, 82,  148, 404, 4,   672, 698, 812, 900, 447, 989, 473, 20,  857, 338, 231, 395, 490, 136,
    319, 655, 83,  217, 132, 244, 372, 265, 377, 723, 793, 903, 242, 597, 493, 297, 648, 902, 557, 997, 559, 382, 128, 479, 346, 460, 983, 383, 800,
    960, 19,  574, 830, 898, 517, 666, 132, 200, 473, 899, 2,   84,  475, 532, 210, 623, 283, 538, 717, 632, 138, 803, 587, 777, 408, 23,  141, 37,
    776, 193, 161, 989, 266, 393, 342, 190, 420, 506, 114, 381, 231, 396, 334, 897, 674, 228, 176, 388, 745, 145, 875, 110, 754, 985, 232, 69,  238,
    488, 17,  899, 654, 316, 528, 192, 731, 833, 160, 607, 314, 885, 717, 143, 965, 554, 792, 784, 568, 763, 495, 324, 852, 260, 760, 468, 236, 767,
    848, 36,  459, 821, 387, 537, 86,  46,  793, 995, 605, 460, 710, 402, 260, 727, 579, 739, 167, 78,  467, 251, 657, 273, 364, 166, 2,   166, 168,
    592, 443, 747, 352, 812, 164, 985, 309, 921, 597, 555, 665, 65,  936, 296, 397, 146, 208, 796, 421, 884, 418, 92,  483, 752, 168, 749, 231, 534,
    607, 474, 947, 920, 468, 956, 417, 689, 871, 643, 700, 698, 394, 412, 837, 898, 358, 226, 121, 542, 446, 360, 784, 255, 706, 449, 322, 853, 516,
    640, 253, 127, 815, 467, 827, 472, 77,  581, 815, 201, 381, 703, 686, 502, 322, 54,  870, 185, 147, 13,  969, 533, 122, 790, 272, 150, 688, 890,
    286, 568, 951, 21,  279, 940, 785, 291, 608, 183, 359, 157, 363, 948, 813, 795, 271, 170, 734, 908, 217, 855, 122, 718, 671, 157, 260, 273, 641,
    407, 654, 350, 23,  202, 12,  670, 881, 885, 999, 468, 259, 616, 44,  811, 133, 727, 664, 434, 853, 227, 698, 840, 10,  377, 12,  844, 359, 600,
    742, 55,  395, 304, 323, 209, 446, 958, 443, 724, 476, 414, 291, 908, 829, 724, 948, 245, 352, 758, 390, 785, 179, 465, 538, 417, 439, 799, 331,
    22,  146, 671, 827, 568, 503, 220, 416, 758, 490, 514, 731, 265, 3,   44,  247, 203, 373, 123, 123, 629, 282, 589, 388, 197, 25,  441, 205, 968,
    656, 960, 39,  325, 912, 47,  736, 178, 354, 925, 783, 839, 836, 47,  53,  146, 842, 634, 136, 800, 332, 123, 21,  515, 55,  252, 709, 727, 94,
    835, 502, 311, 521, 42,  322, 89,  145, 119, 979, 420, 578, 670, 202, 869, 133, 127, 464, 972, 960, 218, 892, 818, 199, 72,  345, 348, 7,   344,
    852, 613, 149, 652, 275, 23,  817, 697, 336, 337, 600, 59,  874, 120, 816, 968, 637, 272, 710, 739, 205, 887, 613, 642, 556, 515, 297, 754, 627,
    111, 785, 730, 173, 790, 429, 136, 468, 74,  819, 304, 468, 756, 557, 305, 318, 137, 362, 408, 795, 611, 15,  349, 848, 801, 757, 350, 278, 584,
    292, 788, 202, 158, 243, 823, 329, 18,  910, 742, 530, 226, 336, 45,  486, 550, 494, 353, 4,   290, 449, 628, 740, 167, 765, 935, 943, 80,  505,
    829, 101, 110, 301, 231, 50,  47,  468, 967, 646, 907, 704, 134, 953, 339, 805, 273, 132, 958, 284, 417, 420, 796, 61,  371, 906, 49,  236, 384,
    515, 218, 597, 337, 228, 751, 252, 925, 268, 521, 574, 178, 219, 126, 135, 58,  35,  277, 343, 839, 945, 195, 632, 669, 243, 550, 673, 913, 920,
    259, 421, 742, 770, 338, 307, 376, 939, 66,  261, 440, 929, 432, 57,  558, 31,  776, 179, 367, 314, 689, 682, 590, 612, 53,  657, 483, 20,  526,
    763, 965, 489, 430, 418, 427, 173, 655, 964, 921, 59,  233, 440, 9,   413, 416, 549, 875, 230, 439, 516, 383, 233, 581, 8,   690, 316, 986, 867,
    916, 676, 979, 770, 441, 508, 312, 455, 278, 323, 160, 318, 835, 70,  772, 850, 957, 575, 54,  660, 409, 858, 694, 796, 28,  494, 132, 75,  834,
    42,  784, 479, 62,  810, 219, 827, 487, 931, 735, 876, 100, 209, 245, 838, 865, 917, 492, 526, 754, 838, 920, 674, 153, 813, 973, 240, 41,  687,
    612, 827, 165, 226, 864, 452, 852, 37,  70,  352, 390, 888, 874, 606, 738, 675, 267, 28,  668, 60,  236, 983, 902, 534, 738, 592, 117, 554, 164,
    56,  509, 535, 34,  370, 102, 323, 939, 209, 711, 47,  263, 988, 800, 589, 504, 414, 545, 731, 763, 117, 58,  915, 299, 418, 454, 625, 216, 585,
    479, 568, 779, 942, 774, 692, 858, 977, 81,  121, 894, 393, 53,  0};



void test1(void) {
  jv_rbtree_t *tree = jv_rbtree_create();

  /*
   41,38,31,12,19,8
   82,76,68,50,25,10,8
   12,1,9,2,11,7,19,4,15,18,5,14,13,10,16,6,3,8,17
   13,2,10,3,1,12,8,20,5,16,19,6,15,14,11,17,7,4,9,18
   1,2,4,5,7,8,11,14,15
   11,2,14,1,7,15,5,8,4
   1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16
   */

  jv_int_t arr[] = {13, 2, 10, 3, 1, 12, 8, 20, 5, 16, 19, 6, 15, 14, 11, 17, 7, 4, 9, 18, 0};
  jv_int_t *a = arr;

  while (*a != 0) {
    jv_rbtree_data_t data;

    data.key = *a;
    data.value = (void *) *a;

    printf("insert value:%lu\n", data.key);
    jv_rbtree_insert(tree, &data);
    a++;
  }
  printf("--------------------------traverse 1-----------------------------\n");
  jv_rbtree_inorder(tree->root, tree->sentinel);

  printf("--------------------------remove 38-----------------------------\n");
  printf("min:%lu\n", jv_rbtree_min(tree->root, tree->sentinel)->data->key);
  printf("max:%lu\n", jv_rbtree_max(tree->root, tree->sentinel)->data->key);
  /* 8,12,19,31,38,41 */
  jv_rbtree_remove(tree, jv_rbtree_get(tree, 38));
  jv_rbtree_inorder(tree->root, tree->sentinel);

  printf("--------------------------remove 31-----------------------------\n");
  printf("min:%lu\n", jv_rbtree_min(tree->root, tree->sentinel)->data->key);
  printf("max:%lu\n", jv_rbtree_max(tree->root, tree->sentinel)->data->key);
  /* 8,12,19,31,38,41 */
  jv_rbtree_remove(tree, jv_rbtree_get(tree, 31));
  jv_rbtree_inorder(tree->root, tree->sentinel);

  printf("--------------------------remove 41-----------------------------\n");
  printf("min:%lu\n", jv_rbtree_min(tree->root, tree->sentinel)->data->key);
  printf("max:%lu\n", jv_rbtree_max(tree->root, tree->sentinel)->data->key);
  /* 8,12,19,31,38,41 */
  jv_rbtree_remove(tree, jv_rbtree_get(tree, 41));
  jv_rbtree_inorder(tree->root, tree->sentinel);

  printf("--------------------------remove 8-----------------------------\n");
  /* 8,12,19,31,38,41 */
  printf("min:%lu\n", jv_rbtree_min(tree->root, tree->sentinel)->data->key);
  printf("max:%lu\n", jv_rbtree_max(tree->root, tree->sentinel)->data->key);
  jv_rbtree_remove(tree, jv_rbtree_get(tree, 8));
  jv_rbtree_inorder(tree->root, tree->sentinel);

  printf("--------------------------remove 12-----------------------------\n");
  printf("min:%lu\n", jv_rbtree_min(tree->root, tree->sentinel)->data->key);
  printf("max:%lu\n", jv_rbtree_max(tree->root, tree->sentinel)->data->key);
  /* 8,12,19,31,38,41 */
  jv_rbtree_remove(tree, jv_rbtree_get(tree, 12));
  jv_rbtree_inorder(tree->root, tree->sentinel);

  printf("--------------------------remove 19-----------------------------\n");
  printf("min:%lu\n", jv_rbtree_min(tree->root, tree->sentinel)->data->key);
  printf("max:%lu\n", jv_rbtree_max(tree->root, tree->sentinel)->data->key);
  /* 8,12,19,31,38,41 */
  jv_rbtree_remove(tree, jv_rbtree_get(tree, 19));
  jv_rbtree_inorder(tree->root, tree->sentinel);

  jv_rbtree_destroy(tree);
}

void test2(void) {
  jv_rbtree_t *tree = jv_rbtree_create();

  /*
   41,38,31,12,19,8
   82,76,68,50,25,10,8
   12,1,9,2,11,7,19,4,15,18,5,14,13,10,16,6,3,8,17
   13,2,10,3,1,12,8,20,5,16,19,6,15,14,11,17,7,4,9,18
   1,2,4,5,7,8,11,14,15
   11,2,14,1,7,15,5,8,4
   1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16

   */

  /* jv_uint_t arr[] = { 6,3,2,5,3,5,1,2,4, 0 }; */
  jv_uint_t *a = huge;

  while (*a != 0) {
    jv_rbtree_data_t data;

    data.key = *a;
    data.value = (void *) *a;

    printf("insert value:%lu\n", data.key);
    jv_rbtree_insert(tree, &data);
    a++;
  }

  printf("min:%lu\n", jv_rbtree_min(tree->root, tree->sentinel)->data->key);
  printf("max:%lu\n", jv_rbtree_max(tree->root, tree->sentinel)->data->key);
  printf("depth:%lu\n", jv_rbtree_depth(tree->root, tree->sentinel));
  printf("length:%lu\n", tree->length);

  printf("--------------------------traverse 1-----------------------------\n");
  jv_rbtree_inorder(tree->root, tree->sentinel);

  printf("--------------------------remove 14-----------------------------\n");
  /* 11,2,14,1,7,15,5,8,4 */
  jv_rbtree_remove(tree, jv_rbtree_get(tree, 7));
  jv_rbtree_inorder(tree->root, tree->sentinel);

  jv_rbtree_destroy(tree);
}

void test3(void) {
  jv_rbtree_t *tree = jv_rbtree_create();
  jv_uint_t arr[] = { 6,3,2,5,3,5,1,2,4, 0 }; 
  jv_uint_t *a=arr;

  while (*a != 0) {
    jv_rbtree_data_t data;

    data.key = *a;
    data.value = (void *) *a;

    printf("insert value:%lu\n", data.key);
    jv_rbtree_insert(tree, &data);
    a++;
  }

  printf("min:%lu\n", jv_rbtree_min(tree->root, tree->sentinel)->data->key);
  printf("max:%lu\n", jv_rbtree_max(tree->root, tree->sentinel)->data->key);
  printf("depth:%lu\n", jv_rbtree_depth(tree->root, tree->sentinel));
  printf("length:%lu\n", tree->length);

  jv_rbtree_inorder(tree->root, tree->sentinel);

  jv_rbtree_remove(tree, jv_rbtree_get(tree, 7));
  jv_rbtree_inorder(tree->root, tree->sentinel);

  jv_rbtree_destroy(tree);
}

int main(int argc, char *argv[]) {
  test1();
  test2();
  test3();
  return 0;
}