#ifndef UNIT_TEST_KTLT_Management_HPP
#define UNIT_TEST_KTLT_Management_HPP


#include "Warehouse.h"
#include "unit_test.hpp"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() { return func(); })

class UNIT_TEST_KTLT_Management : public UNIT_TEST {
 public:
  UNIT_TEST_KTLT_Management() {
    REGISTER_TEST(Management01);
    REGISTER_TEST(Management02);
    REGISTER_TEST(Management03);
     REGISTER_TEST(Management04);
    REGISTER_TEST(Management05);
;
  }

 private:
   bool Management01();
  bool Management02();
  bool Management03();
  bool Management04();
  bool Management05();
};

#endif  // UNIT_TEST_KTLT_Management_HPP