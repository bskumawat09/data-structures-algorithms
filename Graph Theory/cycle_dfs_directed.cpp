// Detect a cycle in directed graph using DFS
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool checkCycle(int u, vector<int> adjList[], vector<bool>& visit, vector<bool>& dfsVisit) {
		visit[u] = 1;
		dfsVisit[u] = 1;	// mark dfsVisit to "1" for current dfs() call

		for(int v : adjList[u]) {
			if(!visit[v]) {
				if(checkCycle(v, adjList, visit, dfsVisit))
					return true;
			}
			else if(dfsVisit[v])
				return true;
		}
		dfsVisit[u] = 0;	// mark dfsVisit back to "0" once the current dfs() call gets over
		return false;
	}

	bool hasCycle(vector<int> adjList[], int n) {
		vector<bool> visit(n, 0);
		vector<bool> dfsVisit(n, 0);

		for(int i=0; i<n; i++) {
			if(!visit[i]) {
				if(checkCycle(i, adjList, visit, dfsVisit))
					return true;
			}
		}
		return false;
	}
};

int main() {
	int n = 9;	// no. of nodes
	int e = 10;	// no. of edges

	vector<int>adjList[n];

	int edgeList[][2] = {{0,1},{1,2},{2,3},{3,4},{2,5},{5,4},{6,1},{6,7},{7,8},{8,6}};

	// input the graph
	for(int i=0; i<e; i++) {
		int a = edgeList[i][0];
		int b = edgeList[i][1];

		adjList[a].push_back(b);
	}

	Solution sol;
	bool isCyclic = sol.hasCycle(adjList, n);

	cout << (isCyclic ? "Has a cycle" : "Doesn't has cycle") << endl;

	return 0;
}

/*
Output:
	0-> 1 
	1-> 2 
	2-> 3 5 
	3-> 4 
	4-> 
	5-> 4 
	6-> 1 7 
	7-> 8 
	8-> 6 
	Has a cycle
*/