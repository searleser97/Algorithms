// 2
template <class K, class V>
struct RedBlackTree {
  // 9
  struct Node {
    K key;
    V val;
    Node *l, *r;  // left, right
    bool isRed;
    Node(K k, V v, bool isRed) : key(k), val(v), isRed(isRed) {
    }
  };

  Node *root = nullptr;
  // 5
  int compare(K a, K b) {
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
  }
  // 11
  // O(lg(N))
  V at(K key) {
    Node *x = root;
    while (x) {
      int cmp = compare(key, x->key);
      if (!cmp) return x->val;
      if (cmp < 0) x = x->l;
      if (cmp > 0) x = x->r;
    }
    throw runtime_error("Key doesn't exist");
  }
  // 8
  Node *rotateLeft(Node *h) {
    Node *x = h->r;
    h->r = x->l;
    x->l = h;
    x->isRed = h->isRed;
    h->isRed = 1;
    return x;
  }
  // 8
  Node *rotateRight(Node *h) {
    Node *x = h->l;
    h->l = x->r;
    x->r = h;
    x->isRed = h->isRed;
    h->isRed = 1;
    return x;
  }
  // 5
  void flipColors(Node *h) {
    h->isRed = 1;
    h->l->isRed = 0;
    h->r->isRed = 0;
  }
  // 15
  // O(lg(N))
  Node *insert(Node *h, K key, V val) {
    if (!h) return new Node(key, val, 1);
    int cmp = compare(key, h->key);
    if (!cmp) h->val = val;
    if (cmp < 0) h->l = insert(h->l, key, val);
    if (cmp > 0) h->r = insert(h->r, key, val);
    if (h->r && h->r->isRed && !(h->l && h->l->isRed)) h = rotateLeft(h);
    if (h->l && h->l->isRed && h->l->l && h->l->l->isRed) h = rotateRight(h);
    if (h->l && h->l->isRed && h->r && h->r->isRed) flipColors(h);
    return h;
  }
  // 4
  // O(lg(N))
  void insert(K key, V val) {
    root = insert(root, key, val);
  }
};