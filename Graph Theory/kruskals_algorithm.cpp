#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge 
{
public:
	int u, v, w;
	Edge(int u, int v, int w) 
	{
		this->u = u;
		this->v = v;
		this->w = w;
	}
};

int findParent(int node, vector<int>& parent) 
{
	if(parent[node] == node)
		return node;
	return parent[node] = findParent(parent[node], parent);
}

void unionByRank(int a, int b, vector<int>& parent, vector<int>& rank) 
{
	a = findParent(a, parent);
	b = findParent(b, parent);

	if(rank[a] < rank[b])
		parent[a] = b;

	else if(rank[a] > rank[b])
		parent[b] = a;

	else {
		parent[b] = a;
		rank[a]++;
	}
}

int kruskal(vector<Edge>& edges, int n) 
{
	vector<pair<int,int>> mst;
	vector<int> parent(n);
	vector<int> rank(n, 0);
	int cost = 0;

	for(int i=0; i<n; i++)	// initialize the parent array
		parent[i] = i;

	// sort the edges according to their weights
	sort(edges.begin(), edges.end(), [](Edge e1, Edge e2){return e1.w < e2.w;});

	for(auto it : edges) 
	{
		// if an edge is not forming cycle then inclue it into MST
		if(findParent(it.u, parent) != findParent(it.v, parent)) 
		{
			cost += it.w;
			mst.push_back({it.u, it.v});
			unionByRank(it.u, it.v, parent, rank);
		}
	}
	cout << cost << endl;	// print the total cost of MST
	for(auto it : mst)		// print the MST
		cout << it.first << " " << it.second << endl;

	return cost;
}

int main() 
{
	int n, e;
	cin >> n >> e;

	vector<Edge> edges;

	for(int i=0; i<e; i++) 
	{
		int a, b, w;
		cin >> a >> b >> w;
		edges.push_back(Edge(a, b, w));
	}

	kruskal(edges, n);

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
	0 2
	2 3
	0 1
*/