#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "treeops.h"
#include "account.h"
#include "bankops.h"

int main(int argc, char **argv){
    int action;
    tree_t *all_accounts = tree_init(compare_id, print_and_free);
    printf("0: Create new account, 1: Deposit account, 2: Withdrawal 3: View Balance\n");
    printf("Enter action: ");
    while (scanf("%d", &action) == 1){
        int id, pin;
        account_t *new = NULL;
        node_t *key = NULL, *acc;
        switch (action){
            case 0:
                printf("Enter New ID: ");
                scanf("%d", &id);
                printf("Enter new password: ");
                scanf("%d", &pin);
                new = create_new_account(id, pin);
                all_accounts = insert_tree(all_accounts, new);
                break;
            
            case 1:
                acc = get_details(all_accounts);
                if (acc){
                    acc = do_action(acc, 1, "Deposit");
                }
                break;

            case 2:
                acc = get_details(all_accounts);
                if (acc){
                    acc = do_action(acc, -1, "Withdraw");
                }
                break;

            case 3:
                acc = get_details(all_accounts);
                if (acc) {
                    printf("Balance available: $%.2lf\n", ((account_t *)(acc->data))->amount);
                }
                break;

            default:
                printf("Invalid action, try again\n");
                break;
        }
        printf("Enter action:\n");
    }
    traverse_tree(all_accounts->root, all_accounts->print);
    free_tree(&all_accounts);
    return 0;
}
