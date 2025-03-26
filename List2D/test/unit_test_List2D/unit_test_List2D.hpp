#ifndef UNIT_TEST_List2D_HPP
#define UNIT_TEST_List2D_HPP

#include"list/DLinkedList.h"
#include"list/XArrayList.h"
#include "app/List2D.h"
#include "unit_test.hpp"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() { return func(); })

class UNIT_TEST_List2D : public UNIT_TEST
{
public:
  UNIT_TEST_List2D()
  {
    REGISTER_TEST(List2D01);
    REGISTER_TEST(List2D02);
    REGISTER_TEST(List2D03);
    REGISTER_TEST(List2D04);
    REGISTER_TEST(List2D05);
    REGISTER_TEST(List2D06);
    REGISTER_TEST(List2D07);
    REGISTER_TEST(List2D08);
    REGISTER_TEST(List2D09);
    REGISTER_TEST(List2D10);
  }

private:
  bool List2D01();
  bool List2D02();
  bool List2D03();
  bool List2D04();
  bool List2D05();
  bool List2D06();
  bool List2D07();
  bool List2D08();
  bool List2D09();
  bool List2D10();
};

#endif // UNIT_TEST_List2D_HPP
