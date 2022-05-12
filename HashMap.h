#pragma once

#include "HashNode.h"
#include <string>
#include "HashFunction.h"


class HashMap {
public:
    HashMap();
    ~HashMap();

    bool get(const std::string& key) const;
    void put(const std::string& key, const int& value);
    void remove(const std::string& key);
    std::size_t count(const std::string& key) const;
    std::size_t size() const;
    std::size_t getCapacity() const;
    bool isNullptr(std::size_t index) const;
    HashNode* getNode(std::size_t index);

private:
    HashNode** table;
    std::size_t size_;
    std::size_t capacity;
    HashFunction func;
    const double DEFAULT_LOAD_FACTOR = 0.75;

    void expand();
};