//
// Created by liuping on 2017/12/30.
//

#include <ctype.h>
#include "struct/string/string_util.h"

std::string &StringUtil::ToLower(std::string &str) {
    for (int i = 0; i < str.size(); ++i) {
        str[i] = tolower(str[i]);
    }
    return str;
}

std::string &StringUtil::ToUpper(std::string &str) {
    for (int i = 0; i < str.size(); ++i) {
        str[i] = toupper(str[i]);
    }
    return str;
}