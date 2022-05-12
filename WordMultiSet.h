#pragma once

#include <set>
#include <string>
#include "HashMap.h"

class WordsMultiset {
public:

    WordsMultiset() {
        map = new HashMap();
    }

    void removeWord(const std::string& word) {
        map->remove(word);
    }

    /// Adds times occurences of word to the container
    ///
    /// For example, add("abc") adds the word "abc" once,
    /// while add("abc", 4) adds 4 occurrances.
    void add(const std::string& word, size_t times = 1) {
        map->put(word, times);
    }

    /// Checks whether word is contained in the container
    bool contains(const std::string& word) const {
        return map->get(word);
    }

    /// Number of occurrances of word 
    size_t countOf(const std::string& word) const {
        return map->count(word);
    }

    /// Number of unique words in the container
    size_t countOfUniqueWords() const {
        return map->size();
    }

    /// Returns a multiset of all words in the container
    std::multiset<std::string> words() const {

        std::multiset<std::string> allWords;

        std::size_t length = map->getCapacity();

        for (std::size_t i = 0; i < length; i++) {

            if (!map->isNullptr(i)) {

                HashNode* first = map->getNode(i);
                while (first != nullptr) {
                    int count = first->getValue();

                    while (count > 0) {
                        allWords.insert(first->getKey());
                        count--;
                    }

                    first = first->getNext();
                }

            }

        }

        return allWords;

    }

private:
    HashMap* map;

};