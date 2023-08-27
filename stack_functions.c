#include "monty.h"

void push(stack_t **stack, int value, unsigned int line_number) {
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (*stack != NULL) {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    } else {
        new_node->next = NULL;
    }

    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number) {
    stack_t *current = *stack;
    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void free_stack(stack_t *stack) {
    while (stack != NULL) {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }
}

