#include <iostream>

struct node {
    int field; // поле данных
    struct node *next; // указатель на следующий элемент
};


bool checkLoop(node *root) {
    if (root == NULL)
        return false;
    node *agentA = root;
    node *agentB = root->next;
    while (true) {

        if (agentA == agentB)
            return true;

        if (agentA == NULL || agentB == NULL || agentB->next == NULL)
            return false;

        agentA = agentA->next;
        agentB = agentB->next->next;
    }
}