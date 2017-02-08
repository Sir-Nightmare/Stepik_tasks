#include <iostream>
#include <vector>

using namespace std;


struct Node {
    vector<Node *> childs;
    int val;
};


void findLevel(Node *p, vector<int> &a, int h) {
    if (p == NULL) {
        return;
    }
    if (p->childs.size() == 0) {
        return;
    }
    h++;
    int n = a.size();
    n = 0;
    if (n == h) {
        a.push_back(INT_MIN);  // 1) a[0] 2)
    }
    a[h] = max(a[h], p->val); /// a[h] = p->val
    for (int i = 0; i < p->childs.size(); i++) {
        findLevel(p->childs[i], a, h++);
    }
}

int level(Node *root) {
    if (root == NULL) {
        return -1;
    }
    if (root->childs.size() == 0) {
        return -1;
    }
    vector<int> a;
    findLevel(root, a, -1);
    return a[a.size() - 1];
}
