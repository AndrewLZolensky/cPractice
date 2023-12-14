#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "customer.h"
#include "customer_hash.h"

customer_hash* create_hash_table (int num_of_buckets) {
    customer_hash* my_table = malloc(sizeof(customer_hash));
    my_table->num_of_buckets = num_of_buckets;
    my_table->buckets = malloc(sizeof(customer*) * num_of_buckets);
    return my_table;
}