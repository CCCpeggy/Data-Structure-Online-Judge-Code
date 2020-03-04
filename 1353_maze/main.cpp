#include <iostream>
#include <vector>
using namespace std;
int m, n;

int find(vector<int*> path, vector<vector<bool>> gone, int i = 0, int j = 0) {
    if (i == m - 1 && j == n - 1 && (!gone[i+1][j+1])) {
        for (int ii = 0; ii < path.size(); ii++) {
            cout << "(" << path[ii][0] << "," << path[ii][1] << "),";
        }
        cout << "(" << i << "," << j << ")" << endl;
        return 1;
    }
    else if ((!gone[i+1][j+1])) {
        gone[i+1][j+1] = true;
        path.push_back(new int[2]{ i, j });
        int found = 0;
        if ((!gone[i][j+1]) && find(path, gone, i - 1, j)) found = 1;
        if ((!gone[i+1][j]) && find(path, gone, i, j - 1)) found = 1;
        if ((!gone[i+1][j+2]) && find(path, gone, i, j + 1)) found = 1;
        if ((!gone[i+2][j+1]) && find(path, gone, i + 1, j)) found = 1;
        return found;
    }
    return 0;
}

int main() {
    while (cin >> m && cin >> n) {
        char* inputNum = new char[n + 1];
        vector<vector<bool>> gone(m + 2);
        vector<int*> path;
        for (int i = 0; i < m+2; i++) gone[i].resize(n + 2, true);

        for (int i = 0; i < m; i++) {
            cin >> inputNum;
            for (int j = 0; j < n; j++) {
                gone[i+1][j+1] = inputNum[j] == '0' ? false : true;
            }
        }
        if (!find(path, gone)) cout << "No path\n";
    }
}