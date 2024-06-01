#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <sstream>
#include "Doc.cpp"
#include "DocList.cpp"

using namespace std;

// Graph class to show connectivity between documents
class DocGraph {
private:
    unordered_map<string, vector<string>> adjList; // Adjacency list
    DocList docList; // Member variable to store the list of documents

public:
    // Utility function to check if a word exists in a document's text
    bool doesDocMention(Doc* doc, const string& docName) {
        return doc->exist(docName);
    }

    // Add an edge between two documents
    void addEdge(const string& doc1, const string& doc2) {
        adjList[doc1].push_back(doc2);
    }

    // Build the graph based on document mentions
    void buildGraph() {
        stringstream ss(docList.getDocNamesAsString());
        string docName;
        vector<string> docNames;

        // Extract document names from the stringstream
        while (getline(ss, docName, '\n')) {
            docNames.push_back(docName);
        }

        // Build the adjacency list
        for (const auto& docName : docNames) {
            Doc* doc = docList.getDoc(docName);
            for (const auto& targetDocName : docNames) {
                if (docName != targetDocName) {
                    Doc* targetDoc = docList.getDoc(targetDocName);
                    if (doesDocMention(doc, targetDocName)) {
                        addEdge(docName, targetDocName);
                    }
                }
            }
        }
    }

    // Print the graph
    void printGraph() const {
        for (const auto& pair : adjList) {
            cout << pair.first << " mentions: ";
            for (const auto& neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    // Perform BFS to find the shortest path between two documents
    string findShortestPath(const string& startDoc, const string& endDoc) {
        unordered_map<string, bool> visited;
        unordered_map<string, string> parent;
        queue<string> q;
        stringstream ss;

        q.push(startDoc);
        visited[startDoc] = true;
        parent[startDoc] = "";

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            if (current == endDoc) {
                vector<string> path;
                for (string at = endDoc; at != ""; at = parent[at]) {
                    path.push_back(at);
                }
                reverse(path.begin(), path.end());

                for (const auto& docName : path) {
                    ss << docName << " -> ";
                }
                ss << "END\n";
                return ss.str();
            }

            for (const auto& neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = current;
                    q.push(neighbor);
                }
            }
        }

        return "No path found\n"; // No path found
    }

    // Get all mentions of a specific document as a string
    string getMentions(const string& docName) const {
        stringstream ss;
        auto it = adjList.find(docName);
        ss << docName << " mentions: ";
        if (it != adjList.end()) {
            for (const auto& mention : it->second) {
                ss << mention << " ";
            }
        }
        else {
            ss << "No mentions found.";
        }
        return ss.str();
    }

    // Add document to the internal DocList
    void addDocument(Doc* doc) {
        docList.addDocument(doc);
    }

    // Get the internal DocList as a string
    string getDocListAsString() const {
        return docList.getDocNamesAsString();
    }

};