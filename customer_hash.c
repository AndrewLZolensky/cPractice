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