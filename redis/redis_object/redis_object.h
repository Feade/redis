//
// Created by liuping on 2018/1/1.
//

#pragma once
#include <memory>
#include <string>
enum ObjectType{
    INT_STRING = 1,
    EMBEDDED_STRING,
    REW_STRING
};

class Object {
 public:
    virtual ObjectType Type() = 0;
    virtual void Print() = 0;
    virtual ~Object(){}
};

template <ObjectType type, typename T>
class RedisObject : public Object {
 public:
    RedisObject(T value) : value_(value) {}
    ObjectType Type() override { return type; }
    void Print() override {}

 protected:
    unsigned lru_ : 32; // 最后一次被访问的时间
    T value_;
};

//template <typename T>
//class ListObject : public RedisObject {
// public:
//
// private:
//    std::list<T> value_;
//};