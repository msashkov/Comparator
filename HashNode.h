#pragma once

#include <string>

class HashNode {
public:
    HashNode(const std::string& key, const int& value) :
        key(key), value(value), next(nullptr) {}

    std::string getKey() const {
        return key;
    }

    int getValue() const {
        return value;
    }

    void setValue(int value) {
        this->value += value;
    }

    HashNode* getNext() const {
        return next;
    }

    void setNext(HashNode* next) {
        this->next = next;
    }

private:
    std::string key;
    int value;
    HashNode* next;
};