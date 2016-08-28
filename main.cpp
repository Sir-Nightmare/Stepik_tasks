#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

long long triNum(long long input) {
    long long n = llround(sqrt(input) * sqrt(2));
    if (n * (n + 1) / 2 == input) {
        return n;
    } else if (n * (n - 1) / 2 == input) {
        return n - 1;
    }
    return 0;
}

long long int foo() {
    long long input = 0;
    int is_double = 0;
    if (scanf("%llu.%d", &input, &is_double) == 1) {
        if (input > 0) {
            return triNum(input);
        }
    }
    return 0;
}


int main() {
    printf("%lli", foo());
    return 0;
}