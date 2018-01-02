#include <bits/stdc++.h>

using namespace std;
template <class T> class UnionFind {
public:
    // stores the parent of each node
    unordered_map<T, T> tree;
    // stores the size of each sub-tree
    unordered_map<T, int> treeSize;
    int numberOfSets = 0;

    bool hasNode(T node) {
        return this->tree.count(node);
    }

    void addNode(T newNode) {
        if (!hasNode(newNode)) {
            this->tree[newNode] = newNode;
            this->treeSize[newNode] = 1;
            this->numberOfSets++;
        }
    }

    void addEdge(T v, T w) {
        addNode(v);
        addNode(w);
        T i = setGetRoot(v);
        T j = setGetRoot(w);
        if (i == j)
            return;
        this->numberOfSets--;
        if (treeSize[i] < treeSize[j]) {
            this->tree[i] = j;
            this->treeSize[j] += this->treeSize[i];
        } else {
            this->tree[j] = i;
            this->treeSize[i] += this->treeSize[j];
        }
    }

    bool areNodesConnected(T v, T w) {
        if (!this->tree.count(v) || !this->tree.count(w))
            return false;
        return setGetRoot(v) == setGetRoot(w);
    }

    int getNumberOfSets() {
        return this->numberOfSets;
    }

private:
    T setGetRoot(T v) {
        while (v != this->tree[v])
            v = this->tree[v] = this->tree[this->tree[v]];
        return v;
    }

};

string input() {
    string ans;
    getline(cin, ans);
    return ans;
}

vector<string> split(string str, char token) {
    stringstream test(str);
    string segment;
    vector<std::string> seglist;

    while (std::getline(test, segment, token))
        seglist.push_back(segment);
    return seglist;
}

/*int main() {
    string str;
    int t;
    t = stoi(input());
    str = input();
    while (t--) {
        auto g = new UnionFind<int>();
        int ac = 0, wa = 0;
        int n;
        n = stoi(input());
        while (n--) {
            g->addEdge(n + 1, n + 1);
        }
        while (true) {
            vector<string> vals = split(input(), ' ');
            if (vals.size() == 0)
                break;
            if (vals[0] == "c") {
                g->addEdge(stoi(vals[1]), stoi(vals[2]));
            }
            if (vals[0] == "q") {
                if (g->areNodesConnected(stoi(vals[1]), stoi(vals[2]))) {
                    ac++;
                }
                else {
                    wa++;
                }
            }
        }
        cout << ac << "," << wa << "\n";
        if (t != 0)
            cout << "\n";
        delete g;
    }
    return 0;
}*/