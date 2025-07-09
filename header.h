#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define MSG_NOT_ENOUGH_MEMORY "System doesn't meet memory requirements to run.\n"

struct node
{
    void *data;
    struct node *link;
};

/*Function initialises the very first node for the list.*/
struct node* createHead(void *value, int size);
/*Function is designed to add a node to the very end of the list only.*/
struct node* appendToEnd(struct node *head, void *data, int size);
/*Function inserts newly created node and links it in the correct place of the list to keep the list sorted.*/
struct node* insertAndSortNewNode(struct node *head, void *key, int size, int func_type(void*, void*));
/*Function calls for the specific data type print function and continues to the next node.*/
void printList(struct node *head, void func_type(void* ));
/*Function frees the memory taken up by the list and destroys it.*/
void free_list(struct node *head);
/*Function to delete a selected node from the list.*/
struct node* deleteNode(struct node* head, int number);
/*Function returns int value of the amount of nodes that exist in the list.*/
int findNodeCount(struct node* head);
/*Function returns an int value within the node.*/
int int_tellValueAtNode(struct node* head, int number);
/*Function inserts a chosen value to any selected node*/
struct node* InsertNewValueToNode(struct node *head, void *value, int number);
/*Function deletes a value from the node*/
struct node* deleteValueAtNode(struct node *head, int number);
/*Print functions which are called by the main printList function depending on data type.*/
void print_int_type(void *adr);
void print_char_type(void *adr);
void print_float_type(void *adr);
void print_double_type(void *adr);

/*Compare functions depending on type.*/
int cmp_int(void *adr1, void *adr2);
int cmp_char(void *adr1, void *adr2);
int cmp_float(void *adr1, void *adr2);
int cmp_double(void *adr1, void *adr2);

#endif
