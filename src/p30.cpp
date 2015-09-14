#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "common.h"
#define MAX_BUF 512


void push(struct node*, struct node**);
int pop();
struct node* makeNode(int);
int compare(int, int);
void menuStart();
void handleMenu(int);

enum DISPLAY_TYPE {
    INORDER,
    PREORDER,
    POSTORDER,
    LEAVES,
    COUNT_LEVELS
};

void displayTree(struct node* base, DISPLAY_TYPE displayType);

struct node {
    int val;
    node *left;
    node *right;
};

node *root = NULL;

//MAIN
int main(int argc, char *argv[]) {
    //println("Please enter 10-20 integers");
    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
        node *newNode = makeNode(rand() % 100);
        push(newNode, &root);
    }
    demo_void(displayTree(root, PREORDER));
    println('\n');
    demo_void(displayTree(root, INORDER));
    println('\n');
    demo_void(displayTree(root, POSTORDER));
    println('\n');
    
    menuStart();
}

void menuStart() {
    int code = 0;
    println("Please select an option by entering a number.");
    do {
        println('\n' << 
                "1-3) Display numbers in a...");
        println("    1) Inorder traversal.");
        println("    2) Preorder traversal.");
        println("    3) Postorder traversal.");
        println("4) Add a number to the tree.");
        println("5) Display all the 'Leaves'.");
        println("6) Display the root node");
        println("7) Display the amount of levels in the tree");
        println("8) Exit.");
        std::cout << ": ";
        std::cin >> code;
        handleMenu(code);
    } while(code != 8);

}

void handleMenu(int code) {
    switch(code) {
        case 1:
            displayTree(root, INORDER);
            break;
        case 2:
            displayTree(root, PREORDER);
            break;
        case 3:
            displayTree(root, POSTORDER);
            break;
        case 4:
            if(root == NULL) {
                println("Root Node: " << "NULL");
            } else {
                println("Root Node: " << root->val);
            }
            break;
        case 5:
            displayTree(root, LEAVES);
            break;
        case 6:
            break;
        case 7:
            displayTree(root, COUNT_LEVELS);
            break;
        case 8:
            ;
            break;
    }
}

void push(struct node* newNode, struct node** base) {

    if(*base == NULL) {
        *base = newNode;
        return;
    }
    
    switch(compare(newNode->val, (*base)->val) ){
        case -1:
            push(newNode, &(*base)->left);
            break;
        case 0:
            return;
        case 1:
            push(newNode, &(*base)->right);
            break;
    }
    //TODO transverse and add
}

struct node* makeNode(int value) {
    node *newNode = new node;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->val = value;
    return newNode;
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

void displayTree(struct node* base, DISPLAY_TYPE displayType) {
    if(base == NULL) return;

    switch(displayType) {
        case PREORDER:
            printf("%d ", base->val);
            displayTree(base->left, displayType);
            displayTree(base->right, displayType);
            break;
        case INORDER:
            displayTree(base->left, displayType);
            printf("%d ", base->val);
            displayTree(base->right, displayType);
            break;
        case POSTORDER:
            displayTree(base->left, displayType);
            displayTree(base->right, displayType);
            printf("%d ", base->val);
            break;
        
    }
}
