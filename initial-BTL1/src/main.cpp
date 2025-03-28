#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "test/tc_dlinkedlist.h"
#include "test/tc_xarraylist.h"
#include "test/tc_inventory.h"

using namespace std;

void (*func_ptr[16])() = {
    dlistDemo1,
    dlistDemo2,
    dlistDemo3,
    dlistDemo4,
    dlistDemo5,
    dlistDemo6,
    xlistDemo1,
    xlistDemo2,
    xlistDemo3,
    xlistDemo4,
    tc_inventory1001,
    tc_inventory1002,
    tc_inventory1003,
    tc_inventory1004,
    tc_inventory1005,
    tc_inventory1006
};

void run(int func_idx)
{
    func_ptr[func_idx]();
}

int main(int argc, char **argv)
{
    // cout << "Assignment-1" << endl;
    // if (argc == 1) {
    //     tc_inventory1001();
    // }
    
    // if (argc == 1) {
    //     xlistDemo1();
    // }
    // if (argc == 2) {
    //     xlistDemo2();
    // }
    // if (argc == 3) {
    //     xlistDemo3();
    // }
    // if (argc == 4) {
    //     xlistDemo4();
    // }
    // if (argc == 1) {
    //     dlistDemo1();
    // }
    // if (argc == 2) {
    //     dlistDemo2();
    // }
    // if (argc == 3) {
    //     dlistDemo3();
    // }
    // if (argc == 4) {
    //     dlistDemo4();
    // }
    // if (argc == 5) {
    //     dlistDemo5();
    // }
    // if (argc == 6) {
    //     dlistDemo6();
    // }
    if (argc == 1) {
        tc_inventory1001();
    }
    if (argc == 2) {
        tc_inventory1002();
    }
    if (argc == 3) {
        tc_inventory1003();
    }
    if (argc == 4) {
        tc_inventory1004();
    }
    if (argc == 5) {
        tc_inventory1005();
    }
    if (argc == 6) {
        tc_inventory1006();
    }
    return 0;
}