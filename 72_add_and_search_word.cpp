#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char data;
    Node *arr[26];
    bool endsHere;
    
    Node(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) arr[i] = NULL;
        endsHere = false;
    }
    
    bool containsKey(char ch) {
        return arr[ch-'a'] != NULL;
    }
    
    void addKey(char ch) {
        Node* node = new Node(ch);
        arr[ch-'a'] = node;
    }
    
    Node* getKeyNode(char ch) {
        return arr[ch-'a'];
    }
};

class WordDictionary {
public:
    Node *root;
    WordDictionary() {
        root = new Node('\0');
    }
    
    void addWord(string word) {
        Node *curr = root;
        for (char ch : word) {
            if (!curr->containsKey(ch)) 
                curr->addKey(ch);
            curr = curr->getKeyNode(ch);
        }
        curr->endsHere = true;
    }
    
    bool searchWord(int i, string word, Node* curr) {
        for (; i < word.size(); i++) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; j++) {
                    if (curr->arr[j] != NULL)
                        if (searchWord(i+1, word, curr->arr[j])) 
                            return true;
                }
                return false;
            } else if (!curr->containsKey(word[i])) return false;
            curr = curr->getKeyNode(word[i]);
        }
        return curr->endsHere;
    }
    
    bool search(string word) {
        Node *curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '.') {
                return searchWord(i, word, curr);
            } else if (!curr->containsKey(word[i])) return false;
            curr = curr->getKeyNode(word[i]);
        }
        return curr->endsHere;
    }
};