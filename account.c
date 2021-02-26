#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "treeops.h"
#include "account.h"

void print_and_free(void *data){
    account_t *account = (account_t *)(((node_t *)data)->data);
    printf("\nID: %d\nAmount: %.2lf\n", account->id, account->amount);
    free(account);
    account = NULL;
    free(data);
    data = NULL;
    return; 
}

int compare_id(void *id1, void *id2){
    account_t *x1 = id1, *x2 = id2;
    return ((x1->id) - (x2->id));
}

account_t *create_new_account(int id, int pin){
    account_t *new = (account_t *)malloc(sizeof(account_t));
    assert(new);
    new->id = id;
    new->pin = pin;
    new->amount = 0;
    return new;
}
