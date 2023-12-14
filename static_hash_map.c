#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "customer.h"

#define BUCKETS 3

// Static allocation of hash map
int main() {
    customer* my_table [BUCKETS];
    for (int i = 0; i < BUCKETS; i++) {
        my_table[i] = NULL;
    }
    char name [10]; int id, bucket, failure;
    char more_data[2];

    while(1) {
        printf("Enter a customer name and id\n");
        scanf("%9s %d", name, &id);
        bucket = id % BUCKETS;
        failure = add_customer(&my_table[bucket], id, name);
        if (failure) {
            printf("main() failed to add customer\n");
        }
        printf("Would you like to enter more data? (y/n)\n");
        scanf("%1s", more_data);
        if (strcmp(more_data, "y") != 0) {
            break;
        }
    }
    
    for (int i = 0; i < BUCKETS; i++) {
        printf("Linked list at bucket %d with contents:\n", i);
        print_list(&my_table[i]);
        printf("\n");
    }

    for (int i = 0; i < BUCKETS; i++) {
        delete_list(&my_table[i]);
    }

    return(0);
}