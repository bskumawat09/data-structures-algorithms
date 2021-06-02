#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100

vector<int> adjList[MAX];
vector<bool> visit(MAX, 0);

void bfs(int node) {
	queue<int> q;
	visit[node] = true;
	q.push(node);

	while(!q.empty()) {
		int u = q.front();
		q.pop();
		cout << u << " ";

		for(int v : adjList[u]) {
			if(!visit[v]) {
				visit[v] = true;
				q.push(v);
			}
		}
	}
}

void printGraph(int n) {
	for(int i=0; i<n; i++) {
		cout << i << "-> ";
		for(int v : adjList[i])
			cout << v << " ";
		cout << endl;
	}
}

int main() {
	int n = 6;	// no. of nodes
	int e = 5;	// no. of edges

	int edgeList[][2] = {{0,1},{2,3},{2,4},{3,4},{3,5}};

	// input the graph
	for(int i=0; i<e; i++) {
		int a = edgeList[i][0];
		int b = edgeList[i][1];

		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	printGraph(n);

	int components = 0;

	// calls bfs() for every component
	for(int i=0; i<n; i++) {
		if(!visit[i]) {
			bfs(i);
			components++;
		}
	}

	cout << '\n' << components << endl;

	return 0;
}

/*
Output:
	0 1 2 3 4 5 
	2
*/