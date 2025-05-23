#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "test/tc_xmap.h"
#include "test/tc_heap.h"
#include "test/tc_compressor.h"
#include "test/tc_dlinkedlist.h"
#include "test/tc_xarraylist.h"
#include "test/tc_inventory.h"

using namespace std;

void (*func_ptr[35])() = {
    hashDemo1,
    hashDemo2,
    hashDemo3,
    hashDemo4,
    hashDemo5,
    hashDemo6,
    hashDemo7,
    hashDemo8,
    heapDemo1,
    heapDemo2,
    heapDemo3,
    heapDemo4,
    tc_huffman1001,
    tc_huffman1002,
    tc_huffman1003,
    tc_huffman1004,
    tc_huffman1005,
    tc_compressor1001,
    tc_compressor1002,
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
    // cout << "Assignment-2" << endl;
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

    // dList
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

    // hashDemo
    // if (argc == 1) {
    //     hashDemo1();
    // }
    // if (argc == 2) {
    //     hashDemo2();
    // }
    // if (argc == 3) {
    //     hashDemo3();
    // }
    // if (argc == 4) {
    //     hashDemo4();
    // }
    // if (argc == 5) {
    //     hashDemo5();
    // }
    // if (argc == 6) {
    //     hashDemo6();
    // }
    // if (argc == 7) {
    //     hashDemo7();
    // }
    // if (argc == 8) {
    //     hashDemo8();
    // }
    // if (argc == 9) {
    //     hashDemo9();
    // }
    

    // heapDemo
    // if (argc == 1) {
    //     heapDemo1();
    // }
    // if (argc == 2) {
    //     heapDemo2();
    // }
    // if (argc == 3) {
    //     heapDemo3();
    // }
    // if (argc == 4) {
    //     heapDemo4();
    // }

    // inventoryDemo
    // if (argc == 1) {
    //     tc_inventory1001();
    // }
    // if (argc == 2) {
    //     tc_inventory1002();
    // }
    // if (argc == 3) {
    //     tc_inventory1003();
    // }
    // if (argc == 4) {
    //     tc_inventory1004();
    // }
    // if (argc == 5) {
    //     tc_inventory1005();
    // }
    // if (argc == 6) {
    //     tc_inventory1006();
    // }

    //huffMan demo
    if (argc == 1) {
        tc_huffman1001();
    }
    if (argc == 2) {
        tc_huffman1002();
    }
    if (argc == 3) {
        tc_huffman1003();
    }
    if (argc == 4) {
        tc_huffman1004();
    }
    if (argc == 5) {
        tc_huffman1005();
    }

    //tc compressor
    // if (argc == 1) {
    //     tc_compressor1001();
    // }
    // if (argc == 2) {
    //     tc_compressor1002();
    // }
    return 0;
}