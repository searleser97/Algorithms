#include<bits/stdc++.h>

using namespace std;

class Trie {
private:
    class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        // map<char, TrieNode*> children;
        bool endOfWord;
        int numberOfWords;
        TrieNode() {
            this->numberOfWords = 0;
            this->endOfWord = false;
        }
        ~TrieNode() {
            unordered_map<char, TrieNode*> thisNodeChildren = this->children;
            unordered_map<char, TrieNode*>::iterator i = thisNodeChildren.begin();
            // map<char, TrieNode*> thisNodeChildren = this->children;
            // map<char, TrieNode*>::iterator i = thisNodeChildren.begin();
            while (i != thisNodeChildren.end()) {
                delete i->second;
                i++;
            }
            thisNodeChildren.clear();
        }
    };
private:
    TrieNode* root = nullptr;
    int maximo;
public:
    Trie() {
        maximo = 0;
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
        int goodness = word.size() * node->numberOfWords;
        if (goodness > this->maximo)
            this->maximo = goodness;
        if (node->endOfWord)
            words.push_back(word);
        for (auto i : node->children)
            getWords(i.second, words, word + i.first);
    }

    vector<string> getWords() {
        vector<string> words;
        this->maximo = 0;
        getWords(this->root, words, "");
        cout << this->maximo << endl;
        this->maximo = 0;
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
        current->endOfWord = false;
        getWords(current, words, prefix);
        current->endOfWord = true;
        return words;
    }


};

void printv(vector<string> v) {
    if (v.size() == 0) {
        cout << "No match." << '\n';
        return;
    }
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        Trie *tr = new Trie();
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j)
        {
            string str;
            cin >> str;
            tr->insert(str);
        }
        tr->getWords();
        delete tr;
    }
    
    return 0;
}