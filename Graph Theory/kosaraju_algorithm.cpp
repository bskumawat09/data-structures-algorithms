#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<int> adj[], vector<bool>& visit, stack<int>& stk) {
	visit[u] = 1;
	for(int v : adj[u]) {
		if(!visit[v])
			dfs(v, adj, visit, stk);
	}
	stk.push(u);
}

void dfs2(int u, vector<int> trp[], vector<bool>& visit) {
	visit[u] = 1;
	for(int v : trp[u]) {
		if(!visit[v])
			dfs2(v, trp, visit);
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

	int n, e;
	cin >> n >> e;
	vector<int> adj[n];		// stores graph
	vector<int> trp[n];		// stores transpose graph

	for(int i=0; i<e; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		trp[b].push_back(a);
	}

	stack<int> stk;
	vector<bool> visit(n, 0);

	for(int i=0; i<n; i++) {	// run dfs to order the nodes according to their increasing
		if(!visit[i])			// out-time
			dfs(i, adj, visit, stk);
	}

	for(int i=0; i<n; i++)
		visit[i] = 0;

	int countScc = 0;

	while(!stk.empty()) {
		int node = stk.top();
		stk.pop();

		if(!visit[node]) {
			countScc++;
			dfs2(node, trp, visit);
		}
	}
	cout << countScc << endl;
	return 0;
}

/*
Input:
	7 9
	0 1
	1 2
	2 0
	2 3
	3 6
	3 4
	4 5
	5 6
	6 4
Output:
	3
*/