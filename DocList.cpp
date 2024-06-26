#pragma once
#include "Doc.cpp"
#include "MaxHeap.cpp"
#include <list>

using namespace std;

class DocList {
private:
    list<Doc*> docList; // Store pointers to Doc objects

public:
    DocList() {
        fstream file("E:\\Solved lab tasks\\DS\\dsaProj\\databaseNetwork.txt", std::ios::in);
        if (!file.is_open()) {
            std::cerr << "Unable to open the file for reading." << std::endl;
            return;
        }

        string name, path;
        while (getline(file, name) && getline(file, path)) {
            Doc* doc = new Doc(name, path); // Assuming Doc has a constructor that accepts name and path
            doc->processFile();
            docList.push_back(doc);
        }
        file.close();
    }

    void addDocument(Doc* d) {
        docList.push_back(d);
    }

    Doc* getDoc(const string& docName) {
        for (auto& doc : docList) {
            if (doc->getName() == docName) {
                return doc;
            }
        }
        return nullptr;
    }

    /*void getResults(const string& word) {
        for (auto& doc : docList) {
            cout << "Doc Name: " << doc->getName() << endl;
            cout << "Frequency of word: " << doc->getWordFrequency(word) << endl;
        }
    }*/

    MaxHeap getResults(const string& word) {
        MaxHeap result;
        for (auto& doc : docList) {
            cout << "Checking document: " << doc->getName() << std::endl; // Debug print
            if (doc->exist(word)) {
                cout << "Word '" << word << "' exists in document: " << doc->getName() << endl; // Debug print
                int frequency = doc->getWordFrequency(word);
                cout << "Frequency of '" << word << "' in document: " << frequency << endl; // Debug print
                DocFreq docFreq(doc->getName(), frequency);
                result.insertNode(docFreq);
            }
            else {
                std::cout << "Word '" << word << "' does not exist in document: " << doc->getName() << endl; // Debug print
            }
        }
        return result;
    }

    MaxHeap getResultsAND(const string& word, const string& word2) {
        MaxHeap result;
        for (auto& doc : docList) {
            cout << "Checking document: " << doc->getName() << std::endl; // Debug print
            if (doc->exist(word) && doc->exist(word2)) {
                cout << "Word '" << word << "' exists in document: " << doc->getName() << endl; // Debug print
                int frequency = doc->getWordFrequencyAND(word, word2);
                cout << "Frequency of '" << word << "' in document: " << frequency << endl; // Debug print
                DocFreq docFreq(doc->getName(), frequency);
                result.insertNode(docFreq);
            }
            else {
                std::cout << "Word '" << word << "' does not exist in document: " << doc->getName() << endl; // Debug print
            }
        }
        return result;
    }

    MaxHeap getResultsOR(const string& word, const string& word2) {
        MaxHeap result;
        for (auto& doc : docList) {
            cout << "Checking document: " << doc->getName() << std::endl; // Debug print
            if (doc->exist(word) || doc->exist(word2)) {
                cout << "Word '" << word << "' exists in document: " << doc->getName() << endl; // Debug print
                int frequency = doc->getWordFrequencyOR(word, word2);
                cout << "Frequency of '" << word << "' in document: " << frequency << endl; // Debug print
                DocFreq docFreq(doc->getName(), frequency);
                result.insertNode(docFreq);
            }
            else {
                std::cout << "Word '" << word << "' does not exist in document: " << doc->getName() << endl; // Debug print
            }
        }
        return result;
    }


    void traverseList() {
        for (const auto& doc : docList) {
            cout << "Doc Name: " << doc->getName() << endl;
            cout << "Filepath: " << doc->getFilePath() << endl;
        }
    }
    
    string getDocNamesAsString() const {
        stringstream ss;
        for (const auto& doc : docList) {
            ss << doc->getName() << "\n";
        }
        return ss.str();
    }

    ~DocList() {
        fstream file("E:\\Solved lab tasks\\DS\\dsaProj\\databaseNetwork.txt", ios::in | ios::out);
        string name, path;

        if (!file.is_open()) {
            // File could not be opened, attempt to create a new file
            file.open("E:\\Solved lab tasks\\DS\\dsaProj\\databaseNetwork.txt", ios::in | ios::out);
            if (!file) {
                cerr << "Unable to create or open the file." << endl;
                return;
            }
        }

        for (auto& d : docList) {
            name = d->getName();
            path = d->getFilePath();
            file << name << endl;
            file << path << endl;
        }
        file.close();
    }
};