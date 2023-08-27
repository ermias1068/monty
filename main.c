#include "monty.h"

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

    stack_t *stack = NULL;
    char line[100]; // Adjust the buffer size as needed
    unsigned int line_number = 1;

    while (fgets(line, sizeof(line), file) != NULL) {
        char opcode[10];
        int value;

        if (sscanf(line, "%s %d", opcode, &value) == 2 && strcmp(opcode, "push") == 0) {
            push(&stack, value, line_number);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&stack, line_number);
        }
        
        line_number++;
    }

    fclose(file);
    free_stack(stack);
    return 0;
}

