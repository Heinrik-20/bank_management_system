#ifndef BANKOPS_H
#define BANKOPS_H

node_t *get_details(tree_t *all_accounts);
node_t *do_action(node_t *acc, int flag, char *action);

#endif