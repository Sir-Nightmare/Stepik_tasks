#include <iostream>

using namespace std;

int foo() {
    long long input = 0;
    int is_double = 0;
    if (scanf("%llu.%d", &input, &is_double) != 1) {
        if (is_double != 0) {
            while (true) {

            }
        }
    }
    return 0;
}


int main() {
    printf("%d", foo());
    return 0;
}