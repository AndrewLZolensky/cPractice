#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "customer.h"

void print_customer(customer* c) {
    if (c == NULL) {
        printf("Nothing to print\n");
        return;
    }
    printf("Customer named: %s with id: %d\n", c->name, c->id);
}

int add_customer(customer** ptr2head, int id, char* name) {

    // create new customer on the heap
    customer* new_customer = malloc(sizeof(customer));
    if (new_customer == NULL) {
        printf("Error in customer.c: add_customer() failed\n");
        return(1);
    }
    new_customer->id = id;
    new_customer->name = malloc(strlen(name)+1);
    if (new_customer->name == NULL) {
        printf("Error in customer.c: add_customer() failed\n");
        return(1);
    }
    strcpy(new_customer->name, name);
    new_customer->next = NULL;

    // if list empty, allocate head
    if (*ptr2head == NULL) {
        *ptr2head = new_customer;
        return(0);
    }

    // otherwise, traverse list until end and then add customer
    customer* c = *ptr2head;
    while (c->next != NULL) {
        c = c->next;
    }
    c->next = new_customer;

    return(0);
}

void print_list(customer** ptr2head) {
    customer* c = *ptr2head;

    // if no customers to print, alert and return
    if (c == NULL) {
        printf("Nothing to print\n");
        return;
    }

    //otherwise print customers until none left
    print_customer(c);
    while (c->next != NULL) {
        c = c->next;
        print_customer(c);
    }
}

void delete_list(customer** head) {
    customer *c1 = *head;
    customer *c2 = *head;

    //if list empty, altert and return
    if (c1 == NULL) {
        printf("Nothing to delete\n");
        return;
    }

    //otherwise, traverse and delete
    while(c1 != NULL) {

        // set c2 ahead one node (possibly null)
        c2 = c1->next;

        // delete current node (pointed to by c1)
        free(c1->name);
        free(c1);

        // move ahead (catch c1 up to c2)
        c1 = c2;
    }

    // set head pointer to NULL
    *head = NULL;
}