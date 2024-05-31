#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct DocFreq {
    string docName;
    int frequency;

    DocFreq() {
        docName = "";
        frequency = 0;
    }

    DocFreq(string name, int f) {
        docName = name;
        frequency = f;
    }
};

class MaxHeap {
private:
    static const int MAX_SIZE = 10;
    DocFreq heap[MAX_SIZE];
    int heapSize;


    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index].frequency > heap[parent].frequency) {

            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

public:
    MaxHeap() {
        heapSize = 0;
    }

    void insertNode(DocFreq newNode) {
        if (heapSize == MAX_SIZE) {
            cout << "Heap is full. Cannot insert more nodes." << endl;
            return;
        }

        heap[heapSize] = newNode;
        heapSize++;

        heapifyUp(heapSize - 1);
    }

    void printHeap() {
        cout << "Max Heap:" << endl;
        for (int i = 0; i < heapSize; i++) {
            cout << heap[i].docName << " - " << heap[i].frequency << endl;
        }
    }

    bool isEmpty() {
        if (heapSize == 0) {
            return true;
        }
        return false;
    }
    string getDocNamesInOrder() const {
        stringstream ss;
        for (int i = 0; i < heapSize; i++) {
            ss << i + 1 << ". " << heap[i].docName << "\n";
        }
        return ss.str();
    }
};

