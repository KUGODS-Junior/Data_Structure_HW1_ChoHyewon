#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void* dataPtr;
    struct node* next;
}NODE;

typedef struct stack {
    NODE* head;
    NODE* tail;
    int cnt = 0;
    int size = 100;
}STACK;

STACK* makeStack() {
    // TODO
    STACK* s = (STACK*)malloc(sizeof(STACK));

    s->head = NULL;
    s->tail = NULL;
    s->cnt = 0;
    s->size = 100;

    return s;
}

int pushStack(STACK* s, int data) {
    // TODO
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    if (s->cnt >= s->size) {
        return 1;
    }

    int* d = (int*)malloc(sizeof(int));
    *d = data;
    temp->dataPtr = d;

    temp->next = s->head;
    s->head = temp;

    if (s->tail == NULL) {
        s->tail = temp;
    }
    (s->cnt++);

    return 0;
}

int isEmpty(STACK* s) {
    return s->cnt <= 0;   
}

int popStack(STACK* s) {
    // TODO
    if (isEmpty(s)) {
        return 1;
    }

    NODE* temp = s->head; 

    s->head = temp->next; 
    int rd = *(int*)(temp->dataPtr);
    free(temp); 
    if (s->head == NULL) {
        s->tail = NULL;

    }
    s->cnt--;
    return rd;
}




void traverse(STACK* s) {
    // TODO
    NODE* temp = s->head;

    while (temp != NULL) {
        printf("%d ", *(int*)(temp->dataPtr));
        temp = temp->next;
    }
    printf("\n");

}

STACK* concat(STACK* s1, STACK* s2) {
    // TODO
    STACK* s3 = makeStack();

    while (s1->head != NULL && s2->head != NULL) {
        if (*(int*)(s1->head->dataPtr) >= *(int*)(s2->head->dataPtr)) {
            pushStack(s3, *(int*)(s1->head->dataPtr));
            popStack(s1);
        }
        else {
            pushStack(s3, *(int*)(s2->head->dataPtr));
            popStack(s2);
        }
    }

    while (s1->head == NULL && s2->head != NULL) {
        pushStack(s3, *(int*)(s2->head->dataPtr));
        popStack(s2);
    }

    while (s1->head != NULL && s2->head == NULL) {
        pushStack(s3, *(int*)(s1->head->dataPtr));
        popStack(s1);
    }

    free(s1);
    free(s2);

    return s3;

}

int main() {
    STACK* s1 = makeStack();
    STACK* s2 = makeStack();

    pushStack(s1, 9);
    pushStack(s1, 4);
    pushStack(s1, 2);
    pushStack(s1, 6);
    pushStack(s1, 5);
    pushStack(s2, 3);
    pushStack(s2, 1);
    pushStack(s2, 7);


    // HW 1-1
    while (s1->cnt > 0) {
        traverse(s1);
        popStack(s1);
    }
    printf("--------------------------\n");

    // HW 1-2
    while (s2->cnt > 0) {
        traverse(s2);
        popStack(s2);
    }
    printf("--------------------------\n");

    pushStack(s1, 9);
    pushStack(s1, 4);
    pushStack(s1, 2);
    pushStack(s1, 6);
    pushStack(s1, 5);
    pushStack(s2, 3);
    pushStack(s2, 1);
    pushStack(s2, 7);

    // HW2
    STACK* s3 = concat(s1, s2);
    traverse(s3);

    free(s3);

    return 0;

}
