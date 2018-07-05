// 11094 - Continents
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Point;
char landSymbol;
int M, N, y, x;
int biggest = 0;
vector< vector<int> > movs = {
    {1, 0},
    {0, 1},
    { -1, 0},
    {0, -1}
};

bool isValid(Point &point, vector< vector<bool> > &visited, vector< vector<char> > &mat) {
    if (point.first < 0 || point.first >= M)
        return false;

    if (mat[point.first][point.second] != landSymbol)
        return false;
    if (visited[point.first][point.second])
        return false;

    visited[point.first][point.second] = true;
    return true;
}

int bfs(Point start, vector< vector<bool> > &visited, vector< vector<char> > &mat) {
    if (!isValid(start, visited, mat))
        return 0;
    int localBiggest = 0;
    queue<Point> q;
    q.push(start);
    while (!q.empty()) {
        localBiggest++;
        Point point = q.front(); q.pop();
        for (int i = 0; i < movs.size(); i++) {
            int newX = (point.second + movs[i][1]) % N;
            if (newX == -1)
                newX = N - 1;
            Point nextPoint = { point.first + movs[i][0],  newX};
            if (isValid(nextPoint, visited, mat))
                q.push(nextPoint);
        }
    }
    return localBiggest;
}

int main() {
    while (cin >> M >> N) {
        vector< vector<char> > mat(M, vector<char>(N));
        vector< vector<bool> > visited(M, vector<bool>(N));

        for (int i = 0; i < M; i++)
            for (int j = 0;  j < N; j++)
                cin >> mat[i][j];

        cin >> y >> x;
        landSymbol = mat[y][x];
        bfs({y, x}, visited, mat);

        for (int i = 0; i < M; i++)
            for (int j = 0;  j < N; j++)
                if (!visited[i][j]) {
                    int thisBig = bfs({i, j}, visited, mat);
                    if (biggest < thisBig)
                        biggest = thisBig;
                }

        cout << biggest << endl;
        biggest = 0;
    }
}