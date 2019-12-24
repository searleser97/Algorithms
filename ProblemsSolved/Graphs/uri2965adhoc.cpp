// 16
/****************************************************
https://searleser97.gitlab.io/algorithms/template.cpp
****************************************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define forn(_, x, n) for (int _ = x; _ < n; _++)
#define rep(_, n) forn(_, 0, n)

vector<vector<int>> adj;
int N, K;
vector<int> parent, height, largerChild, deleted;
priority_queue<pair<int, int>> pq;

int calcHeight(int u) {
  if (height[u]) return height[u];
  for (auto &v : adj[u]) {
    if (calcHeight(v) > height[u]) {
      largerChild[u] = v;
      height[u] = calcHeight(v);
    }
  }
  return ++height[u]; 
}

void _main(int tc) {
  cin >> N >> K;
  parent.assign(N, 0);
  height.assign(N, 0);
  deleted.assign(N, 0);
  largerChild.assign(N, -1);
  adj.resize(N);
  forn(i, 1, N) {
    cin >> parent[i];
    adj[--parent[i]].push_back(i);
  }
  forn(i, 0, N) calcHeight(i);
   
  forn(i, 0, N) pq.push({height[i], i});

  int ans = 0;
  int deletedCount = 0;
  while (!pq.empty()) {
    pair<int, int> top = pq.top(); pq.pop();
    int height = top.first;
    int u = top.second;
    if (deleted[u]) continue;
    deleted[u] = 1;
    while ((u = largerChild[u]) != -1) deleted[u] = 1;
    ans += height;
    deletedCount++;
    if (K == deletedCount) break;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  _main(0); return 0;
}
