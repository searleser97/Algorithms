#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > movs = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

struct Pos {
    char val;
    bool visited;
    int y, x;
    int distance;
};

bool isValidPos(vector<vector<Pos>> &matrix, int y, int x) {
    if (y >= matrix.size() || y < 0 || x >= matrix[0].size() || x < 0)
        return false;
    if (matrix[y][x].val == '*')
        return false;
    if (matrix[y][x].visited)
        return false;
    matrix[y][x].visited = true;
    return true;
}

void bfs(vector<vector<Pos>> &matrix, int startY, int startX) {
    queue<Pos> q;
    q.push(matrix[startY][startX]);
    matrix[startY][startX].visited = true;
    while (!q.empty()) {
        Pos currentPos = q.front();
        q.pop();
        if (matrix[currentPos.y][currentPos.x].val == '#') {
            cout << currentPos.distance << endl;
            return;
        }
        for (int i = 0; i < movs.size(); i++) {
            int nextYPos = currentPos.y + movs[i][0];
            int nextXPos = currentPos.x + movs[i][1];
            while (isValidPos(matrix, nextYPos, nextXPos)) {
                matrix[nextYPos][nextXPos].distance = matrix[nextYPos - movs[i][0]][nextXPos - movs[i][1]].distance + 1;
                q.push(matrix[nextYPos][nextXPos]);
                nextYPos = nextYPos + movs[i][0];
                nextXPos = nextXPos + movs[i][1];
            }
        }
    }
    cout << -1 << endl;
}


void _main(int T) {
    int m, n, startY, startX;
    cin >> m >> n;
    vector<vector<Pos>> matrix(m, vector<Pos>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char val;
            cin >> val;
            if (val == '$') {
                startY = i;
                startX = j;
            }
            matrix[i][j] = {val, false, i, j, 0};
        }
    }

    bfs(matrix, startY, startX);
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
        _main(T);

    return 0;
}