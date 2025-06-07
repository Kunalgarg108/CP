#include <bits/stdc++.h>
using namespace std;

int dir[8][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
vector<vector<pair<int,int>>> Answer;
void BFS(vector<vector<int>>& grid, vector<vector<int>>& vis, int x, int y) {
    vector<pair<int,int>> subans;
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;
    subans.push_back({x,y});
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        int cx=it.first;
        int cy=it.second;
        for (int i = 0; i < 8; i++) {
            int nx = cx + dir[i][0];
            int ny = cy + dir[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && vis[nx][ny] == 0) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
                subans.push_back({nx,ny});
            }
        }
    }
    Answer.push_back(subans);
}

int countIslands(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && vis[i][j] == 0) {
                BFS(grid, vis, i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        cout << countIslands(grid) << endl;
    }
    return 0;
}


/*
Input:5
3 3
1 1 0
1 1 0
0 0 1
4 5
1 1 0 0 0
1 1 0 0 1
0 0 1 0 1
1 0 0 0 1
4 4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
3 4
1 1 1 1
1 0 0 1
1 1 1 1
*/

/*
Output
1
3
1
0
1
*/
