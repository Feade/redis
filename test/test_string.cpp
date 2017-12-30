//
// Created by liuping on 2017/12/30.
//
#include <iostream>
#include "string/string_util.h"


int main() {

    std::cout << "test StringUtil::ToUpper\n";
    std::string str1 = "Hello World\n";
    std::cout << str1 << StringUtil::ToUpper(str1) << std::endl;

    std::cout << "test StringUtil::ToLower\n";
    std::string str2 = "Hello World\n";
    std::cout << str2 << StringUtil::ToLower(str2) << std::endl;
}
