#include <iostream>
using namespace std;

int a[9][9];

bool safe(int r, int c, int num) {
    for (int i = 0; i < 9; i++) {
        if (a[r][i] == num || a[i][c] == num)
            return false;
    }

    int x = (r / 3) * 3;
    int y = (c / 3) * 3;

    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            if (a[i][j] == num)
                return false;
        }
    }
    return true;
}

bool solve() {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {

            if (a[r][c] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (safe(r, c, num)) {
                        a[r][c] = num;

                        if (solve())
                            return true;

                        a[r][c] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    cout << "Enter Sudoku (0 for empty):\n";

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> a[i][j];

    if (solve()) {
        cout << "Solved Sudoku:\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution";
    }

    return 0;
}
