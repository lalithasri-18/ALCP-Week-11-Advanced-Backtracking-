#include <iostream>
#include <string>
using namespace std;

int maze[20][20], visited[20][20];
int n, countPaths = 0;

void solve(int r, int c, string path) {
    if (r == n - 1 && c == n - 1) {
        cout << path << endl;
        countPaths++;
        return;
    }

    visited[r][c] = 1;

    // Down
    if (r + 1 < n && maze[r + 1][c] == 1
        && visited[r + 1][c] == 0)
        solve(r + 1, c, path + "D");

    // Left
    if (c - 1 >= 0 && maze[r][c - 1] == 1
        && visited[r][c - 1] == 0)
        solve(r, c - 1, path + "L");

    // Right
    if (c + 1 < n && maze[r][c + 1] == 1
        && visited[r][c + 1] == 0)
        solve(r, c + 1, path + "R");

    // Up
    if (r - 1 >= 0 && maze[r - 1][c] == 1
        && visited[r - 1][c] == 0)
        solve(r - 1, c, path + "U");

    visited[r][c] = 0;
}

int main() {
    cout << "Enter maze size: ";
    cin >> n;

    cout << "Enter maze (1=open, 0=blocked):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];

    if (maze[0][0] == 1 &&
        maze[n - 1][n - 1] == 1)
        solve(0, 0, "");

    if (countPaths == 0)
        cout << "No path exists";
    else
        cout << "Total paths: " << countPaths;

    return 0;
}
