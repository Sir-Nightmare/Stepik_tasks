#include <iostream>
#include <math.h>

struct list {
    int field; // поле данных
    struct list *ptr; // указатель на следующий элемент
};


int getElNum(struct list *listptr) {
    struct list *p;
    p = listptr;
    int num = 0;
    while (p != NULL) {
        num++;
        p = p->ptr;
    }
    return num;
}

list *getMergePtr(struct list *listA, struct list *listB) {
    struct list *bigList;
    struct list *smallList;
    int numA = getElNum(listA);
    int numB = getElNum(listB);
    if (numA > numB) {
        bigList = listA;
        smallList = listB;
    } else {
        bigList = listB;
        smallList = listA;
    }
    int delta = abs(numA - numB);
    while (delta > 0) {
        delta--;
        bigList = bigList->ptr;
    }
    while (smallList != NULL) {
        if (bigList == smallList) {
            return smallList;
        }
        bigList = bigList->ptr;
        smallList = smallList->ptr;
    }
    return NULL;
}


int main() {
    struct list *firstList;
    struct list *secondList;
    struct list *mergeList = getMergePtr(firstList, secondList);
    if (mergeList != NULL) {
        std::cout << mergeList->field;
    } else {
        std::cout << "There is no merge point";
    }
    return 0;
}