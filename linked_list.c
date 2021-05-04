#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "linked_list.h"


NODE* create_list(NODE* head) {

    int i, num_of_nodes, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_of_nodes);
    if (head == NULL);
    do {
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        head = addatbeg(head, data);
    } while (--num_of_nodes);
    return head;
}

NODE* addatbeg(NODE* head, int data) {

    NODE* new_node = malloc(sizeof(NODE));

    new_node->data = data;
    new_node->next = head;

    /* Assign newnode as the new head, since adding to beginning*/
    head = new_node;
    return head;
}

NODE* addatend(NODE* head, int data) {

    NODE* new_node = malloc(sizeof(NODE));

    NODE* ptr = head;
    new_node->data = data;

    /* Traverse until the end of the list */
    while (ptr->next != NULL)
        ptr = ptr->next;
    /* assign the new node to the last node*/
    ptr->next = new_node;
    new_node->next = NULL;
    return head;
}

NODE* del(NODE* head, int data) {
    NODE* temp = head, *ptr;
    if (head == NULL) {
        printf("The list is empty!\n\n");
        return head;
    }
    int count = 0;
    /*Iterate until last node*/
    while (temp != NULL) {
        if (temp->data == data) {
            if (count == 0) {
                /* if the first node needs deletion but it's the only one*/
                if (temp->next == NULL) {
                    free(head);
                    head = NULL;
                    return head;
                }
                /* if heads needs deletion but it isn't the only node*/
                head = head->next;
                free(temp);
                return head;
            }
            /* Upadte previous pointer to point past the current one that you want deleted*/
            ptr->next = temp->next;
            free(temp);
            return head;
        }
        count++;
        ptr = temp;
        temp = temp->next;
    }
    printf("Element %d, not found!\n\n", data);
    return head;
}

NODE* addafter(NODE* head, int data, int item) {

    NODE* new_node = malloc(sizeof(NODE)), *ptr = head;

    while (ptr != NULL) {
        /* stop when you find the node you're looking for*/
        if (ptr->data == item) {
            new_node->next = ptr->next;
            new_node->data = data;
            ptr->next = new_node;
            return head;
        }
        ptr = ptr->next;
    }
    printf("%d is not present in the list\n\n", item);
}

NODE* addbefore(NODE* head, int data, int item) {

    NODE* new_node = malloc(sizeof(NODE)), *ptr = head, *temp = head;

    while (ptr != NULL) {
        if (ptr->data == item) {
            new_node->next = ptr;
            new_node->data = data;
            temp->next = new_node;
            return head;
        }
        temp = ptr;
        ptr = ptr->next;
    }
}

NODE* addatpos(NODE* head, int data, int pos) {

    NODE* ptr = head, * prev;
    int element = 1;

    while (ptr != NULL) {
        if (element == pos) {
            head = addbefore(head, data, ptr->next->data);
            head = del(head, ptr->data);
            return head;
        }
        ptr = ptr->next;
        element++;
    }
}

NODE* reverse(NODE* head) {

    NODE* ptr, * next, * prev;
    prev = NULL;
    ptr = head;

    while (ptr != NULL) {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    head = prev;
    return head;
}

void destroy_list(NODE* head) {

    NODE* ptr = head, *prev;
    /* destroy the list*/
    /*if (head == NULL) {
        printf("List is empty\n\n");
        return;
    }
    while (ptr != NULL) {
        prev = ptr->next;
        free(ptr);
        ptr = prev;
    }*/
    while (ptr != NULL) {
        ptr = del(ptr, ptr->data);
    }
}

void search(NODE* head, int data) {

    NODE* ptr = head;
    int element = 1;

    while (ptr != NULL) {
        if (ptr->data == data) {
            printf("Node %d was found at position %d\n\n", data, element);
            return;
        }
        element++;
        ptr = ptr->next;
        return;
    }
    printf("element was not found\n\n");
}

void display(NODE* head) {

    if (head == NULL)
    {
        printf("List is empty\n\n");
        return;
    }
    NODE* ptr = head;

    printf("list is ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}

void count(NODE* head) {

    if (head == NULL) {
        printf("List is empty\n\n");
        return;
    }
    NODE* ptr = head;
    int counter = 0;

    while (ptr != NULL) {
        counter++;
        ptr = ptr->next;
    }
    printf("number of nodes is %d\n\n", counter);
}

