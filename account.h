typedef struct {
    int id;
    double amount;
}account_t;

void print_items(void *data);
int compare_id(void *id1, void *id2);
account_t *create_new_account(int id);