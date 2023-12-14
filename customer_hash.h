#ifndef CUSTOMER_HASH_H
#define CUSTOMER_HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customer.h"

typedef struct {
    int num_of_buckets;
    customer** buckets;
} customer_hash_table;

customer_hash_table* create_hash_table(int num_of_buckets);
int hash_by_ID (customer_hash_table* my_table, int id);
int hash_by_name (customer_hash_table* my_table, char* name);

#endif