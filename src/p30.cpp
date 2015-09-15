#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "common.h"
#define MAX_BUF 512


void push(struct node*, struct node**);
struct node* makeNode(int);
int compare(int, int);
void menuStart();
void handleMenu(int);
int countLevels();
int getInputNums(int);

enum DISPLAY_TYPE {
    INORDER,
    PREORDER,
    POSTORDER,
    LEAVES,
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
    println("Please enter 10-20 integers");
    int inputsGotten = 0;
    while(inputsGotten < 10) {
        inputsGotten += getInputNums(20 - inputsGotten);
    }

    
    menuStart();
}

int getInputNums(int maximum) {
    std::string input;
    std::getline(std::cin, input);
    std::stringstream stream(input);

    int inputNum; 
    int numInput = 0;
    while((numInput < maximum) && (stream >> inputNum)) {
        push(makeNode(inputNum), &root);
        numInput++;
    }
    return numInput;
}

void menuStart() {
    int code = 0;
    println("Please select an option by entering a number.");
    println("1-3) Display numbers in a...");
    println("    1) Inorder traversal.");
    println("    2) Preorder traversal.");
    println("    3) Postorder traversal.");
    println("4) Add a number to the tree.");
    println("5) Display all the 'Leaves'.");
    println("6) Display the root node");
    println("7) Display the amount of levels in the tree");
    println("8) Exit.");
    do {
        std::cout << ": ";
        std::cin >> code;
        handleMenu(code);
    } while(code != 8);

}

void handleMenu(int code) {
    switch(code) {
        case 1:
            displayTree(root, INORDER);
            std::cout << '\n';
            break;
        case 2:
            displayTree(root, PREORDER);
            std::cout << '\n';
            break;
        case 3:
            displayTree(root, POSTORDER);
            std::cout << '\n';
            break;
        case 4:
            std::cout << "Add Integer: ";
            int additive;
            std::cin >> additive;
            push(makeNode(additive), &root);
            break;
        case 5:
            displayTree(root, LEAVES);
            std::cout << '\n';
            break;
        case 6:
            if(root == NULL) {
                println("Root Node: " << "NULL");
            } else {
                println("Root Node: " << root->val);
            }
            break;
        case 7:
            println("# Levels: " << countLevels());
            break;
        case 8:
            exit(0);
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
        case LEAVES:
            if(base == NULL) return;

            if(base->left == NULL && base->right == NULL) {
                std::cout << base->val << ' ';
            } else {
                displayTree(base->left, LEAVES);
                displayTree(base->right, LEAVES);
            }
            break;
    }
}
static int maxLevel;
void transverseCount(struct node* base, int theLevel) {
    if(base == NULL) return;

    maxLevel = std::max(theLevel, maxLevel);
    transverseCount(base->left, theLevel + 1);
    transverseCount(base->right, theLevel + 1);
}
int countLevels() {
    maxLevel = 0;
    transverseCount(root, 1);
    return maxLevel;
}
