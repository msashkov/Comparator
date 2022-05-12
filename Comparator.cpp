#include <iostream>
#include <fstream>
#include <string>
#include "Comparator.h"
#include "WordMultiSet.h"

void Comparator::report(std::ifstream& a, std::ifstream& b) {

    WordsMultiset first;
    std::string word;

    int wordsInFile1 = 0;
    int wordsInFile2 = 0;
    int commonWords = 0;

    char c;
    while (a.get(c)) {

        if (is_space(c)) {
            if (!word.empty()) {
                first.add(word);
                wordsInFile1++;
            }

            word.clear();
        }

        else {
            word += c;
        }
    }
    if (!word.empty()) {
        first.add(word);
        wordsInFile1++;
    }

    word.clear();
    while (b.get(c)) {

        if (is_space(c)) {

            if (!word.empty()) {

                if (first.contains(word)) {
                    first.removeWord(word);
                    commonWords++;
                }
                wordsInFile2++;
            }

            word.clear();
        }

        else {
            word += c;
        }

    }

    if (!word.empty()) {

        if (first.contains(word)) {
            first.removeWord(word);
            commonWords++;
        }
        wordsInFile2++;

    }

    int percentage1 = ((double)commonWords / wordsInFile1) * 100;
    int percentage2 = ((double)commonWords / wordsInFile2) * 100;

    std::cout << "file1 contains " << wordsInFile1 << " words and " << commonWords
        << " of them are in file2(" << percentage1 << "%)"
        << std::endl;

    std::cout << "file2 contains " << wordsInFile2 << " words and " << commonWords
        << " of them are in file1(" << percentage2 << "%)"
        << std::endl;

    a.close();
    b.close();
}

bool Comparator::is_space(char ch) {
    return std::isspace(static_cast<unsigned char>(ch));
}