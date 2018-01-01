//
// Created by liuping on 2018/1/1.
//

#include "redis/redis_object/string_object.h"
#include <iostream>

int main() {
    IntString int_string(1212);
    std::cout<< "type:" << int_string.Type()<<" value:" << int_string() << std::endl;

    EmbeddedString embedded_string("hello world");
    std::cout<< "type:" << embedded_string.Type()<<" value:" << embedded_string() << " size:" <<
             embedded_string().size() << std::endl;

    RawString raw_string("hello world");
    std::cout<< "type:" << raw_string.Type()<<" value:" << raw_string() << " size:" <<
             raw_string().size() << std::endl;


    RawString raw_string1(123451234512345.0);
    std::cout<< "type:" << raw_string1.Type()<<" value:" << raw_string1() << " size:" <<
             raw_string1().size() << std::endl;

    return 0;
}