#include <stdio.h>
#include <stdlib.h>

struct node {
    float coef;
    int expo;
    struct node* next;

};

struct node* head