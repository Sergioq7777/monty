#include "monty.h"

/**
 *_pushstack - add node to stack
 *@head: head
 *@num: number nodes
 */
void _pushstack(stack_t **head, int num)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = num;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
}

/**
 *_pushqueue - adds node to queue
 *@head: front
 *@num: number nodes
 */
void _pushqueue(stack_t **head, int num)
{
	stack_t *new = NULL, *aux = NULL;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = num;
	aux = *head;
	if (!(*head))
	{
		*head = new;
		(*head)->next = NULL;
		(*head)->prev = NULL;
		return;
	}
	while (aux->next)
	{
		aux = aux->next;
	}
	new->prev = aux;
	new->next = NULL;
	aux->next = new;
}

/**
 *freee - free
 *@head: head
 */
void freee(stack_t **head)
{
	stack_t *aux = NULL;

	aux = *head;
	while (aux)
	{
		aux = aux->next;
		free(*head);
		*head = aux;
	}
}
