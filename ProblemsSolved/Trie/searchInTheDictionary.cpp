#include <bits/stdc++.h>

// wpt = number of words passing through
// w = number of words ending in the node
// c = character

using namespace std;
struct Trie {
  struct Node {
    // for lexicographical order use 'map'
    map<char, Node *> ch;
    // unordered_map<char, Node *> ch;
    int w = 0, wpt = 0;
  };

  Node *root = new Node();

  void insert(string str) {
    Node *curr = root;
    for (int i = 0; i < str.size(); i++) {
      int c = str[i];
      curr->wpt++;
      if (!curr->ch.count(c))
        curr->ch[c] = new Node();
      curr = curr->ch[c];
    }
    curr->wpt++;
    curr->w++;
  }

  void getWords(Node *curr, vector<string> &words,
                string word) {
    if (curr->w) words.push_back(word);
    for (auto &c : curr->ch) {
      getWords(c.second, words, word + c.first);
    }
  }

  vector<string> getWordsByPrefix(string prefix) {
    vector<string> words;
    Node *node = root;
    for (int i = 0; i < prefix.size(); i++) {
      int c = prefix[i];
      if (!node->ch.count(c)) return words;
      node = node->ch[c];
    }
    int bckp = node->w;
    node->w = 0;
    getWords(node, words, prefix);
    node->w = bckp;
    return words;
  }
};

void printv(vector<string> v) {
  if (!v.size()) {
    cout << "No match." << endl;
    return;
  }
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << endl;
  //   for (auto &s : v) cout << s << endl;
}

int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);

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
    printv(tr->getWordsByPrefix(str));
  }
  delete tr;
  return 0;
}