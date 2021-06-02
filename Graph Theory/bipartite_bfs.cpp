#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	bool checkBipartite(int src, vector<int> adjList[], vector<bool>& visit, vector<int>& color) {
		queue<int> q;
		visit[src] = true;
		color[src] = 0; 
		q.push(src);

		while(!q.empty()) {
			int u = q.front();
			q.pop();

			for(int v : adjList[u]) {
				if(!visit[v]) {
					visit[v] = true;
					q.push(v);
					color[v] = color[u] ^ 1;
				}
				else if(color[u] == color[v])
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
				if(checkBipartite(i, adjList, visit, color) == false)
					return false;
			}
		}
		return true;
	}
};

int main() {
	int n = 8;	// no. of nodes
	int e = 6;	// no. of edges

	vector<int>adjList[n];

	int edgeList[][2] = {{0,1},{1,2},{1,3},{3,4},{5,6},{5,7}};

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