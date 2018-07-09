#include <bits/stdc++.h>

// ASIZE = alphabet size
// wpt = number of words passing through
// w = number of words ending in the node
// c = character
const int ASIZE = 30;

using namespace std;
struct Trie {
  struct Node {
    vector<Node *> ch;
    int w, wpt;
    Node() {
      w = wpt = 0;
      ch = vector<Node *>(ASIZE, nullptr);
    }
  };

  Node *root = new Node();

  void insert(string str) {
    Node *curr = root;
    for (auto &c : str) {
      curr->wpt++;
      int i = c - 'a';
      if (!curr->ch[i]) curr->ch[i] = new Node();
      curr = curr->ch[i];
      cout << i << endl;
    }
    curr->wpt++;
    curr->w++;
  }

  Node *find(string &str) {
    Node *curr = root;
    for (auto &c : str) {
      int i = c - 'a';
      if (!curr->ch[i]) return curr;
      curr = curr->ch[i];
    }
    return curr;
  }

  // returns number of repeated words removed.
  bool remove(Node *curr, string &str, int &i) {
    if (!curr) return 0;
    if (i == str.size()) return curr->w ? !(curr->w = 0 && curr->wpt--) : 0;
    int c = str[i] - 'a';
    if (remove(curr->ch[c], str, ++i)) {
      if (!curr->ch[c]->wpt) curr->wpt--, curr->ch[c] = nullptr;
      return true;
    }
    return false;
  }

  int remove(string str) {
    int i = 0;
    return remove(root, str, i);
  }

  // number of words with given prefix
  int prefixCount(string prefix) { return find(prefix)->wpt; }
  // number of words matching str
  int strCount(string str) { return find(str)->w; }

  void getWords(Node *curr, vector<string> &words, string &word) {
    if (!curr) return;
    if (curr->w) words.push_back(word);
    for (int i = 0; i < ASIZE; i++) {
      getWords(curr->ch[i], words, word += (i + 'a'));
      word.pop_back();
    }
  }

  vector<string> getWords() {
    vector<string> words;
    string word = "";
    getWords(root, words, word);
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
  Trie trie;
  trie.insert("hola");
  trie.insert("holo");
  trie.insert("que");
  trie.insert("hay");
  trie.insert("de");
  trie.insert("nuevo");
  trie.insert("nueva");
  cout << " haha " << trie.strCount("hola") << endl;
  printv(trie.getWords());
  cout << " remove " << trie.remove("hola") << endl;
  printv(trie.getWords());
  return 0;
}