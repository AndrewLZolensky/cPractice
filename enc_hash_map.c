#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customer_hash.h"

int main() {
    customer_hash_table* my_table = create_hash_table(5);
    printf("Table created with %d buckets\n", my_table->num_of_buckets);
    return(0);
}