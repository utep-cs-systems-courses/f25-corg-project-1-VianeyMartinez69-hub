#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main() {
    List *history = init_history();
    char input[256];

    while (1) {
        printf("Enter a string (history = show, !n = recall, quit = exit): ");
        if (!fgets(input, sizeof(input), stdin)) break;
        input[strcspn(input, "\n")] = 0; // strip newline

        if (strcmp(input, "quit") == 0) break;

        if (strcmp(input, "history") == 0) {
            print_history(history);
            continue;
        }

        if (input[0] == '!') {
            int id = atoi(&input[1]);
            char *recall = get_history(history, id);
            if (recall) {
                printf("Recalled #%d: %s\n", id, recall);
                char **tokens = tokenize(recall);
                print_tokens(tokens);
                free_tokens(tokens);
            } else {
                printf("No history entry with id %d\n", id);
            }
            continue;
        }

        // Normal input: save it to history and tokenize
        add_history(history, input);

        char **tokens = tokenize(input);
        printf("Tokens:\n");
        print_tokens(tokens);
        free_tokens(tokens);
    }

    printf("\nFinal history:\n");
    print_history(history);
    free_history(history);
    return 0;
}
