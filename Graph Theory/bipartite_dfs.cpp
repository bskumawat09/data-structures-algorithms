#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool checkBipartite(int u, vector<int> adjList[], vector<bool>& visit, vector<int>& color) {
		visit[u] = true;

		for(int v : adjList[u]) {
			if(!visit[v]) {
				color[v] = color[u] ^ 1;		// firstly color the node, then call dfs() on it

				if(checkBipartite(v, adjList, visit, color) == false)
					return false;
			}
			else if(color[v] == color[u]) {
				cout << u << "->" << v << endl;	// edge forming a cycle
				return false;
			}
		}
		return  true;
	}

	bool isBipartite(vector<int>adjList[], int n) {
		vector<bool> visit(n, false);
		vector<int> color(n, -1);

		for(int i=0; i<n; i++) {
			if(!visit[i]) {
				color[i] = 0;

				if(checkBipartite(i, adjList, visit, color) == false)
					return false;
			}
		}
		return true;
	}
};

int main() {
	int n = 8;	// no. of nodes
	int e = 7;	// no. of edges

	vector<int>adjList[n];

	int edgeList[][2] = {{0,1},{1,2},{1,3},{3,4},{5,6},{5,7},{6,7}};

	// input the graph
	for(int i=0; i<e; i++) {
		int a = edgeList[i][0];
		int b = edgeList[i][1];

		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	Solution sol;
	bool ans = sol.isBipartite(adjList, n);
	cout << (ans ? "Bipartite" : "Not bipartite") << endl;

	return 0;
}