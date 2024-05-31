#pragma once
#include "MaxHeap.cpp"
#include <iostream>
#include <string>
using namespace std;

struct SearchResult {
    string word;
    MaxHeap results;
    SearchResult(const string& data, const MaxHeap& r) : word(data), results(r) {}
};


struct CacheNode {
    SearchResult* data;
    CacheNode* next;
    CacheNode() : data(NULL), next(nullptr) {}
    CacheNode(SearchResult* data) : data(data), next(nullptr) {}
};

class CacheTable {
private:
    CacheNode** cacheTable;
    int currentSize;
    int totalCapacity;
    int primeIndex;
    const int primes[16] = { 11, 19, 41, 79, 163, 317, 641, 1279, 2557, 5119, 10243, 20479, 40961, 81919, 163841, 327673 };

    void rehash() {
        int oldCapacity = totalCapacity;
        primeIndex++;
        totalCapacity = primes[primeIndex];
        CacheNode** oldCacheTable = cacheTable;

        cacheTable = new CacheNode * [totalCapacity];
        for (int i = 0; i < totalCapacity; i++) {
            cacheTable[i] = nullptr;
        }

        currentSize = 0;

        for (int i = 0; i < oldCapacity; i++) {
            CacheNode* oldNode = oldCacheTable[i];
            while (oldNode != nullptr) {
                int index = hash(oldNode->data->word);
                CacheNode* newNode = new CacheNode(new SearchResult(oldNode->data->word, oldNode->data->results));
                newNode->next = cacheTable[index];
                cacheTable[index] = newNode;
                CacheNode* toDelete = oldNode;
                oldNode = oldNode->next;
                delete toDelete;
                currentSize++;
            }
        }

        delete[] oldCacheTable;
    }

    int hash(const string& key) const {
        int sum = 0;
        for (char ch : key) {
            sum += ch;
        }
        return sum % totalCapacity;
    }

public:
    CacheTable() : primeIndex(0), totalCapacity(11), currentSize(0) {
        cacheTable = new CacheNode * [totalCapacity];
        for (int i = 0; i < totalCapacity; i++) {
            cacheTable[i] = nullptr;
        }
    }

    CacheTable(int capacity) : primeIndex(0), currentSize(0) {
        // Find the smallest prime larger than capacity
        for (int i = 0; i < 16; i++) {
            if (primes[i] >= capacity) {
                primeIndex = i;
                break;
            }
        }
        totalCapacity = primes[primeIndex];
        cacheTable = new CacheNode * [totalCapacity];
        for (int i = 0; i < totalCapacity; i++) {
            cacheTable[i] = nullptr;
        }
    }

    CacheTable(const CacheTable& other) : currentSize(other.currentSize), totalCapacity(other.totalCapacity), primeIndex(other.primeIndex) {
        cacheTable = new CacheNode * [totalCapacity];
        for (int i = 0; i < totalCapacity; i++) {
            cacheTable[i] = nullptr;
            CacheNode* current = other.cacheTable[i];
            while (current != nullptr) {
                put(current->data->word, current->data->results);
                current = current->next;
            }
        }
    }
    ~CacheTable() {
        for (int i = 0; i < totalCapacity; i++) {
            CacheNode* current = cacheTable[i];
            while (current != nullptr) {
                CacheNode* toDelete = current;
                current = current->next;
                delete toDelete;
            }
        }
        delete[] cacheTable;
    }

    void put(const string& key, const MaxHeap& value) {
        int index = hash(key);
        SearchResult* node = new SearchResult(key, value);
        CacheNode* newNode = new CacheNode(node);
        newNode->next = cacheTable[index];
        cacheTable[index] = newNode;
        currentSize++;

        float loadFactor = (1.0 * currentSize) / totalCapacity;
        if (loadFactor >= 0.75) {
            rehash();
        }
    }

    MaxHeap get(const string& key) const {
        int index = hash(key);
        CacheNode* head = cacheTable[index];
        while (head != nullptr) {
            if (head->data->word == key) {
                return head->data->results;
            }
            head = head->next;
        }
        return MaxHeap(); // Key not found, return an empty MaxHeap or a suitable value indicating not found
    }

    int size() const {
        return currentSize;
    }

    bool exists(const string& key) const {
        return !(get(key).isEmpty()); // Assuming MaxHeap has an isEmpty() method to check if it's empty
    }
};
