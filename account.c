#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "account.h"

void print_items(void *data){
    account_t *account = (account_t *)data;
    printf("ID: %d\nAmount: %.2lf\n\n", account->id, account->amount);
    return; 
}

int compare_id(void *id1, void *id2){
    account_t *x1 = id1, *x2 = id2;
    return ((x1->id) - (x2->id));
}

account_t *create_new_account(int id){
    account_t *new = (account_t *)malloc(sizeof(account_t));
    assert(new);
    new->id = id;
    new->amount = 0;
    return new;
}