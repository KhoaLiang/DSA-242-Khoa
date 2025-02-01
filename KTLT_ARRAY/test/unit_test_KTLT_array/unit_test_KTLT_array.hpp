#ifndef UNIT_TEST_KTLT_array_HPP
#define UNIT_TEST_KTLT_array_HPP

#include "KTLT_array.h"
#include "unit_test.hpp"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() { return func(); })

class UNIT_TEST_KTLT_array : public UNIT_TEST {
 public:
  UNIT_TEST_KTLT_array() {
    // missingNumber
    REGISTER_TEST(missingNumber01);
    REGISTER_TEST(missingNumber02);
    REGISTER_TEST(missingNumber03);
    REGISTER_TEST(missingNumber04);
    REGISTER_TEST(missingNumber05);

    // singleNumber
    REGISTER_TEST(singleNumber01);
    REGISTER_TEST(singleNumber02);
    REGISTER_TEST(singleNumber03);
    REGISTER_TEST(singleNumber04);
    REGISTER_TEST(singleNumber05);

    // findSecondSmallest
    REGISTER_TEST(findSecondSmallest01);
    REGISTER_TEST(findSecondSmallest02);
    REGISTER_TEST(findSecondSmallest03);
    REGISTER_TEST(findSecondSmallest04);
    REGISTER_TEST(findSecondSmallest05);

    // Medium Tests
    // maxSubArray
    REGISTER_TEST(maxSubArray01);
    REGISTER_TEST(maxSubArray02);
    REGISTER_TEST(maxSubArray03);
    REGISTER_TEST(maxSubArray04);
    REGISTER_TEST(maxSubArray05);

    // isMountainArray
    REGISTER_TEST(isMountainArray01);
    REGISTER_TEST(isMountainArray02);
    REGISTER_TEST(isMountainArray03);
    REGISTER_TEST(isMountainArray04);
    REGISTER_TEST(isMountainArray05);

    // findMaxSumSubarray
    REGISTER_TEST(findMaxSumSubarray01);
    REGISTER_TEST(findMaxSumSubarray02);
    REGISTER_TEST(findMaxSumSubarray03);
    REGISTER_TEST(findMaxSumSubarray04);
    REGISTER_TEST(findMaxSumSubarray05);

    // Hard Tests
    // maxAreaOfIsland
    REGISTER_TEST(maxAreaOfIsland01);
    REGISTER_TEST(maxAreaOfIsland02);
    REGISTER_TEST(maxAreaOfIsland03);
    REGISTER_TEST(maxAreaOfIsland04);
    REGISTER_TEST(maxAreaOfIsland05);

    // numberOfClosedIslands
    REGISTER_TEST(numberOfClosedIslands01);
    REGISTER_TEST(numberOfClosedIslands02);
    REGISTER_TEST(numberOfClosedIslands03);
    REGISTER_TEST(numberOfClosedIslands04);
    REGISTER_TEST(numberOfClosedIslands05);
  }

 private:
  // Easy: missingNumber
  bool missingNumber01();
  bool missingNumber02();
  bool missingNumber03();
  bool missingNumber04();
  bool missingNumber05();

  // Easy: singleNumber
  bool singleNumber01();
  bool singleNumber02();
  bool singleNumber03();
  bool singleNumber04();
  bool singleNumber05();

  // Easy: findSecondSmallest
  bool findSecondSmallest01();
  bool findSecondSmallest02();
  bool findSecondSmallest03();
  bool findSecondSmallest04();
  bool findSecondSmallest05();

  // Medium: maxSubArray
  bool maxSubArray01();
  bool maxSubArray02();
  bool maxSubArray03();
  bool maxSubArray04();
  bool maxSubArray05();

  // Medium: isMountainArray
  bool isMountainArray01();
  bool isMountainArray02();
  bool isMountainArray03();
  bool isMountainArray04();
  bool isMountainArray05();

  // Medium: findMaxSumSubarray
  bool findMaxSumSubarray01();
  bool findMaxSumSubarray02();
  bool findMaxSumSubarray03();
  bool findMaxSumSubarray04();
  bool findMaxSumSubarray05();

  // Hard: maxAreaOfIsland
  bool maxAreaOfIsland01();
  bool maxAreaOfIsland02();
  bool maxAreaOfIsland03();
  bool maxAreaOfIsland04();
  bool maxAreaOfIsland05();

  // Hard: numberOfClosedIslands
  bool numberOfClosedIslands01();
  bool numberOfClosedIslands02();
  bool numberOfClosedIslands03();
  bool numberOfClosedIslands04();
  bool numberOfClosedIslands05();
};

#endif  // UNIT_TEST_KTLT_array_HPP