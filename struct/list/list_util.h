//
// Created by liuping on 2017/12/30.
// base std::list
#pragma once
#include <list>

class ListUtil {
 public:
    template <typename T>
    static void ListRotate(std::list<T> &lst);
};

// 功能 将{1,2,3,4,5}--转换为->{5,1,2,3,4}
template <typename T>
void ListUtil::ListRotate(std::list<T> &lst) {
    // todo 是否有更优雅的实现
    T temp = lst.back();
    lst.emplace(lst.begin(), std::move(temp));
    lst.pop_back();
}