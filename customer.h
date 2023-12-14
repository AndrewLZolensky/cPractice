#ifndef CUSTOMER_H
#define CUSTOMER_H
typedef struct cust_struct {
    int id;
    char *name;
    struct cust_struct *next;
} customer;

void print_customer(customer* c);
int add_customer(customer** ptr2head, int id, char* name);
void print_list(customer** ptr2head);
void delete_list(customer** head);

#endif