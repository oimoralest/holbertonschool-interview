#include "lists.h"

/**
 * insert_node_beginning - adds a new node at the beginning of a
 * listint_t list
 *
 * @current_node: pointer to the current node (head of single linked list)
 * @number: integer to be included in new node
 * Return: listint_t* address of the new element or NULL if it fails
 */
listint_t *insert_node_beginning(listint_t **current_node, int number)
{
	listint_t *new_node = NULL;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->n = number;
	new_node->next = *current_node;

	return (new_node);
}

/**
 * insert_node_middle - adds a new node at somewhere in the middle of a
 * listint_t list
 *
 * @current_node: pointer to the current node
 * @number: integer to be included in new node
 * Return: listint_t* address of the new element or NULL if it fails
 */
listint_t *insert_node_middle(listint_t **current_node, int number)
{
	listint_t *new_node = NULL;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->n = number;
	new_node->next = (*current_node)->next;
	(*current_node)->next = new_node;

	return (new_node);
}

/**
 * insert_node_end - adds a new node at end of a listint_t list
 *
 * @current_node: pointer to the current node
 * @number: integer to be included in new node
 * Return: listint_t* address of the new element or NULL if it fails
 */
listint_t *insert_node_end(listint_t **current_node, int number)
{
	listint_t *new_node = NULL;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
	{
		return (NULL);
	}
	(*current_node)->next = new_node;
	new_node->n = number;
	new_node->next = NULL;

	return (new_node);
}

/**
 * insert_node - adds a new node in a sorted listint_t list
 *
 * @head: pointer to the head of a single linked list
 * @number: integer to be included in new node
 * Return: listint_t* address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *aux =  *head;

	if (aux == NULL || aux->n > number)
	{
		*head = insert_node_beginning(head, number);
		goto exit;
	}
	while (aux)
	{
		if (aux->next != NULL && aux->next->n > number)
		{
			insert_node_middle(&aux, number);
			goto exit;
		}
		if (aux->next == NULL)
		{
			insert_node_end(&aux, number);
			goto exit;
		}
		aux = aux->next;
	}

exit: return (aux);
}
