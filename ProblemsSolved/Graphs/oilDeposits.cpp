#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> movs = {
    {1, 0},
    {0, 1},
    { -1, 0},
    {0, -1},
    {1, 1},
    { -1, 1},
    {1, -1},
    { -1, -1}
};

bool valid(vector<vector<char>> &mat, int i, int j, vector<vector<bool>> &visited) {
    if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size())
        return false;
    if (visited[i][j])
        return false;
    if (mat[i][j] == '*')
        return false;
    visited[i][j] = true;
    return true;
}

typedef pair<int, int> Point;

void bfs(vector<vector<char>> &mat, Point point, vector<vector<bool>> &visited, int &count) {
    if (!valid(mat, point.first, point.second, visited))
        return;
    count++;
    queue<Point> q;
    q.push(point);
    while (!q.empty()) {
        Point point = q.front(); q.pop();
        for (auto move : movs) {
            Point newPoint = {point.first + move[0], point.second + move[1]};
            if (valid(mat, newPoint.first, newPoint.second, visited)) {
                q.push(newPoint);
            }
        }
    }
}

int main() {
    int m, n;
    while (true) {
        cin >> m;
        if (!m)
            return 0;
        cin >> n;

        vector<vector<char>> mat(m, vector<char>(n));
        vector<vector<bool>> visited(m, vector<bool>(n));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bfs(mat, {i, j}, visited, count);
            }
        }
        cout << count << endl;
    }
    return 0;
}