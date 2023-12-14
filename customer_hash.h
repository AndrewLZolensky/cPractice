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

customer* create_hash_table(int num_of_buckets);

#endif