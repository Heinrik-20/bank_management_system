#include <stdio.h>
#include <stdlib.h>
#include "treeops.h"
#include "account.h"
#include "bankops.h"

node_t *get_details(tree_t *all_accounts){
    int id, pin;
    account_t *new = NULL;
    node_t *key = NULL, *acc;
    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter pin: ");
    scanf("%d", &pin);
    new = create_new_account(id, pin);
    key = node_init(new);
    acc = search_tree(all_accounts, key);
    free(new);
    new = NULL;
    free(key);
    key = NULL;
    if (!acc){
        printf("Account not in database\n");
        return NULL;
    }
    if ((((account_t *)(acc->data))->pin) == pin){
        return acc;
    }
    else{
        printf("Wrong password\n");
    }
    return NULL;
}

node_t *do_action(node_t *acc, int flag, char *action){
    double amount;
    printf("Enter amount to %s: \n", action);
    scanf("%lf", &amount);
    (((account_t *)(acc->data))->amount) += (flag * amount);
    printf("$%.2lf available in account\n", (((account_t *)(acc->data))->amount));
    return acc;
}