//
// Created by liuping on 2018/1/1.
//

#pragma once

#include "redis/redis_object/redis_object.h"

class RawString : public RedisObject<REW_STRING, std::string> {
 public:
    RawString(const std::string &str) : RedisObject(str) {
        value_.resize(str.size());
    }
    RawString(const char *buf, int len): RawString(std::string(buf, len)) {}
    RawString(long long value) : RawString(std::to_string(value)) {}
    RawString(double value) :RawString(std::to_string(value)) {}
    std::string &operator()(){ return value_; }
};

class EmbeddedString : public RedisObject<EMBEDDED_STRING, std::string> {
 public:
    EmbeddedString(const char *buf, int len) : RedisObject(buf) { value_.resize(len); }
    EmbeddedString(const std::string &str) : EmbeddedString(str.c_str(), str.size()) {}
    std::string &operator()() { return value_; }
};

class IntString : public RedisObject<INT_STRING, long> {
 public:
    IntString(long value) : RedisObject(value){}
    std::string operator()(){ return std::to_string(value_); }
};
