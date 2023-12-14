#ifndef CUSTOMER_HASH_H
#define CUSTOMER_HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customer.h"

typedef struct {
    int num_of_buckets;
    customer** buckets;
    int (*hash_function)(void* table, void* key);
} customer_hash_table;

customer_hash_table* create_hash_table(int num_of_buckets, int (*hash_function) (void* table, void* key));
int add_customer_to_table(customer_hash_table* table, int id, char* name);

#endif