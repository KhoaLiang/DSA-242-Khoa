g++ -g -I include -I src -std=c++17 src/test/* src/main.cpp -o main && ./main

# A compile that actually works
g++ -g -I include -I src -std=c++17 src/test/tc_xmap.cpp src/test/tc_heap.cpp src/main.cpp -o main

# Surprisingly, this works too
g++ -g -I include -I src -std=c++17 src/test/tc_xmap.cpp src/test/tc_heap.cpp src/test/tc_compressor.cpp src/main.cpp src/test/tc_dlinkedlist.cpp src/test/tc_xarraylist.cpp -o main