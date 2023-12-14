typedef struct {
    int num_of_buckets;
    customer** buckets;
} customer_hash;

customer_hash* create_hash_table (int num_of_buckets);