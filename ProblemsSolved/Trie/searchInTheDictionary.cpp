#include<bits/stdc++.h>

using namespace std;

class Trie {
private:
    class TrieNode {
    public:
        // unordered_map<char, TrieNode*> children;
        map<char, TrieNode*> children;
        bool endOfWord;
        int numberOfWords;
        TrieNode() {
            this->numberOfWords = 0;
            this->endOfWord = false;
        }
        ~TrieNode() {
            // unordered_map<char, TrieNode*> thisNodeChildren = this->children;
            // unordered_map<char, TrieNode*>::iterator i = thisNodeChildren.begin();
            map<char, TrieNode*> thisNodeChildren = this->children;
            map<char, TrieNode*>::iterator i = thisNodeChildren.begin();
            while (i != thisNodeChildren.end()) {
                delete i->second;
                i++;
            }
            thisNodeChildren.clear();
        }
    };
private:
    TrieNode* root = nullptr;
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        delete root;
    }
    void insert(string &word) {
        TrieNode *current = this->root;
        current->numberOfWords++;
        for (int i = 0; i < word.size(); i++) {
            char symbol = word[i];
            if (current->children.count(symbol) == 0)
                current->children[symbol] = new TrieNode();
            current = current->children[symbol];
            current->numberOfWords++;
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

    vector<string> getWords(string &prefix) {
        vector<string> words;
        TrieNode *current = this->root;
        for (int i = 0; i < prefix.size(); i++) {
            if (current->children.count(prefix[i]) == 0)
                return words;
            current = current->children[prefix[i]];
        }
        bool prevState = current->endOfWord;
        current->endOfWord = false;
        getWords(current, words, prefix);
        current->endOfWord = prevState;
        return words;
    }


};

void printv(vector<string> v) {
    if (v.size() == 0) {
        cout << "No match." << endl;
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(0);
    
    int n, k;
    Trie *tr = new Trie();
    cin >> n;
    for (int i = 0; i < n; i++) {
        string aux;
        cin >> aux;
        tr->insert(aux);
    }
    cin >> k;
    for (int j = 0; j < k; j++) {
        string str;
        cin >> str;
        cout << "Case #" << j + 1 << ":" << '\n';
        printv(tr->getWords(str));
    }
    
    delete tr;
    return 0;
}