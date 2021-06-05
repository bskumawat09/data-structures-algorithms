// Dijkstra's algorithm for SSSP in weighted undirected graph
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

class Solution {
public:
	void bfs(int src, vector<pair<int,int>> adjList[], vector<int>& dist) {
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
		dist[src] = 0;
		pq.push({0, src});

		while(!pq.empty()) {
			int u = pq.top().second;
			int d = pq.top().first;
			pq.pop();

			for(pair<int,int> node : adjList[u]) {
				int w = node.first;
				int v = node.second;

				if(dist[v] > d + w) {
					dist[v] = d + w;
					pq.push({d+w, v});
				}
			}
		}
	}

	vector<int> dijkstra(int src, vector<pair<int,int>> adjList[], int n) {
		vector<int> dist(n, INT_MAX);
		bfs(src, adjList, dist);
		return dist;
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

	vector<pair<int,int>> adjList[n+1];

	for(int i=0; i<e; i++) {
		int a, b, w;
		cin >> a >> b >> w;

		adjList[a].push_back({w, b});
		adjList[b].push_back({w, a});
	}
	int src;
	cin >> src;

	Solution sol;
	vector<int> dist = sol.dijkstra(src, adjList, n+1);

	for(int x : dist)
		cout << x << " ";
	cout << endl;
	return 0;
}

/*
Input:
	5 6
	1 2 2
	1 4 1
	2 3 4
	2 5 5
	3 4 3
	3 5 1
	1

Output:
	2147483647 0 2 4 1 5 
*/