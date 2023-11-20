#include "sort.h"
void swap_nodes_dl(listint_t **f_node, listint_t **s_node)
{
    listint_t *temp;
    // handle the adjacant node
    if ((*f_node)->next == *s_node)
    {
        (*f_node)->next = (*s_node)->next;
        (*s_node)->prev = (*f_node)->prev;

        if ((*f_node)->prev)
        (*f_node)->prev->next = *s_node;
        if ((*s_node)->next)
        (*s_node)->next->prev = *f_node;

        (*s_node)->next = (*f_node);
        (*f_node)->prev = (*s_node);
    }
    else
    {
    if ((*f_node)->prev)
    (*f_node)->prev->next = *s_node;

    if ((*s_node)->prev)
    (*s_node)->prev->next = *f_node;

    if ((*f_node)->next)
    (*f_node)->next->prev = *s_node;

    if ((*s_node)->next)
    (*s_node)->next->prev = *f_node;

    temp = (*f_node)->prev;
    (*f_node)->prev = (*s_node)->prev;
    (*s_node)->prev = temp;

    temp = (*f_node)->next;
    (*f_node)->next = (*s_node)->next;
    (*s_node)->next = temp;
    }
}


// void swap_nodes_dl(listint_t **f_node, listint_t **s_node) {
//     listint_t *temp;

//     // Get pointers to the nodes being swapped
//     listint_t *first = *f_node;
//     listint_t *second = *s_node;

//     // Update previous node pointers;l
//     if (first->prev)
//         first->prev->next = second;
//     if (second->prev)
//         second->prev->next = first;

//     // Update next node pointers
//     if (first->next)
//         first->next->prev = second;
//     if (second->next)
//         second->next->prev = first;

//     // Swap next and prev pointers of the nodes
//     temp = first->prev;
//     first->prev = second->prev;
//     second->prev = temp;

//     temp = first->next;
//     first->next = second->next;
//     second->next = temp;

//     // Update pointers in case of head or tail node swap
//     if (*f_node == first)
//         *f_node = second;
//     else if (*f_node == second)
//         *f_node = first;
// }



// void insertion_sort_list(listint_t **list)
// {

// }

void print_list(const listint_t *list)
{
int i;

i = 0;
while (list)
{
if (i > 0)
printf(", ");
printf("%d", list->n);
++i;
list = list->next;
}
printf("\n");
}

int main(void)
{
    listint_t node1 = {10, NULL, NULL};
    listint_t *head = &node1;
    listint_t node2 = {20, head, NULL};
    head->next = &node2;
    print_list(head);
    printf("\n");
    swap_nodes_dl(&(head), &(head->next));
    printf("%d", head->n);
    // print_list(head);
    return (0);
}
