// Topological sorting in DAG(Directed Acyclic Graph) using DFS
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	void dfs(int u, vector<int> adjList[], vector<bool>& visit, stack<int>& stk) {
		visit[u] = 1;

		for(int v : adjList[u]) {
			if(!visit[v])
				dfs(v, adjList, visit, stk);
		}
		stk.push(u);
	}

	vector<int> topoSort(vector<int> adjList[], int n) {
		vector<int> topo;
		vector<bool> visit(n, 0);
		stack<int> stk;
		
		for(int i=0; i<n; i++) {
			if(!visit[i])
				dfs(i, adjList, visit, stk);
		}
		while(!stk.empty()) {
			topo.push_back(stk.top());
			stk.pop();
		}
		return topo;
	}

	void printTopoSort(vector<int>& topo) {
		for(int x : topo)
			cout << x << " ";
		cout << endl;
	}
};

int main() {
	int n = 6;	// no. of nodes
	int e = 8;	// no. of edges

	vector<int>adjList[n];

	int edgeList[][2] = {{0,1},{0,2},{1,2},{1,3},{4,2},{4,3},{4,5},{5,3}};

	// input the graph
	for(int i=0; i<e; i++) {
		int a = edgeList[i][0];
		int b = edgeList[i][1];
		adjList[a].push_back(b);
	}

	Solution sol;
	vector<int> topo = sol.topoSort(adjList, n);
	sol.printTopoSort(topo);

	return 0;
}

/*
Output:
	0-> 1 2
	1-> 2 3
	2-> 
	3->  
	4-> 2 3 5
	5-> 3 
	
	4 5 0 1 3 2 
*/