/*
 * DSA1 - HK242
 * file : main.cpp
 * Data Structures and Algorithms
 * Author: Võ Tiến
 * Link FB : https://www.facebook.com/Shiba.Vo.Tien
 * Link Group : https://www.facebook.com/groups/khmt.ktmt.cse.bku
 * Date: 05.12.2024

 ! build code : g++ -std=c++17  -o main -Iinclude -Itest main.cpp \
 test/unit_test_KTLT_string/unit_test_KTLT_string.cpp test/unit_test.cpp \
 src/*.cpp test/unit_test_KTLT_string/test_case/*.cpp \
 -DTEST_KTLT_string

 * run code
    !./main test_unit
    !./main test_unit nameFunctionUnitTest
*/

#include "main.hpp"
#ifdef TEST_KTLT_string
#include "unit_test_KTLT_string/unit_test_KTLT_string.hpp"
const string TEST_CASE = "KTLT_string";
#endif
void printTestCase();

int main(int argc, char *argv[]) {
  cout << "-------------------------------------------------------------"
       << endl;
  cout << GREEN << BOLD << "DSA1 - HK242 - VO TIEN" << endl;
  cout << CYAN << BOLD << "Vo Tien : https://www.facebook.com/Shiba.Vo.Tien"
       << endl
       << endl;
  if (argc <= 1) {
    printTestCase();
    return 1;
  }

  std::string arg1 = argv[1];
  if (arg1 == "test_unit") {
    std::cout << GREEN << BOLD << "Running unit_test/unit_test_" << TEST_CASE
              << RESET << "\n";
    handleTestUnit(argc, argv);
  } else {
    printTestCase();
  }
  cout << "-------------------------------------------------------------"
       << endl;
}

#ifdef TEST_KTLT_string
void handleTestUnit(int argc, char *argv[]) {
  UNIT_TEST_KTLT_string unitTest;

  if (argc == 2 || (argc == 3 && std::string(argv[2]) == "all")) {
    unitTest.runAllTests();
  } else if (argc == 3) {
    unitTest.runTest(argv[2]);
  } else {
    printTestCase();
  }
}
#endif

void printTestCase() {
  std::cout << GREEN << BOLD << "terminal unit test" << RESET << std::endl;
  std::cout << RED << "./main test_unit" << RESET << std::endl;
  std::cout << RED << "./main test_unit nameFunctionUnitTest" << RESET
            << std::endl
            << std::endl;
}