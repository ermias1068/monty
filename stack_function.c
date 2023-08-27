#include "monty.h"

void push(Stack *stack, int value) {
    if (stack->top < STACK_SIZE) {
        stack->data[stack->top++] = value;
    } else {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
}

void pall(const Stack *stack) {
    for (int i = stack->top - 1; i >= 0; i--) {
        printf("%d\n", stack->data[i]);
    }
}

