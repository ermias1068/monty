#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

typedef struct Stack {
    int data[STACK_SIZE];
    int top;
} Stack;

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

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    Stack stack;
    stack.top = 0;

    char opcode[10];
    int value;

    while (fscanf(file, "%s", opcode) != EOF) {
        if (strcmp(opcode, "push") == 0) {
            if (fscanf(file, "%d", &value) != 1) {
                fprintf(stderr, "Error: Usage: push integer\n");
                fclose(file);
                return EXIT_FAILURE;
            }
            push(&stack, value);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&stack);
        } else {
            fprintf(stderr, "Error: Unknown opcode: %s\n", opcode);
            fclose(file);
            return EXIT_FAILURE;
        }
    }

    fclose(file);
    return 0;
}

