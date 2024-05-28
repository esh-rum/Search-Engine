#pragma once
#include <string>

using namespace std;

struct WordItem {
    string word;
    int frequency;

    WordItem() : word(""), frequency(0) {}
    WordItem(string word, int frequency) : word(word), frequency(frequency) {}
};

struct Node {
    WordItem* data;
    Node* next;

    Node(WordItem* data) : data(data), next(nullptr) {}
    ~Node() { delete data; }
};