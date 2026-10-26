#include <iostream>
using namespace std;

int graph[20][20], path[20];
int n;

bool safe(int v, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return false;
    }
    return true;
}

bool solve(int pos) {
    if (pos == n) {
        return graph[path[n - 1]][0] == 1;
    }

    for (int v = 1; v < n; v++) {
        if (safe(v, pos)) {
            path[pos] = v;

            if (solve(pos + 1))
                return true;

            path[pos] = -1;
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

    for (int i = 0; i < n; i++)
        path[i] = -1;

    path[0] = 0;

    if (solve(1)) {
        cout << "Hamiltonian Cycle: ";
        for (int i = 0; i < n; i++)
            cout << path[i] << " ";

        cout << 0;
    } else {
        cout << "No Hamiltonian Cycle";
    }

    return 0;
}
