//
// Created by admin on 2018/1/5.
//
#include <iostream>
#include "commlib/shared_ptr.h"
using namespace redis;
class A : public SharedBase {
 public:
    A(double a, int b) : a_(a), b_(b) {}
    ~A (){ std::cout << "(" << a_ <<","<< b_ << ")is delete" << std::endl; }
    int a_ = 0;
    int b_ = 0;
};

SharedPtr<A> test_shared() {
    SharedPtr<A> temp = MakeShared<A>(2, 2);
    return temp;
}
void IsNull(const SharedPtr<A> &ptr) {
    if (ptr) {
        std::cout << "not null" << std::endl;
    } else {
        std::cout << "null" << std::endl;
    }
}
using namespace std;
int main() {
    SharedPtr<A> shared_ptr;
    IsNull(shared_ptr);// null
    std::cout << shared_ptr.Count() << std::endl; // 0
    shared_ptr = MakeShared<A>(1,1);
    IsNull(shared_ptr); // not null;
    std::cout << shared_ptr.Count() << std::endl; // 1
    {
        SharedPtr<A> temp = shared_ptr;
        std::cout << temp.Count() << std::endl; // 2
    }
    std::cout << shared_ptr.Count() << std::endl; // 1

    {
        auto ret_from_function = test_shared();
        std::cout << ret_from_function->a_ <<" " << ret_from_function->b_<<std::endl;
    } // {2，2}会自动析构

    return 0; // {1,1} 析构
    // 输出
    //    null
    //    0
    //    not null
    //    1
    //    2
    //    1
    //    2 2
    //    (2,2)is delete
    //    (1,1)is delete
}