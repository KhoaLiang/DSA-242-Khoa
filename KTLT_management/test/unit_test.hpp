#ifndef UNIT_TEST_HPP
#define UNIT_TEST_HPP

#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class UNIT_TEST {
 public:
  UNIT_TEST() = default;
  virtual ~UNIT_TEST() = default;

  // Static map to store test names and their corresponding member function
  // pointers
  static map<string, function<bool()>> TESTS;

  // Static method to register a test
  static void registerTest(const string& name,
                           const function<bool()>& function) {
    if (TESTS.find(name) != TESTS.end()) {
      throw runtime_error("Test with name '" + name + "' already exists.");
    }
    TESTS[name] = function;
  }

  // Method to run all registered tests
  static void runTests() {
    for (const auto& [name, test] : TESTS) {
      try {
        test();
      } catch (const exception& e) {
        cout << "ERROR: " << e.what() << endl;
      }
    }
  }

  // ANSI escape codes for colors
  inline static const string green = "\033[32m";
  inline static const string red = "\033[31m";
  inline static const string cyan = "\033[36m";
  inline static const string reset = "\033[0m";  // To reset to default color
  inline static const string BOLD = "\033[1m";

  // Print test result
  bool printResult(const string& output, const string& expect,
                   const string& name) {
    if (expect == output) {
      cout << green << "Test " + name + " --------------- PASS" << reset
           << "\n";
      return true;
    } else {
      cout << red << "Test " + name + " --------------- FAIL" << reset << "\n";
      cout << " Expected: " << expect << endl;
      cout << " Output  : " << output << endl;
      return false;
    }
  }

  // Run a single test case
  void runTest(const string& name) {
    auto it = TESTS.find(name);
    if (it != TESTS.end()) {
      try {
        if (!it->second()) {
          throw runtime_error("Test failed.");
        }
      } catch (const exception& e) {
        cout << red << "Test '" << name << "' ERROR: " << e.what() << reset
             << endl;
      }
    } else {
      throw runtime_error("Test with name '" + name + "' does not exist.");
    }
  }

  // Run all test cases
  void runAllTests() {
    vector<string> fails;
    for (const auto& [name, test] : TESTS) {
      try {
        if (!test()) {
          fails.push_back(name);
        }
      } catch (const exception& e) {
        fails.push_back(name);
        cout << red << "ERROR: " << e.what() << reset << endl;
      }
    }

    cout << cyan << BOLD << "\n------------- Test Results ----------" << reset
         << endl;
    if (fails.empty()) {
      cout << green << BOLD << "All tests passed!" << reset << endl;
    } else {
      int totalTests = TESTS.size();
      int failedTests = fails.size();
      int passedTests = totalTests - failedTests;
      double passRate = (static_cast<double>(passedTests) / totalTests) * 100.0;

      cout << red << BOLD << "Some tests failed:" << endl;
      for (const auto& fail : fails) {
        cout << "   " << fail << endl;
      }
      cout << reset;
      cout << green << BOLD << "Pass rate: " << passRate << "%" << reset
           << endl;
    }
  }
};

#endif  // UNIT_TEST_HPP