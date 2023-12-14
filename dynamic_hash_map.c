#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "customer.h"

// Dynamic allocation of hash map
int main() {
    customer** my_table;
    char name[15];
    int id, bucket, buckets, failure;
    char more_data[2];

    // decide how big to make hash table
    printf("How many buckets should we initialize?\n");
    scanf("%d", &buckets);

    // malloc hash table (my table -> [ll_ptr_1, ll_ptr_2, ...])
    my_table = malloc(sizeof(customer*) * buckets);
    if (my_table == NULL) {
        printf("Error in main(): malloc() failed\n");
    }

    // set all head pointers to NULL
    for (int i = 0; i < buckets; i++) {
        my_table[i] = NULL;
    }

    while(1) {
        printf("Enter a customer name and id\n");
        scanf("%9s %d", name, &id);
        bucket = id % buckets;
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

    for (int i = 0; i < buckets; i++) {
        printf("Linked list at bucket %d with contents:\n", i);
        print_list(&my_table[i]);
        printf("\n");
    }

    for (int i = 0; i < buckets; i++) {
        delete_list(&my_table[i]);
    }

    return(0);
}