// Topological sorting in DAG(Directed Acyclic Graph) using BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	void bfs(vector<int> adjList[], vector<int>& inDegree, vector<int>& topo) {
		queue<int> q;
		int n = inDegree.size();

		for(int i=0; i<n; i++) {			// initially insert all the nodes having 0 in-degree
			if(inDegree[i] == 0)
				q.push(i);
		}

		while(!q.empty()) {
			int u = q.front();
			q.pop();
			topo.push_back(u);

			for(int v : adjList[u]) {		// push the node into the queue when its in-degree becomes 0
				inDegree[v]--;

				if(inDegree[v] == 0)
					q.push(v);
			}
		}
	}

	vector<int> topoSort(vector<int> adjList[], int n) {
		vector<int> topo;
		vector<int> inDegree(n, 0);

		for(int i=0; i<n; i++) {			// initialize in-degree of every node in graph
			for(int node : adjList[i])		// also works if multiple components are there
				inDegree[node]++;
		}

		bfs(adjList, inDegree, topo);
		return topo;
	}
};

int main() {
	int n, e;
	cin >> n >> e;

	vector<int> adjList[n];

	for(int i=0; i<e; i++) {
		int a, b;
		cin >> a >> b;

		adjList[a].push_back(b);
	}

	Solution sol;
	vector<int> topo = sol.topoSort(adjList, n);

	for(int x : topo)
		cout << x << " ";
	cout << endl;
	return 0;
}

/*
Input:
	9 8
	0 2
	2 1
	1 3
	4 2
	4 3
	3 5
	7 6
	7 8

Output:
	0 4 7 2 6 8 1 3 5 
*/