#include <bits/stdc++.h>

using namespace std;

vector<string> mat;
vector<string> vis;
int n, width, height;
int iAsterisk, jAsterisk;

string input() {
    string ans;
    getline(cin, ans);
    return ans;
}

vector<vector<int>> movs = {
    {1, 0},
    {0, 1},
    { -1, 0},
    {0, -1}
};

void dfs(int i, int j, int previ, int prevj) {
    if (i < 0 || j < 0 || i >= (height) || j >= (width + 1)
            || vis[i][j] == 'V' || mat[i][j] == '#' || mat[i][j] == '*'
            || mat[i][j] == '_')
        return;
    if (mat[i][j] != ' ') {
        mat[previ][prevj] = '#';
        return;
    }
    else
        vis[i][j] = 'V';
    for (auto &mov : movs) {
        dfs(i + mov[0], j + mov[1], i, j);
    }
}

int main() {
    n = stoi(input());
    while (n--) {
        height = 0, width = 0, mat = vector<string>(50, string(100, ' '));
        vis = vector<string>(50, string(100, 'U'));
        string underscores;
        while (true) {
            string str = input();
            if (str[0] == '_') {
                underscores = str;
                break;
            }
            for (int i = 0; i < str.size(); i++) {
                if (str[i] == '*')
                    iAsterisk = height, jAsterisk = i;
                else
                    mat[height][i] = str[i];
            }
            height++;
            width = max((int) str.size(), width);
        }
        dfs(iAsterisk, jAsterisk, -1, -1);
        for (int i = 0; i < (height); i++) {
            string out = "";
            for (int j = 0; j < (width + 1); j++) {
                out.push_back(mat[i][j]);
            }

            bool flag3 = true;

            for (int k = out.size() - 1; k > -1; k--)
                if (out[k] == ' ' && flag3)
                    out.pop_back();
                else
                    flag3 = false;
                cout << out << endl;
        }
        cout << underscores << endl;
    }
}