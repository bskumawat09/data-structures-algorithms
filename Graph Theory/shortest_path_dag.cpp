// Shortest path in weighted DAG
#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

class Solution {
public:
	void topoSort(int u, vector<pair<int,int>> adjList[], vector<bool>& visit, stack<int>& stk) {
		visit[u] = 1;

		for(auto node : adjList[u]) {
			int v = node.second;
			if(!visit[v])
				topoSort(v, adjList, visit, stk);
		}
		stk.push(u);
	}

	vector<int> shortestPath(int src, vector<pair<int, int>> adjList[], int n) {
		vector<bool> visit(n, 0);		// used for finding topological sorting
		stack<int> stk;					// stores topological order

		for(int i=0; i<n; i++) {
			if(!visit[i])
				topoSort(i, adjList, visit, stk);
		}

		vector<int> dist(n, INT_MAX);
		dist[src] = 0;

		while(!stk.empty()) {
			int u = stk.top();
			stk.pop();

			if(dist[u] != INT_MAX) {	// if the current node 'u' is reachable, then only
										// try to minimize the distances of its adjecent nodes
				for(pair<int,int> node : adjList[u]) {
					int v = node.second;
					int w = node.first;

					if(dist[v] > dist[u] + w)
						dist[v] = dist[u] + w;
				}
			}
		}
		return dist;
	}
};

int main() {
	int n, e;
	cin >> n >> e;

	vector<pair<int,int>> adjList[n];

	for(int i=0; i<e; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adjList[a].push_back(make_pair(w, b));
	}

	int src;
	cin >> src;

	Solution sol;
	vector<int> dist = sol.shortestPath(src, adjList, n);

	// printing the distance array
	for(int x : dist)
		cout << x << " ";
	cout << endl;

	return 0;
}

/*
Input:
	6 7
	0 1 2
	1 2 3
	2 3 6
	3 5 1
	4 0 1
	4 2 2
	4 5 4
	1
Output:
	4 0 1 2 3 5			...(Topological ordering)
	INF 0 3 9 INF 10 	...(Distance array)
*/