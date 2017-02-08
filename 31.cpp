int main() {
    int n;
    int a[n - 1];
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum+=a[i];
    }
    int num = n*(n+1)/2 -sum;
    return 0;
}
