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
public:
    bool isAWordPrefix;
    Trie() {
        root = new TrieNode();
        isAWordPrefix = false;
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

    bool find(string &word) {
        TrieNode *current = this->root;
        for (int i = 0; i < word.size(); i++) {
            char symbol = word[i];
            if (current->children.count(symbol) == 0)
                return false;
            current = current->children[symbol];
        }
        return current->endOfWord;
    }

private:
    bool deleteWord(TrieNode *current, string &word, int &index) {
        if (index == word.size()) {
            if (!current->endOfWord)
                return false;
            current->endOfWord = false;
            return current->children.size() == 0;
        }
        char symbol = word[index];
        if (current->children.count(symbol) == 0)
            return false;
        bool shouldDeleteChild = deleteWord(current->children[symbol], word, index += 1);

        if (shouldDeleteChild) {
            current->children.erase(symbol);
            return current->children.size() == 0;
        }
        return false;
    }

    void getWords(TrieNode* node, vector<string> &words, string &word) {
        if (node->endOfWord && node->numberOfWords > 1)
            this->isAWordPrefix = true;
        if (node->endOfWord)
            words.push_back(word);
        for (auto i : node->children) {
            getWords(i.second, words, word += i.first);
            word.pop_back();
        }
    }
public:
    void deleteWord(string &word) {
        int index = 0;
        deleteWord(this->root, word, index);
    }
    vector<string> getWords() {
        vector<string> words;
        string word = "";
        getWords(this->root, words, word);
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
        cout << "[]" << endl;
        return;
    }
    cout << "[" << v[0];
    for (int i = 1; i < v.size(); i++) {
        cout << ", " << v[i];
    }
    cout << "]" << endl;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        Trie *tr = new Trie();
        int n;
        cin >> n;
        while (n--) {
            string number;
            cin >> number;
            tr->insert(number);
        }
        tr->getWords();
        if (tr->isAWordPrefix)
            cout << "NO\n";
        else
            cout << "YES\n";
        delete tr;
    }
    return 0;
}