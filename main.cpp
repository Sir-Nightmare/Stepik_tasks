#include <iostream>

using namespace std;

inline int triNum(long long input) {
    int n = 1;
    int triangleNumber = 0;
    while (triangleNumber < input) {
        triangleNumber = n * (n + 1) / 2;
        if (triangleNumber == input) {
            return n;
        }
        n++;
    }
    return 0;
}

int foo() {
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
    printf("%d", foo());
    return 0;
}