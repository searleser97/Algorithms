#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0);


int Time, top;
vector<vector<int>> ady, sccs;
vector<int> disc, low, s;

void initVars(int N) {ady.assign(N, vector<int>());}

void addEdge(int u, int v) { ady[u].push_back(v);}

void dfsSCCS(int u) {
  if (disc[u]) return;
  low[u] = disc[u] = ++Time;
  s[++top] = u;
  for (int &v : ady[u])
    dfsSCCS(v), low[u] = min(low[u], low[v]);
  if (disc[u] == low[u]) {
    vector<int> scc;
    while (true) {
      int tv = s[top--];
      scc.push_back(tv);
      low[tv] = ady.size();
      if (tv == u) break;
    }
    sccs.push_back(scc);
  }
}


void SCCS() {
	s = low = disc = vector<int>(ady.size());
	Time = 0, top = -1, sccs.clear();
	for (int u = 0; u < ady.size(); u++) dfsSCCS(u);
}

unordered_map<int, int> sccForNode;
unordered_set<int> isEnemy;

vector<int> vis, toposorted;
vector<vector<int>> adyTopo;

void initVarsTopo(int N) {
	adyTopo.assign(N, vector<int>());
	vis.assign(N, 0);
	toposorted.clear();
}

bool toposort(int u) {
  vis[u] = 1;
  for (auto &v : adyTopo[u])
    if (v != u && vis[v] != 2 &&
        (vis[v] || !toposort(v)))
      return false;
  vis[u] = 2;
  toposorted.push_back(u);
  return true;
}

bool toposort() {
  for (int u = 0; u < adyTopo.size(); u++)
    if (!vis[u] && !toposort(u)) return false;
  return true;
}

void addEdgeTopo(int u, int v) { adyTopo[u].push_back(v); }

unordered_set<int> visited;
unordered_map<int, int> sccEnemies;

int ans = 0;

void dfsMalos(int u) {
	if (sccEnemies[u] == -1) return;
	if (sccEnemies[u] > 0) {
		ans += sccs[u].size() - sccEnemies[u];
		sccEnemies[u] = -1;
	} else {
		ans += sccs[u].size();
		sccEnemies[u] = -1;
	}
	for (auto v : adyTopo[u]) dfsMalos(v);
}

void dfs(int u) {
	visited.insert(u);
	for (auto v : adyTopo[u])
		if (!sccEnemies[v]) dfs(v);
}


int main(int argc, char const *argv[])
{
	fastio;

	int S, E, C;
	cin >> S >> E >> C;
	initVars(S);
	while (C--) {
		int u, v;
		cin >> u >> v;
		addEdge(u, v);
	}
	while (E--) {
		int e;
		cin >> e;
		isEnemy.insert(e);
	}

	SCCS();

	

	for (int i = 0; i < sccs.size(); i++) {
		sccEnemies[i] = 0;
		for (auto node : sccs[i]) {
			sccForNode[node] = i;
			if (isEnemy.count(node)) {
				sccEnemies[i]++;
			}
		}
	}

	unordered_map<int, unordered_set<int>> adyAux;

	for (int i = 0; i < S; i++) {
		for (auto v : ady[i]) {
			if (sccForNode[i] != sccForNode[v])
				adyAux[sccForNode[i]].insert(sccForNode[v]);
		}
	}


	initVarsTopo(sccs.size());

	for (auto u : adyAux) {
		for (auto v : u.second) {
			addEdgeTopo(v, u.first);
		}
	}

	for (int u = 0; u < sccs.size(); u++) {
		if (sccEnemies[u] > 0) {
			dfsMalos(u);
		}
	}

	initVarsTopo(sccs.size());

	for (auto u : adyAux) {
		for (auto v : u.second) {
			addEdgeTopo(u.first, v);
		}
	}
	
	toposort();

	reverse(toposorted.begin(), toposorted.end());

	for (auto u : toposorted) {
		if (!visited.count(u) && !sccEnemies[u]) {
			dfs(u);
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}