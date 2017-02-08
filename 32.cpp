#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isAnarg(string a, string b) {
    if (a.length() != b.length()) {
        return false;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}
void show(vector<string> strArr){
    int n = strArr.size();
    vector<bool> checked(n);
    for (int i = 0; i < n; i++) {
        if (!checked[i]) {
            bool hasAn = false;
            for (int j = i + 1; j < n; j++) {
                if (!checked[i]) {
                    if (isAnarg(strArr[i], strArr[j])){
                        cout << strArr[j] << ' ';
                        hasAn = true;
                        checked[j]= true;
                    }
                }
            }
            if (hasAn){
                cout << strArr[i] << endl;
            }
        }
    }
}
int main() {
    int n;
    string strArr[n];

    return 0;
}
