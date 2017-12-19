#include <bits/stdc++.h>

using namespace std;

struct Object {
    char first;
    int second;
};

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << "{" << q.top().first << " " << q.top().second << "}";
        q.pop();
    }
    std::cout << '\n';
}

int main() {
    auto cmp = [](const Object& a, const Object& b) {return a.second > b.second;};
    priority_queue<Object, vector<Object>, decltype(cmp)> pq(cmp);
    vector<Object> v = {{'c',3}, {'a', 1}, {'b', 2}};
    for (auto i : v)
        pq.push(i);
    sort(v.begin(), v.end(), cmp);
    print_queue(pq);
    return 0;
}