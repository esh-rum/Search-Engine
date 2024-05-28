#pragma once
#include "HashTable.cpp"
//#include "Funct.cpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


class Doc {
private:
    string name;
    string filePath;

public:
    HashTable hashTable;

    Doc(const string& name, const string& filePath) : name(name), filePath(filePath) {}

    Doc(const Doc& other) : name(other.name), filePath(other.filePath), hashTable(other.hashTable) {}

    void processFile() {
        ifstream file(filePath);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filePath << endl;
            return;
        }

        string word;
        vector<WordItem> words;
        while (file >> word) {
            string newWord;
            for (char c : word) {
                if (isalpha(c) || c == '\'') {
                    newWord += c;
                }
            }

            newWord = removeApostrophe(newWord);
            newWord = toLowerCase(newWord);

            if (!newWord.empty()) {
                int index = -1;
                for (int i = 0; i < words.size(); i++) {
                    if (words[i].word == newWord) {
                        index = i;
                        break;
                    }
                }

                if (index != -1) {
                    words[index].frequency++;
                }
                else {
                    words.emplace_back(newWord, 1);
                }
            }
        }

        // Print words and frequencies before inserting into the hash table
        for (const auto& wordItem : words) {
            hashTable.put(wordItem.word, wordItem.frequency);
        }

        file.close();
    }


    bool exist(const string& word) {
        return hashTable.exists(word);
    }

    int getWordFrequency(const string& word) {
        return hashTable.get(word);
    }

    int getWordFrequencyAND(const string& word, const string& word2) {
        return hashTable.getAND(word, word2);
    }

    int getWordFrequencyOR(const string& word, const string& word2) {
        return hashTable.getOR(word, word2);
    }

    int getTableSize() {
        return hashTable.size();
    }

    string getName() const {
        return name;
    }

    string getFilePath() const {
        return filePath;
    }

    static string toLowerCase(const string& str) {
        string result;
        for (char ch : str) {
            result += tolower(ch);
        }
        return result;
    }

    static string removeApostrophe(const string& str) {
        if (str.empty()) return str;
        if (str.front() == '\'') {
            return str.substr(1);
        }
        if (str.back() == '\'') {
            return str.substr(0, str.length() - 1);
        }
        return str;
    }

    string getContent() {
        string content;
        fstream file(filePath, std::ios::in);
        if (file.is_open()) {
            std::string line;
            while (getline(file, line)) {
                content += line + "\r\n"; // Append each line followed by a newline character
            }
            file.close();
        }
        return content;
    }
};