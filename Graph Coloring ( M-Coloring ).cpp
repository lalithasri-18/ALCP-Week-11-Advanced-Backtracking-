#include <iostream>
using namespace std;

int graph[20][20], color[20];
int n, m;

bool safe(int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && color[i] == c)
            return false;
    }
    return true;
}

bool solve(int v) {
    if (v == n)
        return true;

    for (int c = 1; c <= m; c++) {
        if (safe(v, c)) {
            color[v] = c;

            if (solve(v + 1))
                return true;

            color[v] = 0;
        }
    }
    return false;
}

int main() {
    cout << "Enter vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    cout << "Enter number of colors: ";
    cin >> m;

    if (solve(0)) {
        cout << "Coloring possible\n";
        for (int i = 0; i < n; i++)
            cout << "Vertex " << i
                 << " = Color " << color[i] << endl;
    } else {
        cout << "Coloring not possible";
    }

    return 0;
}
