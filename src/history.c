#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

/* Initialize the linked list to keep the history. */
List* init_history() {
    List *list = malloc(sizeof(List));
    list->root = 0;
    return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str) {
    static int next_id = 1;
    Item *newItem = malloc(sizeof(Item));
    newItem->id = next_id++;
    newItem->str = strdup(str);
    newItem->next = 0;

    if (!list->root){
        list->root = newItem;
    }
    else{
        Item *curr = list->root;
        while(curr->next) curr = curr->next;
        curr->next = newItem;
    }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id) {
    Item *curr = list->root;
    while(curr){
        if(curr->id == id) return curr->str;
        curr = curr->next;
    }
    return 0;
}

/*Print the entire contents of the list. */
void print_history(List *list) {
    Item *curr = list->root;
    while(curr){
        printf("%d: %s\n", curr->id, curr->str);
        curr = curr->next;
    }
}

/*Free the history list and the strings it references. */
void free_history(List *list) {
    Item * curr = list->root;
    while(curr){
        Item *next = curr->next;
        free(curr->str);
        free(curr);
        curr = next;
    }
    free(list);
}
