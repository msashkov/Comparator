#pragma once

#include <string>
#include <functional>

struct HashFunction {
    std::size_t operator()(const std::string& k) const {

        return std::hash<std::string>()(k);
    }

};