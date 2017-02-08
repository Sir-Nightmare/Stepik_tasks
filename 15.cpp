#include <iostream>
#include <vector>

using namespace std;


int max_subarray(vector<int> a, int &first, int &last) {
    int ans_l = 0;
    int ans_r = 0;
    int n = a.size();
    int max_ending_here = a[0];
    int max_so_far = a[0];


    for (int i = 1; i < n; i++) {
        max_ending_here = max(a[i], max_ending_here + a[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

int main() {
    int n;
    int a[n];
    int ans = a[0],
            ans_l = 0,
            ans_r = 0,
            sum = 0,
            minus_pos = -1;
    for (
            int r = 0;
            r < n;
            ++r) {
        sum += a[r];

        if (sum > ans) {
            ans = sum;
            ans_l = minus_pos + 1;
            ans_r = r;
        }

        if (sum < 0) {
            sum = 0;
            minus_pos = r;

        }
    }
    return 0;
}