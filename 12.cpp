#include <iostream>
#include <vector>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int val;
};

void findLevel(Node* p, vector<int>& a, int h) {
    if (p == NULL) {
        return;
    }
    h++;
    int n = a.size();
    if (n == h) {
        a.push_back(0);
    }
    a[h]++;
    findLevel(p->left, a, h);
    findLevel(p->right, a, h);
}

int level(Node* root) {
    if (root == NULL){
        return 0;
    }
    vector<int> a;
    findLevel(root, a, -1);
    int max = 0;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}
