#include <iostream>

using namespace std;

pair<int, int> matrixFind(int a[n][m], int int target, int n, int m) {

    if (target < a[0][0] or target > a[n - 1][m - 1])
        return make_pair(-1, -1);
    int row = 0;
    int col = m - 1;
    while (row <= n - 1 and col >= 0)
        if (a[row][col] < target)
            row++;
        else if (a[row][col] > target)
            col--;
        else
            return make_pair(row, col);
    return make_pair(-1, -1);
}