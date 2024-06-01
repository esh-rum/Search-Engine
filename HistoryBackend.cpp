#pragma once
#include <iostream>
#include <list>
#include <stdexcept>
#include <sstream>
#include <string>
#include <unordered_map>
#include <memory>

using namespace std;

class History {
private:
    list<string> data; // Store document names as strings

    // Private copy constructor and assignment operator to prevent copies
    History(const History&) = delete;
    History& operator=(const History&) = delete;

public:
    History() {}
    ~History() {
        clear(); // Ensure all data is cleared
    }
    // Public method to get a named instance (Multiton pattern)
    static History& getInstance(const string& key) {
        static unordered_map<string, unique_ptr<History>> instances;
        if (instances.find(key) == instances.end()) {
            instances[key] = make_unique<History>();
        }
        return *instances[key];
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

    string getDocNamesAsString() const {
        stringstream ss;
        int count = 1;
        for (const auto& string : data) {
            ss << count++ << ". " << string << "\r\n";
        }
        return ss.str();
    }
};
