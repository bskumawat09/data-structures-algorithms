#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	void prims(vector<pair<int,int>> adjList[], int n) {
		vector<bool> mst(n, 0);			// to mark the nodes that are part of MST
		vector<int> parent(n, -1);		// stores parent of each node so that MST can be constructed
		vector<int> weight(n, INT_MAX);	// to calculate total cost of MST

		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
		pq.push({0,0});
		weight[0] = 0;

		while(!pq.empty()) {
			int u = pq.top().second;
			pq.pop();
			mst[u] = true;

			for(pair<int,int> it : adjList[u]) {
				int v = it.second;
				int w = it.first;

				if(mst[v] == false && weight[v] > w) {
					weight[v] = w;
					parent[v] = u;
					pq.push({w,v});
				}
			}
		}

		int cost = 0;
		for(int x : weight)
			cost += x;
		cout << cost << endl;	// total cost of MST

		for(int x : parent)		// parent of each node, to construct MST
			cout << x << " ";
		cout << endl;
	}
};

int main() {
	int n, e;
	cin >> n >> e;

	vector<pair<int,int>> adjList[n];

	for(int i=0; i<e; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adjList[a].push_back({w,b});
		adjList[b].push_back({w,a});
	}

	Solution sol;
	sol.prims(adjList, n);
	return 0;
}

/*
Input:
	4 5
	0 1 4
	0 2 1
	0 3 3
	1 3 5
	2 3 2
Output:
	7
	-1 0 0 2 
*/