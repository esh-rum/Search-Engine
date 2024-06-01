#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
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

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heapSize && heap[left].frequency > heap[largest].frequency) {
            largest = left;
        }

        if (right < heapSize && heap[right].frequency > heap[largest].frequency) {
            largest = right;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }
    void heapifyDown(vector<DocFreq>& tempHeap, int size, int index) const {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && tempHeap[left].frequency > tempHeap[largest].frequency) {
            largest = left;
        }

        if (right < size && tempHeap[right].frequency > tempHeap[largest].frequency) {
            largest = right;
        }

        if (largest != index) {
            swap(tempHeap[index], tempHeap[largest]);
            heapifyDown(tempHeap, size, largest);
        }
    }
public:
    MaxHeap() : heapSize(0) {}

    void insertNode(DocFreq newNode) {
        if (heapSize < MAX_SIZE) {
            heap[heapSize] = newNode;
            heapSize++;
            heapifyUp(heapSize - 1);
        }
        else if (newNode.frequency > heap[9].frequency) {
            heap[9] = newNode;
            heapifyUp(heapSize - 1);
        }
    }
    void printHeap() const {
        cout << "Max Heap:" << endl;
        for (int i = 0; i < heapSize; i++) {
            cout << heap[i].docName << " - " << heap[i].frequency << endl;
        }
    }

    bool isEmpty() const {
        return heapSize == 0;
    }

    string getDocNamesInOrder() const {
        stringstream ss;
        // Create a copy of the heap for traversal
        vector<DocFreq> tempHeap(heap, heap + heapSize);
        int tempHeapSize = heapSize;

        int index = 1;
        while (tempHeapSize > 0) {
            ss << index++ << ". " << tempHeap[0].docName << "\r\n";
            // Replace root with the last element and reduce heap size
            tempHeap[0] = tempHeap[tempHeapSize - 1];
            tempHeapSize--;
            // Restore heap property
            heapifyDown(tempHeap, tempHeapSize, 0);
        }
        return ss.str();
    }

};