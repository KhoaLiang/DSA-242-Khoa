#ifndef UNIT_TEST_DLinkedList_HPP
#define UNIT_TEST_DLinkedList_HPP
#include "util/Point.h"
#include "list/DLinkedList.h"
#include "unit_test.hpp"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() { return func(); })

class UNIT_TEST_DLinkedList : public UNIT_TEST
{
public:
  UNIT_TEST_DLinkedList()
  {
    REGISTER_TEST(DLinkedList01);

    REGISTER_TEST(DLinkedList02);

    REGISTER_TEST(DLinkedList03);

    REGISTER_TEST(DLinkedList04);

    REGISTER_TEST(DLinkedList05);

    REGISTER_TEST(DLinkedList06);

    REGISTER_TEST(DLinkedList07);

    REGISTER_TEST(DLinkedList08);

    REGISTER_TEST(DLinkedList09);

    REGISTER_TEST(DLinkedList10);

    REGISTER_TEST(DLinkedList11);

    REGISTER_TEST(DLinkedList12);

    REGISTER_TEST(DLinkedList13);

    REGISTER_TEST(DLinkedList14);

    REGISTER_TEST(DLinkedList15);

    REGISTER_TEST(DLinkedList16);

    REGISTER_TEST(DLinkedList17);

    REGISTER_TEST(DLinkedList18);

    REGISTER_TEST(DLinkedList19);

    REGISTER_TEST(DLinkedList20);

    REGISTER_TEST(DLinkedList21);

    REGISTER_TEST(DLinkedList22);

    REGISTER_TEST(DLinkedList23);

    REGISTER_TEST(DLinkedList24);

    REGISTER_TEST(DLinkedList25);

    REGISTER_TEST(DLinkedList26);

    REGISTER_TEST(DLinkedList27);

    REGISTER_TEST(DLinkedList28);

    REGISTER_TEST(DLinkedList29);

    REGISTER_TEST(DLinkedList30);

    REGISTER_TEST(DLinkedList31);

    REGISTER_TEST(DLinkedList32);

    REGISTER_TEST(DLinkedList33);

    REGISTER_TEST(DLinkedList34);

    REGISTER_TEST(DLinkedList35);

    REGISTER_TEST(DLinkedList36);

    REGISTER_TEST(DLinkedList37);

    REGISTER_TEST(DLinkedList38);

    REGISTER_TEST(DLinkedList39);

    REGISTER_TEST(DLinkedList40);

    REGISTER_TEST(DLinkedList41);

    REGISTER_TEST(DLinkedList42);
  }

private:
  bool DLinkedList01();

  bool DLinkedList02();

  bool DLinkedList03();

  bool DLinkedList04();

  bool DLinkedList05();

  bool DLinkedList06();

  bool DLinkedList07();

  bool DLinkedList08();

  bool DLinkedList09();

  bool DLinkedList10();

  bool DLinkedList11();

  bool DLinkedList12();

  bool DLinkedList13();

  bool DLinkedList14();

  bool DLinkedList15();

  bool DLinkedList16();

  bool DLinkedList17();

  bool DLinkedList18();

  bool DLinkedList19();

  bool DLinkedList20();

  bool DLinkedList21();

  bool DLinkedList22();

  bool DLinkedList23();

  bool DLinkedList24();

  bool DLinkedList25();

  bool DLinkedList26();

  bool DLinkedList27();

  bool DLinkedList28();

  bool DLinkedList29();

  bool DLinkedList30();

  bool DLinkedList31();

  bool DLinkedList32();

  bool DLinkedList33();

  bool DLinkedList34();

  bool DLinkedList35();

  bool DLinkedList36();

  bool DLinkedList37();

  bool DLinkedList38();

  bool DLinkedList39();

  bool DLinkedList40();

  bool DLinkedList41();

  bool DLinkedList42();
 
  
};

#endif // UNIT_TEST_DLinkedList_HPP
