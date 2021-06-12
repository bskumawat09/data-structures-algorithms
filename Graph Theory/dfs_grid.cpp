#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

class Solution {
public:
    bool isValid(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visit) {
        int r = grid.size();
        int c = grid[0].size();

        if(x < 0 || y < 0 || x >= r || y >= c)
            return false;
        if(visit[x][y] == 1 || grid[x][y] == 0) 
            return false;
        return true;
    }

    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visit) {
        visit[x][y] = 1;

        for(int i=0; i<4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(isValid(newX, newY, grid, visit))    
                dfs(newX, newY, grid, visit);
        }
    }
};

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c));

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    vector<vector<bool>> visit(r, vector<bool>(c, 0));
    int components = 0;

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(!visit[i][j] && grid[i][j] == 1) {
                sol.dfs(i, j, grid, visit);
                components++;
            }
        }
    }
    cout << components << endl;
    return 0;
}
/*
Input:
5 5
    1 1 0 1 1
    1 0 1 1 1
    1 0 0 1 0
    1 1 0 0 1
    0 0 1 1 1
Output:
    3
*/