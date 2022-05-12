#include "HashNode.h"
#include <string>
#include <stdexcept>
#include "HashMap.h"

HashMap::HashMap() : size_(0), capacity(16) {
    table = new HashNode * [capacity]();
}

HashMap::~HashMap() {
    for (std::size_t i = 0; i < capacity; ++i) {
        HashNode* entry = table[i];
        while (entry != nullptr) {
            HashNode* prev = entry;
            entry = entry->getNext();
            delete prev;
        }
        table[i] = nullptr;
    }

    delete[] table;
}

bool HashMap::get(const std::string& key) const {
    std::size_t hashValue = func(key) % capacity;
    HashNode* entry = table[hashValue];

    while (entry != nullptr) {
        if (entry->getKey() == key) {
            return true;
        }
        entry = entry->getNext();
    }
    return false;
}

void HashMap::put(const std::string& key, const int& value) {

    std::size_t hashValue = func(key) % capacity;

    HashNode* prev = nullptr;
    HashNode* entry = table[hashValue];

    while (entry != nullptr && entry->getKey() != key) {
        prev = entry;
        entry = entry->getNext();
    }

    if (entry == nullptr) {
        entry = new HashNode(key, value);
        if (prev == nullptr) {
            table[hashValue] = entry;
        }
        else {
            prev->setNext(entry);
        }
        size_++;
    }

    else {
        entry->setValue(value);
    }

    double currentLoadFactor = (1.0 * size_) / capacity;

    if (currentLoadFactor > DEFAULT_LOAD_FACTOR) {
        expand();
    }

}

void HashMap::remove(const std::string& key) {
    std::size_t hashValue = func(key) % capacity;
    HashNode* prev = nullptr;
    HashNode* entry = table[hashValue];

    while (entry != nullptr && entry->getKey() != key) {
        prev = entry;
        entry = entry->getNext();
    }

    if (entry == nullptr) {
        return;
    }
    else {
        if (entry->getValue() == 1) {

            if (prev == nullptr) {

                table[hashValue] = entry->getNext();
            }
            else {
                prev->setNext(entry->getNext());
            }
            size_--;
            delete entry;
        }

        else {
            entry->setValue(-1);
        }

    }
}

std::size_t HashMap::count(const std::string& key) const {

    std::size_t hashValue = func(key) % capacity;
    HashNode* entry = table[hashValue];

    while (entry != nullptr) {
        if (entry->getKey() == key) {
            return entry->getValue();
        }
        entry = entry->getNext();
    }
    return 0;

}

std::size_t HashMap::size() const {
    return size_;
}

std::size_t HashMap::getCapacity() const {
    return capacity;
}

bool HashMap::isNullptr(std::size_t index) const {

    if (index > capacity) {
        throw std::out_of_range("The index is incorrect");
    }

    return table[index] == nullptr;
}

HashNode* HashMap::getNode(std::size_t index) {

    if (index > capacity) {
        throw std::out_of_range("The index is incorrect");
    }

    return table[index];
}

void HashMap::expand() {

    HashNode** temp = table;
    table = new HashNode * [2 * capacity];
    for (std::size_t i = 0; i < 2 * capacity; i++) {
        table[i] = nullptr;
    }
    std::size_t oldBucketCount = capacity;
    capacity *= 2;
    size_ = 0;

    for (std::size_t i = 0; i < oldBucketCount; i++) {
        HashNode* head = temp[i];
        while (head) {
            std::string key = head->getKey();
            int value = head->getValue();
            put(key, value);
            head = head->getNext();
        }
    }
    for (std::size_t i = 0; i < oldBucketCount; i++) {
        delete temp[i];
    }
    delete[]temp;
}

