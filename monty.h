#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

typedef struct Stack {
    int data[STACK_SIZE];
    int top;
} Stack;

void push(Stack *stack, int value);
void pall(const Stack *stack);

#endif /* MONTY_H */

