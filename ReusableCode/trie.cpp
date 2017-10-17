//
// Created by san on 3/09/17.
//
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Trie {
private:
    class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool endOfWord;
        TrieNode() {
            this->endOfWord = false;
        }
        ~TrieNode() {
            unordered_map<char, TrieNode*> thisNodeChildren = this->children;
            unordered_map<char, TrieNode*>::iterator i = thisNodeChildren.begin();
            while (i != thisNodeChildren.end()) {
                cout << i->first << " " << i->second->endOfWord << endl;
                delete i->second;
                i++;
            }
            thisNodeChildren.clear();
        }
    };
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        delete root;
    }
    void insert(string &word) {
        TrieNode *current = this->root;
        for (int i = 0; i < word.size(); i++) {
            char symbol = word[i];
            if (current->children.count(symbol) == 0)
                current->children[symbol] = new TrieNode();
            current = current->children[symbol];
        }
        current->endOfWord = true;
    }

    void getWords(TrieNode* node, vector<string> &words, string word) {
        if (node->endOfWord)
            words.push_back(word);
        for (auto i : node->children)
            getWords(i.second, words, word + i.first);
    }

    vector<string> getWords() {
        vector<string> words;
        getWords(this->root, words, "");
        return words;
    }
};

void printv(vector<string> v) {
    if (v.size() == 0) {
        cout << "[]" << endl;
        return;
    }
    cout << "[" << v[0];
    for (int i = 1; i < v.size(); i++)
        cout << ", " << v[i];
    cout << "]" << endl;
}

int main() {
    int n;
    Trie tr;
    cin >> n;
    struct rusage *usage;
    for (int i = 0; i < n; i++) {
        string aux;
        cin >> aux;
        tr.insert(aux);
    }
    printv(tr.getWords());
    return 0;
}