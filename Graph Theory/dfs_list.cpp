#include <iostream>
#include <vector>
using namespace std;

#define MAX 100

vector<int> adjList[MAX];
vector<bool> visit(MAX, false);

void dfs(int u) {
	cout << u << " ";
	visit[u] = true;

	for(int v : adjList[u]) {
		if(!visit[v]) {
			dfs(v);
		}
	}
}

int main() {
	int n = 6;	// no. of nodes
	int e = 7;	// no. of edges

	int edgeList[][2] = {{0,1},{2,3},{2,4},{3,4},{3,5}, {4,6}, {5,7}};

	// input the graph
	for(int i=0; i<e; i++) {
		int a = edgeList[i][0];
		int b = edgeList[i][1];

		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	int components = 0;

	// calls dfs() for every component
	for(int i=0; i<n; i++) {
		if(!visit[i]) {
			dfs(i);
			components++;
		}
	}

	cout << '\n' << components << endl;
	
	return 0;
}

/*
Output:
	0 1 2 3 4 6 5 7
	2
*/