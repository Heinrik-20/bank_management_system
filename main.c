#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "account.h"
#include "treeops.h"


int main(int argc, char **argv){
    int accounts, id;
    tree_t *all_accounts = tree_init(compare_id, print_items);
    account_t *acc = NULL;
    printf("Number of accounts: ");
    scanf("%d", &accounts);
    for (int i = 0;i < accounts;i++){
        printf("ID: ");
        scanf("%d", &id);
        acc = create_new_account(id);
        all_accounts = insert_tree(all_accounts, acc);
    }
    print_all_items(all_accounts->root, all_accounts->print);
    return 0;
}