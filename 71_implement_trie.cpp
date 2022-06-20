#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    map<char, TrieNode*> alphabet;
    bool endsHere;
    
    TrieNode(char ch) {
        this->data = '\0';
        endsHere = false;
    }
    
    bool containsKey(char ch) {
        return alphabet.find(ch) != alphabet.end();
    }
    
    void addKey(char ch) {
        TrieNode *node = new TrieNode(ch);
        alphabet[ch] = node;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for (char ch : word) {
            if (!curr->containsKey(ch)) {
                curr->addKey(ch);
            }
            curr = (curr->alphabet)[ch];
         }
        curr->endsHere = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for (char ch : word) {
            if (!curr->containsKey(ch)) return false;
            curr = (curr->alphabet)[ch];
        }
        return curr->endsHere;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for (char ch : prefix) {
            if (!curr->containsKey(ch)) return false;
            else curr = (curr->alphabet)[ch];
        }
        return true;
    }
};
