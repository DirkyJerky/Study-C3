#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "common.h"
#define MAX_BUF 32

void push(int);
int pop();

std::vector<int> vec(0);

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
    vec.push_back(elem);
}

int pop() {
    int elem = vec.back();
    vec.pop_back();
    return elem;
}
