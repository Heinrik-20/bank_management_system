#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct {
    int id;
    int pin;
    double amount;
}account_t;

void print_and_free(void *data);
int compare_id(void *id1, void *id2);
account_t *create_new_account(int id, int pin);

#endif 
