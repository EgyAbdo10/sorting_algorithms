#include "sort.h"

/**
 * swap_nodes_dl - swap two adjacent nodes in a doubly linked list
 * @head: the address of the head pointer
 * @f_node: the first node to be changed
 * @s_node: the second node
 */
void swap_nodes_dl(listint_t **head, listint_t *f_node, listint_t *s_node)
{
if (f_node->next == s_node)
{
f_node->next = s_node->next;
s_node->prev = f_node->prev;

if (f_node->prev)
f_node->prev->next = s_node;
if (s_node->next)
s_node->next->prev = f_node;

s_node->next = f_node;
f_node->prev = s_node;
}
if ((f_node) == *head)
*head = s_node;
else if ((s_node) == *head)
*head = f_node;
}

/**
* insertion_sort_list - sort a doubly linked list
* using the insertion sort algorithm
* @list: the address of the head pointer
*/
void insertion_sort_list(listint_t **list)
{
listint_t *temp = *list, *temp2;
if (list == NULL || *list == NULL)
return;
temp = (*list)->next;
while (temp != NULL)
{
temp2 = temp;
while (temp2->prev != NULL && temp2->n < temp2->prev->n)
{
swap_nodes_dl(list, temp2->prev, temp2);
print_list(*list);
}
temp = temp->next;
}
}
