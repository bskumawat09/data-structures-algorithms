#include <iostream>
#include <vector>
using namespace std;

bool checkForCycle(int u, int parent, vector<int>adjList[], vector<bool>&visit) {
	visit[u] = true;

	for(int v : adjList[u]) {
		if(!visit[v]) {
			if(checkForCycle(v, u, adjList, visit))
				return true;
		}
		else if(v != parent)
			return true;
	}
	return false;
}

bool hasCycle(vector<int>adjList[], int n) {
	vector<bool> visit(n, false);

	for(int i=0; i<n; i++) {
		if(!visit[i]) {
			if(checkForCycle(i, -1, adjList, visit))
				return true;
		}
	}
	return false;
}

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

	cout << (hasCycle(adjList, n) ? "Has cycle" : "Doesn't has cycle") << endl;
}