//
// Created by liuping on 2017/12/30.
//
#include <iostream>
#include "struct/string/string_util.h"


int main() {

    std::cout << "test StringUtil::ToUpper\n";
    std::string str1 = "Hello World";
    std::cout << str1 << std::endl;
    std::cout << StringUtil::ToUpper(str1) << std::endl;

    std::cout << "test StringUtil::ToLower\n";
    std::string str2 = "Hello World";
    std::cout << str2 << std::endl;
    std::cout << StringUtil::ToLower(str2) << std::endl;
}
