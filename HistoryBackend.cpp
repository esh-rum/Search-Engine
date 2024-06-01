#pragma once
#include <iostream>
#include <list>
#include <stdexcept>
#include "Doc.cpp"

using namespace std;

class History {
private:
    list<string> data; // Store document names as strings

public:
    History() {}

    ~History() {
        clear(); // Ensure all data is cleared
    }

    void push(const string& docName) {
        data.push_back(docName);
    }

    void pop() {
        if (isEmpty()) {
            throw out_of_range("History is empty. Cannot pop.");
        }
        data.pop_back();
    }

    string top() const {
        if (isEmpty()) {
            throw out_of_range("History is empty. No top document.");
        }
        return data.back();
    }

    bool isEmpty() const {
        return data.empty();
    }

    void traverse() const {
        cout << "History (top to bottom): ";
        for (auto it = data.rbegin(); it != data.rend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    int size() const {
        return data.size();
    }

    void clear() {
        data.clear();
    }

    void insert(int pos, const string& docName) {
        if (pos < 0 || pos > size()) {
            throw out_of_range("Invalid position.");
        }
        auto it = data.begin();
        advance(it, pos);
        data.insert(it, docName);
    }

    void erase(int pos) {
        if (pos < 0 || pos >= size()) {
            throw out_of_range("Invalid position.");
        }
        auto it = data.begin();
        advance(it, pos);
        data.erase(it);
    }
};
/*int main() {
    History history;

    Doc doc1("sample", "C:\\Users\\noora\\Downloads\\i221868_assignment4\\i221868_assignment4\\test.txt");
    Doc doc2("program", "C:\\Users\\noora\\Downloads\\texts\\program.txt");
    Doc doc3("working", "C:\\Users\\noora\\Downloads\\texts\\Creative Writing.txt");
    doc1.processFile();
    doc2.processFile();
    doc3.processFile();

    history.push(doc1);
    history.push(doc2);
    history.push(doc3);

    history.traverse();

    cout << "Top document: " << history.top().getName() << endl;

    history.pop();

    history.traverse();

    cout << "Size of history: " << history.size() << endl;

    history.clear();
    cout << "History cleared." << endl;

    cout << "Size of history after clearing: " << history.size() << endl;

    return 0;
}*/