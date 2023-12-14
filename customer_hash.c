#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "customer.h"
#include "customer_hash.h"

customer_hash_table* create_hash_table(int num_of_buckets) {
    customer_hash_table* my_table = malloc(sizeof(customer_hash_table));
    if (my_table == NULL) {
        printf("Error in customer_hash.c: create_hash_table() failed\n");
        return(NULL);
    }
    my_table->buckets = malloc(sizeof(customer*) * num_of_buckets);
    if (my_table->buckets == NULL) {
        printf("Error in customer_hash.c: create_hash_table() failed\n");
        return(NULL);
    }
    my_table->num_of_buckets = num_of_buckets;
    return my_table;
}

int hash_by_ID (customer_hash_table* my_table, int id) {

    // handle null hash table
    if (my_table == NULL) {
        printf("Error in customer_hash.c: hash_by_ID() failed\n");
        return(-1);
    }

    // otherwise hash
    int buckets = my_table->num_of_buckets;
    int bucket = id % buckets;


    return(bucket);
}

int hash_by_name (customer_hash_table* my_table, char* name) {

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

int add_customer_to_table(customer_hash_table* table, int id, char* name) {

    //handle NULL case
    if (table == NULL) {
        printf("Error in customer_hash.c: add_customer_by_id() failed\n");
        return(-2);
    }

    // hash by id
    int bucket = hash_by_ID(table, id);
    if (bucket < 0 || bucket > table->num_of_buckets) {
        printf("Error in customer_hash.c: add_customer_by_id() failed\n");
        return(-2);
    }

    int failure = add_customer(&(table->buckets[bucket]), id, name);
    if (failure) {
        printf("Error in customer_hash.c: add_customer_by_id() failed\n");
        return(-2);
    }

    return(0);
}