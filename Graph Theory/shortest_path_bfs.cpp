// Single source shortest path in undirected graph using BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	void bfs(int src, vector<int> adjList[], vector<int>& dist) {
		queue<int> q;
		q.push(src);
		dist[src] = 0;

		while(!q.empty()) {
			int u = q.front();
			q.pop();

			for(int v : adjList[u]) {
				if(dist[v] == -1) {
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}
	}

	vector<int> sssp(vector<int> adjList[], int n) {
		vector<int> d(n, -1);

		for(int i=0; i<n; i++) {
			if(d[i] == -1) 
				bfs(i, adjList, d);
		}
		return d;
	}
};

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    
	int n, e;
	cin >> n >> e;

	vector<int> adjList[n];

	for(int i=0; i<e; i++) {
		int a, b;
		cin >> a >> b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	Solution sol;
	vector<int> dist = sol.sssp(adjList, n);

	for(int x : dist)
		cout << x << " ";
	cout << endl;
	return 0;
}

/* 
Input:
	7 8
	0 1
	0 2
	0 4
	1 2
	2 3
	3 5
	4 6

Output:
	0 1 1 2 1 3 2 
*/