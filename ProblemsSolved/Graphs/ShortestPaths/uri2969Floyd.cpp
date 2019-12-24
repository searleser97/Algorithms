// 18
/****************************************************
https://searleser97.gitlab.io/algorithms/template.cpp
****************************************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define forn(_, x, n) for (int _ = x; _ < n; _++)
#define rep(_, n) forn(_, 0, n)
#define fi first
#define se second
#define pb push_back
#define lli __int128_t
#define li long long int
#define ld long double
#define parii pair<int, int>

struct pairhash {
  template <class T1, class T2> size_t operator()(const pair<T1, T2> &p) const {
    return hash<T1>{}(p.first) ^ (hash<T2>{}(p.second) << 32);
  }
};

struct Order {
  int a, b, index;
};

vector<li> ans;
vector<pair<li, int>> planets;
unordered_map<parii, vector<Order>, pairhash> orders;

typedef long long int T;
li inf = (1ll << 62) - 1ll, isDirected = false;
vector<vector<T>> d;

void initVars(int n) {
  d.assign(n, vector<T>(n, inf));
  forn(i, 0, n) d[i][i] = 0;
  planets.assign(n, {});
  orders.clear();
}

void addEdge(int u, int v, T w) { d[u][v] = w; d[v][u] = w; }

void floyd(int flag) {
  vector<vector<T>> dist = d;
  if (!flag)
    sort(planets.begin(), planets.end());
  else
    sort(planets.begin(), planets.end(),
         [](const pair<li, int> &a, const pair<li, int> &b) {
           return b.fi < a.fi;
         });
  unordered_map<li, int> Map;
  int mapId = 0;
  for (auto &i : planets) {
    if (!Map.count(i.fi))
      Map[i.fi] = mapId++;
  }

  forn(k, 0, d.size()) {
    forn(u, 0, d.size()) {
      forn(v, 0, d.size()) {
        if (dist[u][planets[k].se] != inf && dist[planets[k].se][v] != inf)
          dist[u][v] =
              min(dist[u][v], dist[u][planets[k].se] + dist[planets[k].se][v]);
      }
    }

    if (orders.count({Map[planets[k].fi], flag}))
      for (auto &order : orders[{Map[planets[k].fi], flag}]) 
        if (dist[order.a][order.b] != inf)
          ans[order.index] = dist[order.a][order.b];
  }

  while (mapId < d.size()) {
    if (orders.count({mapId, flag}))
      for (auto &order : orders[{mapId, flag}]) 
        if (dist[order.a][order.b] != inf)
          ans[order.index] = dist[order.a][order.b];
    mapId++;
  }
}

// 13
void _main(int tc) {
  int N, R;
  cin >> N >> R;
  initVars(N);
  forn(i, 0, N) {
    li tmp;
    cin >> tmp;
    planets[i] = {tmp, i};
  }

  forn(i, 0, R) {
    li x, y, d;
    cin >> x >> y >> d;
    addEdge(--x, --y, d);
  }

  int Q;
  cin >> Q;
  ans.assign(Q, -1);
  forn(i, 0, Q) {
    int a, b, k, t;
    cin >> a >> b >> k >> t;
    orders[{--k, t}].pb({--a, --b, i});
  }

  floyd(0);
  floyd(1);
  for (auto &i : ans) {
    cout << i << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  _main(0);
  return 0;
  int tc;
  cin >> tc;
  rep(i, tc) _main(i + 1);
  return 0;
}
