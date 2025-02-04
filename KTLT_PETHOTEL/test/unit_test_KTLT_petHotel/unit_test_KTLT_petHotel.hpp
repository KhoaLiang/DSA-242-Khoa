#ifndef UNIT_TEST_KTLT_petHotel_HPP
#define UNIT_TEST_KTLT_petHotel_HPP

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "PetHotel.h"
#include "unit_test.hpp"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() { return func(); })

class UNIT_TEST_KTLT_petHotel : public UNIT_TEST {
 public:
  UNIT_TEST_KTLT_petHotel() {
    REGISTER_TEST(petHotel01);
    REGISTER_TEST(petHotel02);
    REGISTER_TEST(petHotel03);
    REGISTER_TEST(petHotel04);
    REGISTER_TEST(petHotel05);
    REGISTER_TEST(petHotel06);
    REGISTER_TEST(petHotel07);
    REGISTER_TEST(petHotel08);
    REGISTER_TEST(petHotel09);
    REGISTER_TEST(petHotel10);
  }

 private:
  bool petHotel01();
  bool petHotel02();
  bool petHotel03();
  bool petHotel04();
  bool petHotel05();
  bool petHotel06();
  bool petHotel07();
  bool petHotel08();
  bool petHotel09();
  bool petHotel10();
};

#endif  // UNIT_TEST_KTLT_petHotel_HPP