#include <iostream>


struct node {
    int field; // поле данных
    struct node *next; // указатель на следующий элемент
};


void reverse_list(node *head, node *current) {
    node *pred;
    while (current != NULL) {
        node *nextNode = current->next;
        current->next = pred;
        pred = current;
        current = nextNode;
    }
    head = pred;
}