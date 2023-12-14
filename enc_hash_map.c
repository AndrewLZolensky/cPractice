#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customer_hash.h"

int hash_by_ID (void* table, void* key) {

    // cast table
    customer_hash_table *my_table = table;
    int *id = key;

    // handle null hash table
    if (my_table == NULL) {
        printf("Error in customer_hash.c: hash_by_ID() failed\n");
        return(-1);
    }

    // otherwise hash
    int buckets = my_table->num_of_buckets;
    int bucket = (*id) % buckets;


    return(bucket);
}

int hash_by_name (void* table, void* key) {

    // cast table
    customer_hash_table *my_table = table;
    char *name = key;

    // handle NULL case
    if (my_table == NULL || name == NULL) {
        printf("Error in customer_hash.c: hash_by_name() failed\n");
        return(-1);
    }

    // otherwise hash by first letter of name
    int buckets = my_table->num_of_buckets;
    char first_letter = name[0];
    int bucket = first_letter - 0x41;
    bucket = bucket % buckets;

    
    return(bucket);
}

int main() {

    // initialize vars
    customer_hash_table* my_table;
    char name [10]; char more_data [2];
    int id, buckets, failure;

    // dynamically allocate hash table
    printf("How many buckets should we have?\n");
    scanf("%d", &buckets);

    // create hash table, use fn pointer for hash fn
    my_table = create_hash_table(buckets, hash_by_name);
    printf("Table created with %d buckets\n", my_table->num_of_buckets);

    // fill hash map from user input and hashing fn
    while(1) {

        // get name, id from user
        printf("Enter a customer name and id\n");
        scanf("%9s %d", name, &id);

        // add user to linked list at bucket by hashing
        failure = add_customer_to_table(my_table, id, name);
        if (failure != 0) {
            printf("main() failed to add customer\n");
            return(-1);
        }

        // ask if more data
        printf("Would you like to enter more data? (y/n)\n");
        scanf("%1s", more_data);
        if (strcmp(more_data, "y") != 0) {
            break;
        }
    }

    // print hash map
    for (int i = 0; i < buckets; i++) {
        printf("Linked list at bucket %d with contents:\n", i);
        print_list(&(my_table->buckets[i]));
        printf("\n");
    }

    // delete hash map
    for (int i = 0; i < buckets; i++) {
        delete_list(&(my_table->buckets[i]));
    }

    free(my_table->buckets);
    free(my_table);

    return(0);
}