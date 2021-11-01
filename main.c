#include <stdio.h>
#include <mm_malloc.h>
#include <stdlib.h>


struct doubleList {
    int key;
    double value;
    struct doubleList* next;
    struct doubleList* previous;
};

struct doubleList* init() {
    struct doubleList *last;
    last = (struct doubleList *) malloc(sizeof(struct doubleList));
    last -> key = 0;
    last -> value = 0.0;
    last -> next = NULL;
    last -> previous = NULL;
    return last;
}

int isEmpty(struct doubleList* list) {
    if (list -> next == NULL)
        return 1;
    return 0;
}

struct doubleList* createElement(double newValue, int newKey) {
    struct doubleList* newElement;
    newElement = (struct doubleList*) malloc(sizeof(struct doubleList));
    newElement -> key = newKey;
    newElement -> value = newValue;
    newElement -> next = NULL;
    newElement -> previous = NULL;
    return newElement;


void push(struct doubleList* L, struct doubleList* elem) {
    if (isEmpty(L) != 0) {
    elem -> previous = L;
    L -> next -> previous  = elem;
    elem -> next = L -> next;
    L -> next = elem;
    } else {
        L -> next = elem;
        elem -> previous = L;
    }
}

void listPop(struct doubleList* L, int delKey) {
    if (isEmpty(L))
        return;
    struct doubleList* cur = L -> next;
    while ((cur != NULL) && (cur -> key != delKey))
        cur = cur -> next;
    if (cur != NULL) {
        cur -> previous -> next = cur -> next;
        if (cur -> next != NULL)
            cur -> next -> previous = cur -> previous;
        free(cur);
    }
}

void insertKey(struct doubleList* L, struct doubleList* inElem, int inKey) {
    if (isEmpty(L))
        return;
    struct doubleList* cur = L -> next;
    while ((cur != NULL) && (cur -> key != inKey))
        cur = cur -> next;
    if (cur != NULL) {
        inElem -> next = cur -> next;
        inElem -> previous = cur -> previous;
        free(cur);
    }
}

void printList(struct doubleList* list) {
    struct doubleList* current = list -> next;
    while (current != NULL) {
        printf ("%d: %1.0f\n", current -> key, current -> value);
        current = current -> next;
    }
}


//void insertKey(struct doubleList* list, struct doubleList* inElem, int inKey) {
//    if (isEmpty(list))
//        return ;
//    struct doubleList* pointer = list -> next;
//    while (pointer && (pointer -> key != inKey))
//        pointer = pointer -> next;
//
//    if (pointer != NULL) {
//        inElem -> next = pointer -> next;
//        pointer -> next = inElem;
//    }
//}

void createFiveElements() {
    struct doubleList* list;
    list = init();
    for (int i = 0; i < 6; i++) {
        struct doubleList* newElement = createElement(i*i, i);
        push(list,newElement);
    }
    printList(list);
}

int isCircle(struct doubleList* L) {
    struct doubleList* rbt = L -> next;
    struct doubleList* trl = L;
    while ((rbt != NULL) && (rbt != trl)) {
        if (rbt -> next == trl)
            break;
        if (rbt -> next != NULL)
            rbt = rbt -> next -> next;
        else
            rbt = NULL;
        trl = trl->next;
    }
    return rbt != NULL;
}

int main() {
    struct doubleList* list5;
    list5 = init();
    createFiveElements();
    return 0;
}
