#include <iostream>
using namespace std;

int col[20], d1[40], d2[40];
int n;

int solve(int row) {
    if (row == n)
        return 1;

    int count = 0;

    for (int c = 0; c < n; c++) {
        int x = row + c;
        int y = row - c + n - 1;

        if (col[c] == 0 && d1[x] == 0 && d2[y] == 0) {
            col[c] = 1;
            d1[x] = 1;
            d2[y] = 1;

            count += solve(row + 1);

            col[c] = 0;
            d1[x] = 0;
            d2[y] = 0;
        }
    }
    return count;
}

int main() {
    cout << "Enter N: ";
    cin >> n;

    cout << "Number of solutions: " << solve(0);

    return 0;
}
