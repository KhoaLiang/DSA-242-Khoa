#ifndef UNIT_TEST_List1D_HPP
#define UNIT_TEST_List1D_HPP
#include "list/DLinkedList.h"
#include "list/XArrayList.h"
#include "app/List1D.h"
#include "unit_test.hpp"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() { return func(); })

class UNIT_TEST_List1D : public UNIT_TEST
{
public:
  UNIT_TEST_List1D()
  {
    REGISTER_TEST(List1D01);

    REGISTER_TEST(List1D02);

    REGISTER_TEST(List1D03);

    REGISTER_TEST(List1D04);

    REGISTER_TEST(List1D05);

    REGISTER_TEST(List1D06);

    REGISTER_TEST(List1D07);

    REGISTER_TEST(List1D08);

    REGISTER_TEST(List1D09);

    REGISTER_TEST(List1D10);
  }

private:
  bool List1D01();

  bool List1D02();

  bool List1D03();

  bool List1D04();

  bool List1D05();

  bool List1D06();

  bool List1D07();

  bool List1D08();

  bool List1D09();

  bool List1D10();
};

#endif // UNIT_TEST_List1D_HPP
