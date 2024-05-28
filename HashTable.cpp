#pragma once
#include "Node.cpp"
#include <iostream>
#include <string>
using namespace std;

class HashTable {
private:
    Node** hashTable;
    int currentSize;
    int totalCapacity;
    int primeIndex;
    const int primes[16] = { 11, 19, 41, 79, 163, 317, 641, 1279, 2557, 5119, 10243, 20479, 40961, 81919, 163841, 327673 };

    void rehash() {
        int oldCapacity = totalCapacity;
        primeIndex++;
        totalCapacity = primes[primeIndex];
        Node** oldHashTable = hashTable;

        hashTable = new Node * [totalCapacity];
        for (int i = 0; i < totalCapacity; i++) {
            hashTable[i] = nullptr;
        }

        currentSize = 0;

        for (int i = 0; i < oldCapacity; i++) {
            Node* oldNode = oldHashTable[i];
            while (oldNode != nullptr) {
                int index = hash(oldNode->data->word);
                Node* newNode = new Node(new WordItem(oldNode->data->word, oldNode->data->frequency));
                newNode->next = hashTable[index];
                hashTable[index] = newNode;
                Node* toDelete = oldNode;
                oldNode = oldNode->next;
                delete toDelete;
                currentSize++;
            }
        }

        delete[] oldHashTable;
    }

    int hash(const string& key) const {
        int sum = 0;
        for (char ch : key) {
            sum += ch;
        }
        return sum % totalCapacity;
    }

public:
    HashTable() : primeIndex(0), totalCapacity(11), currentSize(0) {
        hashTable = new Node * [totalCapacity];
        for (int i = 0; i < totalCapacity; i++) {
            hashTable[i] = nullptr;
        }
    }

    HashTable(int capacity) : primeIndex(0), currentSize(0) {
        // Find the smallest prime larger than capacity
        for (int i = 0; i < 16; i++) {
            if (primes[i] >= capacity) {
                primeIndex = i;
                break;
            }
        }
        totalCapacity = primes[primeIndex];
        hashTable = new Node * [totalCapacity];
        for (int i = 0; i < totalCapacity; i++) {
            hashTable[i] = nullptr;
        }
    }

    HashTable(const HashTable& other) : currentSize(other.currentSize), totalCapacity(other.totalCapacity), primeIndex(other.primeIndex) {
        hashTable = new Node * [totalCapacity];
        for (int i = 0; i < totalCapacity; i++) {
            hashTable[i] = nullptr;
            Node* current = other.hashTable[i];
            while (current != nullptr) {
                put(current->data->word, current->data->frequency);
                current = current->next;
            }
        }
    }
    ~HashTable() {
        for (int i = 0; i < totalCapacity; i++) {
            Node* current = hashTable[i];
            while (current != nullptr) {
                Node* toDelete = current;
                current = current->next;
                delete toDelete;
            }
        }
        delete[] hashTable;
    }

    void put(const string& key, int value) {
        int index = hash(key);
        Node* newNode = new Node(new WordItem(key, value));
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
        currentSize++;

        float loadFactor = (1.0 * currentSize) / totalCapacity;
        if (loadFactor >= 0.75) {
            rehash();
        }
    }

    int get(const string& key) const {
        int index = hash(key);
        Node* head = hashTable[index];
        while (head != nullptr) {
            if (head->data->word == key) {
                return head->data->frequency;
            }
            head = head->next;
        }
        return -1; // Key not found
    }

    int getAND(const string& key1, const string& key2) const {
        if (exists(key1) && exists(key2)) {
            return get(key1) + get(key2);
        }
        return -1;
    }

    int getOR(const string& key1, const string& key2) const {
        int sum = -1;
        if (exists(key1) && exists(key2)) {
            sum = get(key1) + get(key2);
        }
        else if (exists(key1)) {
            sum = get(key1);
        }
        else if (exists(key2)) {
            sum = get(key2);
        }
        return sum;
    }

    int size() const {
        return currentSize;
    }

    bool exists(const string& key) const {
        return get(key) != -1;
    }
};