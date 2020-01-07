#include "monty.h"
char *tok;

/**
 *_pushstack - adds a node to the stack
 *@head: head
 *@num: number
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
 *_pushqueue - adds a node to the queue
 *@head: head
 *@num: number to add to the node
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
 *_pall - prints stack nodes
 *@head: head.
 *@lin: number error mesasge
 */
void _pall(stack_t **head, unsigned int lin)
{
	stack_t *aux = NULL;

	(void) lin;
	aux = *head;
	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
	tok = NULL;
}
/**
 *freee - free stack
 *@head: head.
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
/**
 *_pint - prints stack
 *@head: head.
 *@lin: number error mesasge
 */
void _pint(stack_t **head, unsigned int lin)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lin);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
