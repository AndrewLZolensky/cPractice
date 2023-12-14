#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "customer.h"
#include "customer_hash.h"

customer_hash_table* create_hash_table(int num_of_buckets, int (*hash_function) (void* table, void* key)) {
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
    my_table->hash_function = hash_function;
    return my_table;
}

int add_customer_to_table(customer_hash_table* table, int id, char* name) {

    //handle NULL case
    if (table == NULL) {
        printf("Error in customer_hash.c: add_customer_by_id() failed\n");
        return(-2);
    }

    // hash by id
    int bucket = table->hash_function(table, &name);
    if (bucket < 0 || bucket > table->num_of_buckets) {
        printf("Error in customer_hash.c: add_customer_to_table() failed\n");
        return(-2);
    }

    int failure = add_customer(&(table->buckets[bucket]), id, name);
    if (failure) {
        printf("Error in customer_hash.c: add_customer_to_table() failed\n");
        return(-2);
    }

    return(0);
}