#include <bits/stdc++.h>

using namespace std;

class Segment {
public:
    long long int l, r;
    Segment(long long int l, long long int r) {
        this->l = l;
        this->r = r;
    }
};

void printv(vector<Segment> v) {
    for (long long int i = 0; i < v.size(); i++) {
        cout << v[i].l << " " << v[i].r << endl;
    }
}

void _main(long long int T) {
    if (T != 1)
        cout << endl;
    auto cmp = [](const Segment & a, const Segment & b) {return a.l < b.l;};
    long long int M;
    cin >> M;
    vector<Segment> v;
    bool entro = false, flag = false;
    long long int l, r;
    while (true) {
        cin >> l;
        cin >> r;
        if (l == 0 && r == 0)
            break;
        v.push_back(Segment(l, r));
    }
    if (v.size() == 0) {
        cout << 0 << endl;
        return;
    }
    sort(v.begin(), v.end(), cmp);

    if (v[v.size() - 1].r < M) {
        cout << 0 << endl;
        return;
    }

    vector<Segment> allSelected;
    Segment selected(0, 0);

    long long int i = 0;

    while (v[i].l <= 0 && i < v.size()) {
        if (v[i].r > selected.r)
            selected = v[i];
        entro = true;
        i++;
    }

    if (!entro) {
        cout << 0 << endl;
        return;
    }

    allSelected.push_back(selected);

    if (selected.r >= M) {
        cout << allSelected.size() << endl;
        printv(allSelected);
        return;
    }

    entro = false;
    l = selected.l;
    r = selected.r;


    for (; i < v.size();) {
        while (v[i].l >= l && v[i].l <= r && i < v.size()) {
            if (v[i].r >= M)
                flag = true;
            if (v[i].r > selected.r)
                selected = v[i];
            entro = true;
            i++;
        }
        if (!entro) {
            cout << 0 << endl;
            return;
        }
        allSelected.push_back(selected);
        entro = false;
        l = selected.l;
        r = selected.r;
        if (flag) {
            cout << allSelected.size() << endl;
            printv(allSelected);
            return;
        }
    }
    cout << 0 << endl;
}

int main() {
    long long int T;
    cin >> T;
    for (long long int i = 1; i <= T; i++) {
        _main(i);
    }
    return 0;
}