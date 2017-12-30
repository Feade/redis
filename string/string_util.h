//
//  Created by liuping on 2017/12/30.
//  redis string
//  基于std::string实现redis的string对象
//
#pragma once

#include <string>

class StringUtil {
 public:
    static std::string &ToLower(std::string &str);

    static std::string &ToUpper(std::string &str);
};
