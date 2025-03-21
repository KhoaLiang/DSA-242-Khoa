#ifndef UNIT_TEST_XArrayList_HPP
#define UNIT_TEST_XArrayList_HPP

#include"util/Point.h"
#include "list/XArrayList.h"
#include "unit_test.hpp"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() { return func(); })

class UNIT_TEST_XArrayList : public UNIT_TEST
{
public:
  UNIT_TEST_XArrayList()
  {
    REGISTER_TEST(XArrayList01);

    REGISTER_TEST(XArrayList02);

    REGISTER_TEST(XArrayList03);

    REGISTER_TEST(XArrayList04);

    REGISTER_TEST(XArrayList05);

    REGISTER_TEST(XArrayList06);

    REGISTER_TEST(XArrayList07);

    REGISTER_TEST(XArrayList08);

    REGISTER_TEST(XArrayList09);

    REGISTER_TEST(XArrayList10);

    REGISTER_TEST(XArrayList11);

    REGISTER_TEST(XArrayList12);

    REGISTER_TEST(XArrayList13);

    REGISTER_TEST(XArrayList14);

    REGISTER_TEST(XArrayList15);

    REGISTER_TEST(XArrayList16);

    REGISTER_TEST(XArrayList17);

    REGISTER_TEST(XArrayList18);

    REGISTER_TEST(XArrayList19);

    REGISTER_TEST(XArrayList20);

    REGISTER_TEST(XArrayList21);

    REGISTER_TEST(XArrayList22);

    REGISTER_TEST(XArrayList23);

    REGISTER_TEST(XArrayList24);

    REGISTER_TEST(XArrayList25);

    REGISTER_TEST(XArrayList26);

    REGISTER_TEST(XArrayList27);

    REGISTER_TEST(XArrayList28);

    REGISTER_TEST(XArrayList29);

    REGISTER_TEST(XArrayList30);

    REGISTER_TEST(XArrayList31);

    REGISTER_TEST(XArrayList32);

    REGISTER_TEST(XArrayList33);

    REGISTER_TEST(XArrayList34);

    REGISTER_TEST(XArrayList35);

    REGISTER_TEST(XArrayList36);

    REGISTER_TEST(XArrayList37);

    REGISTER_TEST(XArrayList38);

    REGISTER_TEST(XArrayList39);
  }

private:
  bool XArrayList01();

  bool XArrayList02();

  bool XArrayList03();

  bool XArrayList04();

  bool XArrayList05();

  bool XArrayList06();

  bool XArrayList07();

  bool XArrayList08();

  bool XArrayList09();

  bool XArrayList10();

  bool XArrayList11();

  bool XArrayList12();

  bool XArrayList13();

  bool XArrayList14();

  bool XArrayList15();

  bool XArrayList16();

  bool XArrayList17();

  bool XArrayList18();

  bool XArrayList19();

  bool XArrayList20();

  bool XArrayList21();

  bool XArrayList22();

  bool XArrayList23();

  bool XArrayList24();

  bool XArrayList25();

  bool XArrayList26();

  bool XArrayList27();

  bool XArrayList28();

  bool XArrayList29();

  bool XArrayList30();

  bool XArrayList31();

  bool XArrayList32();

  bool XArrayList33();

  bool XArrayList34();

  bool XArrayList35();

  bool XArrayList36();

  bool XArrayList37();

  bool XArrayList38();

  bool XArrayList39();
};

#endif // UNIT_TEST_XArrayList_HPP
