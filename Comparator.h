#pragma once

#include <fstream>
#include <cctype>
#include "WordMultiSet.h"

struct Comparator {

    void report(std::ifstream& a, std::ifstream& b);
    bool is_space(char ch);
    void helperFunctionForIfStatementForFisrtFile(const std::string& word, WordsMultiset& first, int& wordsInFile1);
    void helperFunctionForIfStatementForSecondFile(const std::string& word, WordsMultiset& first, int& wordsInFile2, int& commonWords);
    void print(int commonWords, int wordsInFile1, int wordsInFile2);

};