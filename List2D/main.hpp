/*
 * DSA1 - HK242
 * file : main.hpp
 * SRC template
 * Author: Võ Tiến
 * Link FB : https://www.facebook.com/Shiba.Vo.Tien
 * Link Group : https://www.facebook.com/groups/khmt.ktmt.cse.bku
 * Date: 10.9.2024
 */

#ifndef MAIN_HPP
#define MAIN_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string CYAN = "\033[36m";

void handleTestUnit(int argc, char *argv[]);
void printTestCase()
{
    std::cout << GREEN << BOLD << "To run tests, use one of the following commands:" << RESET << std::endl;
    std::cout << RED << "1. Run all tests: ./main " << RESET << std::endl;
    std::cout << RED << "2. Run a specific test: ./main nameFunctionUnitTest" << RESET
              << std::endl
              << std::endl;
}
#endif // MAIN_HPP