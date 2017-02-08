#include <iostream>

using namespace std;

int main() {
    int n = 5;
    int m = 3;
    int a[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = i + j;
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    int amount = n - m + 1;
    int sums[amount][amount] = {};
    int sumsLine[m][amount] = {};
    for (int i = 0; i < m; i++) {
        sumsLine[i][0] = 0;
        for (int j = 0; j < m; j++) {
            sumsLine[i][0] += a[i][j];
        }
        for (int j = 1; j < amount; j++) {
            sumsLine[i][j] = sumsLine[i][j - 1] - a[i][j - 1] + a[i][j - 1 + m];
        }
    }


    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < amount; ++j) {
            cout << sumsLine[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < m; ++i) {
            sums[0][j] += sumsLine[i][j];
        }
    }


    int r = 0;

    for (int i = 1; i < amount; ++i) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += a[i + m - 1][j];
        }
        cout << sum << ' ' << sumsLine[r][0] << endl;
        sums[i][0] = sums[i - 1][0] - sumsLine[r][0] + sum;
        for (int j = 0; j < amount; ++j) {

//            for (int k = 1; k < amount; j++) {
//                sumsLine[j][k] = sumsLine[j][k - 1] - a[j][k - 1] + a[j][k - 1 + m];
//            }
        }
        if (r == amount - 1) {
            r = 0;
        } else {
            r++;
        }
    }
    cout << endl;
    for (int i = 0; i < amount; ++i) {
        for (int j = 0; j < amount; ++j) {
            cout << sums[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}