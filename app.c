#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "customer.h"

#define BUCKETS 3

int main() {
    customer* my_table [BUCKETS];
    char name [4]; int id, bucket;

    while(1) {
        printf("Enter a customer name and id\n");
        scanf("%s %d", name, &id);
        bucket = id % BUCKETS;
        add_customer(&my_table[bucket], id, name);
    }

    for (int i = 0; i < BUCKETS; i++) {
        print_list(&my_table[i]);
    }

    for (int i = 0; i < BUCKETS; i++) {
        delete_list(&my_table[i]);
    }

    return(0);
}