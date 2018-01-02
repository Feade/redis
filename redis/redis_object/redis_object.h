//
// Created by liuping on 2018/1/1.
//

#pragma once
#pragma pack (4) // 设置4字节对其
#include <memory>
#include <string>
enum ObjectType{
    INT_STRING = 1,
    EMBEDDED_STRING,
    REW_STRING
};

class Object {
 public:
    uint32_t lru_ : 32; // 最后一次被访问的时间
};

template <ObjectType type, typename T>
class RedisObject : public Object {
 public:
    RedisObject(T value) : value_(value) {}
    ObjectType Type() { return type; }

 public:
    T value_;
};

#pragma pack ()