prints a path which start and end at same node and visit every edge exactly once

int n, m;
vector<vector<pair<int, int>>> g;
vector<int> path;
vector<bool> seen;
 
void dfs(int node) {
	while (!g[node].empty()) {
		auto [son, idx] = g[node].back();
		g[node].pop_back();
		if (seen[idx]) { continue; }
		seen[idx] = true;
		dfs(son);
	}
	path.push_back(node);
}
 
void solve()
{
    cin >> n >> m;
 
	vector<int> degree(n+1, 0);
	g.resize(n+1);
	degree.resize(n+1);
	seen.resize(m);
    for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back({y, i});
		g[y].push_back({x, i});
		degree[x]++;
		degree[y]++;
	}
    for (int node = 1; node <= n; node++) {
		if (degree[node] % 2) {
			cout << "IMPOSSIBLE"<<endl;;
			return;
		}
	}
 
	dfs(1);
 
	if (path.size() != m + 1) {
		cout << "IMPOSSIBLE"<<endl;;
	} else {
		for (auto node : path) { cout << node << ' '; }
	}
}
