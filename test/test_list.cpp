//
// Created by liuping on 2018/1/1.
//
#include "struct/list/list_util.h"
#include <list>
#include <iostream>

template <typename T>
std::ostream &PrintList(std::ostream &os, const std::list<T> &lst) {
    for (const auto &item : lst) {
        os << item << " ";
    }
    return os;
}

int main() {
    std::list<int> lst = {1,2,3,4,5};
    PrintList(std::cout, lst) << std::endl;
    ListUtil::ListRotate(lst);
    PrintList(std::cout, lst) << std::endl;
    return 0;
}