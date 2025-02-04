#ifndef UNIT_TEST_KTLT_string_HPP
#define UNIT_TEST_KTLT_string_HPP

#include "KTLT_string.h"
#include "unit_test.hpp"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() { return func(); })

class UNIT_TEST_KTLT_string : public UNIT_TEST {
 public:
  UNIT_TEST_KTLT_string() {
    // isPalindrome
    REGISTER_TEST(isPalindrome01);
    REGISTER_TEST(isPalindrome02);
    REGISTER_TEST(isPalindrome03);
    REGISTER_TEST(isPalindrome04);
    REGISTER_TEST(isPalindrome05);

    // encodeASCII
    REGISTER_TEST(encodeASCII01);
    REGISTER_TEST(encodeASCII02);
    REGISTER_TEST(encodeASCII03);
    REGISTER_TEST(encodeASCII04);
    REGISTER_TEST(encodeASCII05);

    // removeConsecutiveDuplicates
    REGISTER_TEST(removeConsecutiveDuplicates01);
    REGISTER_TEST(removeConsecutiveDuplicates02);
    REGISTER_TEST(removeConsecutiveDuplicates03);
    REGISTER_TEST(removeConsecutiveDuplicates04);
    REGISTER_TEST(removeConsecutiveDuplicates05);

    // runLengthEncoding
    REGISTER_TEST(runLengthEncoding01);
    REGISTER_TEST(runLengthEncoding02);
    REGISTER_TEST(runLengthEncoding03);
    REGISTER_TEST(runLengthEncoding04);
    REGISTER_TEST(runLengthEncoding05);

    // sumOfIntegersInString
    REGISTER_TEST(sumOfIntegersInString01);
    REGISTER_TEST(sumOfIntegersInString02);
    REGISTER_TEST(sumOfIntegersInString03);
    REGISTER_TEST(sumOfIntegersInString04);
    REGISTER_TEST(sumOfIntegersInString05);

    // countSubsequences
    REGISTER_TEST(countSubsequences01);
    REGISTER_TEST(countSubsequences02);
    REGISTER_TEST(countSubsequences03);
    REGISTER_TEST(countSubsequences04);
    REGISTER_TEST(countSubsequences05);
  }

 private:
  // --------------------- isPalindrome ---------------------
  bool isPalindrome01();
  bool isPalindrome02();
  bool isPalindrome03();
  bool isPalindrome04();
  bool isPalindrome05();

  // --------------------- encodeASCII ----------------------
  bool encodeASCII01();
  bool encodeASCII02();
  bool encodeASCII03();
  bool encodeASCII04();
  bool encodeASCII05();

  // ------------- removeConsecutiveDuplicates -------------
  bool removeConsecutiveDuplicates01();
  bool removeConsecutiveDuplicates02();
  bool removeConsecutiveDuplicates03();
  bool removeConsecutiveDuplicates04();
  bool removeConsecutiveDuplicates05();

  // ------------------ runLengthEncoding -------------------
  bool runLengthEncoding01();
  bool runLengthEncoding02();
  bool runLengthEncoding03();
  bool runLengthEncoding04();
  bool runLengthEncoding05();

  // ----------------- sumOfIntegersInString ----------------
  bool sumOfIntegersInString01();
  bool sumOfIntegersInString02();
  bool sumOfIntegersInString03();
  bool sumOfIntegersInString04();
  bool sumOfIntegersInString05();

  // ----------------- countSubsequences --------------------
  bool countSubsequences01();
  bool countSubsequences02();
  bool countSubsequences03();
  bool countSubsequences04();
  bool countSubsequences05();
};

#endif  // UNIT_TEST_KTLT_string_HPP