#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "common.h"
#define MAX_BUF 512


void push(int);
int pop();


struct node {
    int val;
    node *back;
};

node *top;

int main(int argc, char *argv[]) {
    demo_void(push(1));
    demo_void(push(2));
    demo_void(push(3));
    demo_void(push(4));
    demo_void(push(5));
    demo_int(pop());
    demo_int(pop());
    demo_int(pop());
    demo_int(pop());
    demo_int(pop());
}

void push(int elem) {
    node *newNode = new node;

    if(top == NULL) {
        newNode->back = NULL;
    } else {
        newNode->back = top;
    }

    newNode->val = elem;
    top = newNode;
}

int pop() {
    int val = top->val;

    node *ripTop = top;
    top = ripTop->back;
    delete ripTop;

    return val;
}
