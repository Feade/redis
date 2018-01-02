//
// Created by liuping on 2018/1/1.
//

#include "redis/redis_object/string_object.h"
#include <iostream>
#include <map>
int main() {
    IntString int_string(1212);
    std::cout<< "sizeof:" << sizeof(int_string) <<  " type:" << int_string.Type()<<
             " value:" << int_string() << std::endl;

    EmbeddedString embedded_string("hello world");
    std::cout<< "sizeof:" << sizeof(embedded_string) << " type:" << embedded_string.Type()<<" value:" <<
             embedded_string() << " size:" << embedded_string().size() << std::endl;

    RawString raw_string("hello world");
    std::cout<< "sizeof:" << sizeof(raw_string) << " type:" << raw_string.Type()<<" value:" << raw_string() << " size:" <<
             raw_string().size() << std::endl;


    RawString raw_string1(123451234512345.0);
    std::cout<< "type:" << raw_string1.Type()<<" value:" << raw_string1() << " size:" <<
             raw_string1().size() << std::endl;

    std::cout << "sizeof std::string:" << sizeof(std::string) <<std::endl;
    std::cout << "size:\tint_string\tembedded_string\traw_string"<<std::endl;
    std::cout << "all\t"<< sizeof(IntString) <<"\t"<< sizeof(EmbeddedString) <<"\t"<< sizeof(RawString)<<std::endl;
    std::cout << "value\t" <<sizeof(int_string.value_) <<"\t"<< sizeof(embedded_string.value_) <<"\t"
              << sizeof(raw_string.value_)<<std::endl;

    return 0;
}