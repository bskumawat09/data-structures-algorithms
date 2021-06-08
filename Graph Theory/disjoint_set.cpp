#include <iostream>
#include <vector>
using namespace std;

int findParent(int node, vector<int>& parent) {
	if(parent[node] == node)
		return node;
	return parent[node] = findParent(parent[node], parent);	// path compression
}

void unionByRank(int a, int b, vector<int>& parent, vector<int>& rank) {
	int pa = findParent(a, parent);
	int pb = findParent(b, parent);

	if(rank[pa] > rank[pb])
		parent[pb] = pa;

	else if(rank[pa] < rank[pb])
		parent[pa] = pb;

	else {
		parent[pb] = pa;
		rank[pa]++;
	}
}

int main() {
	int n = 6;
	vector<int> parent(n);
	vector<int> rank(n, 0);

	for(int i=0; i<n; i++)
		parent[i] = i;

	unionByRank(1, 2, parent, rank);
	unionByRank(2, 3, parent, rank);
	unionByRank(0, 1, parent, rank);
	unionByRank(4, 5, parent, rank);
	unionByRank(3, 5, parent, rank);

	for(int it : parent)
		cout << it << " ";
	cout << endl;

	for(int it : rank)
		cout << it << " ";
	cout << endl;

	return 0;
}