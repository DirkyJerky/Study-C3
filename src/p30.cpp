#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "common.h"
#define MAX_BUF 512


void push(int);
int pop();
struct node* makeNode();
int compare(int, int);


struct node {
    int val;
    node *left;
    node *right;
};

node *root = NULL;

int main(int argc, char *argv[]) {
    //TODO: Get 20 ints input
}

void push(struct node* newNode, struct node** base) {

    if(*base == NULL) {
        *base = newNode;
        return;
    }
    
    switch(compare(newNode->val, (*base)->val) ){
        case 1:
            push(newNode, &(*base)->left);
            break;
        case 0:
            return;
        case -1:
            push(newNode, &(*base)->right);
            break;
    }
    //TODO transverse and add
}


int pop() {
    //TODO transverse and delete
}

struct node* makeNode() {
    node *newNode = new node;
    newNode->left = NULL;
    newNode->right = NULL;
}

int compare(int searcher, int anchor) {
    if (searcher < anchor   ) {
        return -1;
    } else if (   anchor < searcher) {
        return 1;
    } else {
        return 0;
    }
}

void printTree(struct node* base, int level) {
    //x --> |
    //      |
    //    y V
    int maxLevels = 5;
    int width = 3;
    int spacing = 2;
}
