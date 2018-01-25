#include <bits/stdc++.h>
using namespace std;

typedef int T;
typedef char Y;

vector<vector<int>> movs = {
    {1, 0},
    {0, 1},
    { -1, 0},
    {0, -1}
};

void floodFill(Y oldColor, Y color, vector<vector<T>> &matrix, int i, int j) {
    if (i >= matrix.size() || i < 0 || j >= matrix[i].size() || j < 0)
        return;
    if (matrix[i][j] != oldColor)
        return;
    matrix[i][j] = color;
    for (auto move : movs)
        floodFill(oldColor, color, matrix, i + move[1], j + move[0]);
}

int main() {
    vector<vector<int>> screen = {{1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 1, 0},
        {1, 1, 1, 0, 0, 0},
        {1, 1, 1, 0, 1, 0},
        {1, 1, 1, 1, 1, 1}
    };

    floodFill(0, 2, screen, 3, 3);

    for (int i = 0; i < screen.size(); i++) {
        for (int j = 0; j < screen[i].size(); j++) {
            cout << screen[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

