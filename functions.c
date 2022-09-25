#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "header.h"

struct node* createHead(void *value, int size)
{
    void *dataptr = malloc(sizeof(size));

    if(dataptr == NULL)
    {
        printf(MSG_NOT_ENOUGH_MEMORY);
        exit(0);
    }

    memcpy(dataptr, value, size);

    struct node *new_node = malloc(sizeof(struct node));

    if(new_node == NULL)
    {
        printf(MSG_NOT_ENOUGH_MEMORY);
        exit(0);
    }

    new_node -> data = (void*)calloc(1, size);
    new_node -> link = NULL;

    memcpy(new_node -> data, dataptr, size);

    return new_node;

}

struct node* appendToEnd(struct node *head, void *data, int size)
{
    void *dataptr = malloc(sizeof(size));

    if(dataptr == NULL)
    {
        printf(MSG_NOT_ENOUGH_MEMORY);
        exit(0);
    }

    memcpy(dataptr, data, size);

    struct node *new_node = malloc(sizeof(struct node));

    if(new_node == NULL)
    {
        printf(MSG_NOT_ENOUGH_MEMORY);
        exit(0);
    }

    new_node -> data = dataptr;
    new_node -> link = NULL;

    struct node *temp = head;

    while(temp -> link != NULL)
    {
        temp = temp -> link;
    }

    temp -> link = new_node;

    return head;
}

int cmp_int(void *adr1, void *adr2)
{
    if(*((int*)adr1) > *((int*)adr2))
    {
        return 1;
    }

    if(*((int*)adr1) < *((int*)adr2))
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int cmp_float(void *adr1, void *adr2)
{
    if(*((float*)adr1) > *((float*)adr2))
    {
        return 1;
    }

    if(*((float*)adr1) < *((float*)adr2))
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int cmp_char(void *adr1, void *adr2)
{
    if(*((char*)adr1) > *((char*)adr2))
    {
        return 1;
    }

    if(*((char*)adr1) < *((char*)adr2))
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int cmp_double(void *adr1, void *adr2)
{
    if(*((double*)adr1) > *((double*)adr2))
    {
        return 1;
    }

    if(*((double*)adr1) < *((double*)adr2))
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

struct node* insertAndSortNewNode(struct node *head, void *key, int size, int func_type(void*, void* ))
{
    struct node *new_node = malloc(sizeof(struct node));

    if(new_node == NULL)
    {
        printf(MSG_NOT_ENOUGH_MEMORY);
        exit(0);
    }

    void *dataptr = malloc(sizeof(size));

    if(dataptr == NULL)
    {
        printf(MSG_NOT_ENOUGH_MEMORY);
        exit(0);
    }

    memcpy(dataptr, key, size);

    if(new_node == NULL)
    {
        printf("Not enough memory!\n");
        exit(0);
    }

    new_node -> data = (void*)calloc(1, size);
    new_node -> link = NULL;
    memcpy(new_node -> data, dataptr, size);
    struct node *temp;

    if(head == NULL || func_type(head -> data, new_node -> data) > 0)
    {
        new_node -> link = head;
        head = new_node;
    }
    else
    {
        temp = head;

        while(temp -> link != NULL && func_type(temp -> link -> data, new_node -> data) < 0)
        {
            temp = temp -> link;
        }

        new_node -> link = temp -> link;
        temp -> link = new_node;

    }

    return head;

}

struct node* deleteNode(struct node* head, int number)
{
    if(head == NULL)
    {
        return NULL;
    }

    if(number <= 0)
    {
        return head;
    }

    struct node* temp = head;

    if (number == 1)
    {
        temp = temp -> link;
        free(head);
        return temp;
    }

    for(int i = 0; temp != NULL && i < number; i++)
    {
        temp = temp -> link;
    }

    if (temp == NULL || temp -> link == NULL)
    {
        return head;
    }

    struct node* next = temp -> link -> link;
    free(temp -> link);
    temp -> link = next;

    return head;
}

int findNodeCount(struct node* head)
{
    if (head == NULL)
    {
        return 1;
    }

    struct node *temp = head;
    int counter = 0;

    while(temp != NULL)
    {
        temp = temp -> link;
        counter++;
    }

    return counter;
}

int int_tellValueAtNode(struct node* head, int number)
{
    if(number <= 0)
    {
        return 0;
    }

    struct node *temp = head;
    int value = 0;

    for(int i = 0; i < number; ++i)
    {
        if(temp == NULL)
        {
            return 0;
        }

        value = *(int*)temp -> data;
        temp = temp -> link;
    }

    return value;
}

struct node* InsertNewValueToNode(struct node *head, void *value, int number)
{
    struct node *temphead = head;

    if(head == NULL)
    {
        return NULL;
    }

    if(number <= 0)
    {
        return head;
    }

    struct node* temp = head;

    if (number == 1)
    {
        head -> data = value;
        return head;
    }

    for(int i = 1; head != NULL && i < number; ++i)
    {
        head = head -> link;
    }

    if(temp != NULL)
    {
        head -> data = value;
    }

    return temphead;
}

struct node* deleteValueAtNode(struct node *head, int number)
{
    struct node *temphead = head;

    if(head == NULL)
    {
        return NULL;
    }

    if(number <= 0)
    {
        return head;
    }

    struct node* temp = head;

    if (number == 1)
    {
        head -> data = NULL;
        return head;
    }

    for(int i = 1; temp != NULL && i < number; i++)
    {
        head = head -> link;
    }

    if(temp != NULL)
    {
        head -> data = NULL;
    }

    return temphead;
}


void print_int_type(void *adr)
{
    if(adr != NULL)
    {
        printf("%d\n", *(int*)adr);
    }
    else
    {
        printf("(null)\n");
    }

}

void print_char_type(void *adr)
{
    if(adr != NULL)
    {
        printf("%c\n", *(char*)adr);
    }
    else
    {
        printf("(null)\n");
    }
}

void print_float_type(void *adr)
{
    if(adr != NULL)
    {
        printf("%f\n", *(float*)adr);
    }
    else
    {
        printf("(null)\n");
    }
}

void print_double_type(void *adr)
{
    if(adr != NULL)
    {
        printf("%lf\n", *(double*)adr);
    }
    else
    {
        printf("(null)\n");
    }
}

void printList(struct node *head, void func_type(void* ))
{
    struct node *temp = head;

    while(temp != NULL)
    {
        func_type(temp -> data);
        temp = temp -> link;
    }
}

void free_list(struct node *head)
{
    struct node *prev = head;
    struct node *cur = head;

    while(cur != NULL)
    {
        prev = cur;
        cur = prev -> link;
        free(prev);
    }
}
