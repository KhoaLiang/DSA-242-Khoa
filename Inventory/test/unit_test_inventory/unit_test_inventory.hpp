#ifndef UNIT_TEST_inventory_HPP
#define UNIT_TEST_inventory_HPP
#include"util/Point.h"
#include"list/DLinkedList.h"
#include"list/XArrayList.h"
#include "app/inventory.h"
#include "unit_test.hpp"

// Macro to simplify test registration
#define REGISTER_TEST(func) registerTest(#func, [this]() { return func(); })

class UNIT_TEST_inventory : public UNIT_TEST
{
public:
  UNIT_TEST_inventory()
  {
    REGISTER_TEST(inventory01);

    REGISTER_TEST(inventory02);

    REGISTER_TEST(inventory03);

    REGISTER_TEST(inventory04);

    REGISTER_TEST(inventory05);

    REGISTER_TEST(inventory06);

    REGISTER_TEST(inventory07);

    REGISTER_TEST(inventory08);

    REGISTER_TEST(inventory09);

    REGISTER_TEST(inventory10);

    REGISTER_TEST(inventory11);

    REGISTER_TEST(inventory12);

    REGISTER_TEST(inventory13);

    REGISTER_TEST(inventory14);

    REGISTER_TEST(inventory15);

    REGISTER_TEST(inventory16);

    REGISTER_TEST(inventory17);

    REGISTER_TEST(inventory18);

    REGISTER_TEST(inventory19);

    REGISTER_TEST(inventory20);

    REGISTER_TEST(inventory21);

    REGISTER_TEST(inventory22);

    REGISTER_TEST(inventory23);

    REGISTER_TEST(inventory24);

    REGISTER_TEST(inventory25);

    REGISTER_TEST(inventory26);

    REGISTER_TEST(inventory27);

    REGISTER_TEST(inventory28);

    REGISTER_TEST(inventory29);

    REGISTER_TEST(inventory30);

    REGISTER_TEST(inventory31);

    REGISTER_TEST(inventory32);
  }

private:
  bool inventory01();

  bool inventory02();

  bool inventory03();

  bool inventory04();

  bool inventory05();

  bool inventory06();

  bool inventory07();

  bool inventory08();

  bool inventory09();

  bool inventory10();

  bool inventory11();

  bool inventory12();

  bool inventory13();

  bool inventory14();

  bool inventory15();

  bool inventory16();

  bool inventory17();

  bool inventory18();

  bool inventory19();

  bool inventory20();

  bool inventory21();

  bool inventory22();

  bool inventory23();

  bool inventory24();

  bool inventory25();

  bool inventory26();

  bool inventory27();

  bool inventory28();

  bool inventory29();

  bool inventory30();

  bool inventory31();

  bool inventory32();
};

#endif // UNIT_TEST_inventory_HPP
