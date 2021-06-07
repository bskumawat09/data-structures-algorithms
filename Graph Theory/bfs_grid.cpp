#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

class Solution {
public:
	bool isValid(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visit) {
		int r = grid.size();
		int c = grid[0].size();

		if(x < 0 || y < 0 || x >= r || y >= c)	// if cell is out-of bounds
			return false;
		if(visit[x][y] == 1)	// if cell is already visited
			return false;
		if(grid[x][y] == 0)		// if there is blockage on grid
			return false;
		return true;
	}

	void bfs(int srcX, int srcY, 
		vector<vector<int>>& grid, vector<vector<bool>>& visit, vector<vector<int>>& dist) {
		
		queue<pair<int,int>> q;
		visit[srcX][srcY] = 1;
		dist[srcX][srcY] = 0;
		q.push({srcX, srcY});

		while(!q.empty()) {
			int curX = q.front().first;
			int curY = q.front().second;
			q.pop();

			for(int i=0; i<4; i++) {
				int newX = curX + dx[i];
				int newY = curY + dy[i];

				if(isValid(newX, newY, grid, visit)) {
					visit[newX][newY] = 1;
					dist[newX][newY] = 1 + dist[curX][curY];
					q.push({newX, newY});
				}
			}
		}
	}

	vector<vector<int>> bfsTraversal(vector<vector<int>>& grid) {
		int r = grid.size();
		int c = grid[0].size();
		vector<vector<bool>> visit(r, vector<bool> (c, 0));
		vector<vector<int>> dist(r, vector<int> (c, 0));
		int compo = 0;

		for(int i=0; i<r; i++) {
			for(int j=0; j<c; j++) {
				if(!visit[i][j] && grid[i][j] == 1) {
					bfs(i, j, grid, visit, dist);
					compo++;
				}
			}
		}
		cout << compo << endl;
		return dist;
	}
};

int main() {
	int r, c;
	cin >> r >> c;

	vector<vector<int>> grid;

	for(int i=0; i<r; i++) {
		vector<int> row;
		for(int j=0; j<c; j++) {
			int k;
			cin >> k;
			row.push_back(k);
		}
		grid.push_back(row);
	}

	Solution sol;
	vector<vector<int>> dist = sol.bfsTraversal(grid);

	for(int i=0; i<r; i++) {
		for(int j : dist[i])
			cout << j << " ";
		cout << endl;
	}
	return 0;
}

/*
Input:
	5 5
	1 1 0 1 1
	1 0 1 1 1
	1 0 0 1 0
	1 1 1 0 1
	0 0 1 1 1

Output:
	2
	0 1 0 0 1 
	1 0 2 1 2 
	2 0 0 2 0 
	3 4 5 0 9 
	0 0 6 7 8 
*/