#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "common.hpp"
#define MAX_BUF 512


void push(int);
int pop();


struct node {
    int val;
    node *next;
};

node *top = NULL;
node *back = NULL;

int main(int argc, char *argv[]) {
    demo_void(push(44));
    demo_void(push(31));
    demo_void(push(164));
    demo_void(push(34));
    demo_void(push(-41));
    demo_int(pop());
    demo_int(pop());
    demo_int(pop());
    demo_int(pop());
    demo_int(pop());
}

void push(int elem) {
    node *newNode = new node;

    if(back != NULL) {
        back->next = newNode;
    } else {
        top = newNode;
    }

    newNode->val = elem;
    newNode->next = NULL;
    back = newNode;
}

int pop() {
    int val = top->val;

    node *ripTop = top;
    top = ripTop->next;
    delete ripTop;

    return val;
}
