// wpt = number of words passing through
// w = number of words ending in the node
// c = character

struct Trie {
  struct Node {
    // for lexicographical order use 'map'
    // map<char, Node *> ch; 
    unordered_map<char, Node *> ch;
    int w = 0, wpt = 0;
  };

  Node *root = new Node();

  void insert(string str) {
    Node *curr = root;
    for (auto &c : str) {
      curr->wpt++;
      if (!curr->ch.count(c))
        curr->ch[c] = new Node();
      curr = curr->ch[c];
    }
    curr->wpt++;
    curr->w++;
  }

  Node *find(string &str) {
    Node *curr = root;
    for (auto &c : str) {
      if (!curr->ch.count(c)) return nullptr;
      curr = curr->ch[c];
    }
    return curr;
  }

  // number of words with given prefix
  int prefixCount(string prefix) {
    Node *node = find(prefix);
    return node ? node->wpt : 0;
  }
  // number of words matching str
  int strCount(string str) {
    Node *node = find(str);
    return node ? node->w : 0;
  }

  void getWords(Node *curr, vector<string> &words,
                string &word) {
    if (!curr) return;
    if (curr->w) words.push_back(word);
    for (auto &c : curr->ch) {
      getWords(c.second, words, word += c.first);
      word.pop_back();
    }
  }

  vector<string> getWords() {
    vector<string> words;
    string word = "";
    getWords(root, words, word);
    return words;
  }

  vector<string> getWordsByPrefix(string prefix) {
    vector<string> words;
    getWords(find(prefix), words, prefix);
  }

  bool remove(Node *curr, string &str, int &i) {
    if (i == str.size()) {
      curr->wpt--;
      return curr->w ? !(curr->w = 0) : 0;
    }
    int c = str[i];
    if (!curr->ch.count(c)) return false;
    if (remove(curr->ch[c], str, ++i)) {
      if (!curr->ch[c]->wpt)
        curr->wpt--, curr->ch.erase(c);
      return true;
    }
    return false;
  }

  int remove(string str) {
    int i = 0;
    return remove(root, str, i);
  }
};