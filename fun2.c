#include "monty.h"

char *tok;
/**
 *_pop - removes node stack
 *@head: head
 *@lin: number possible error
 */
void _pop(stack_t **head, unsigned int lin)
{
	stack_t *aux;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lin);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	aux = aux->next;
	free(*head);
	*head = aux;
}

/**
 *_swap - swap top stack
 *@head: head
 *@lin: number possible error
 */
void _swap(stack_t **head, unsigned int lin)
{
	stack_t *aux;
	int count = 0, to_a = 0, to_b = 0;

	aux = *head;
	while (aux)
	{
		aux = aux->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lin);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	aux = aux->next;
	to_b = (*head)->n;
	to_a = aux->n;
	aux->n = to_b;
	(*head)->n = to_a;
}

/**
 *_add - adds elements stack
 *@head: head
 *@lin: number possible error
 */
void _add(stack_t **head, unsigned int lin)
{
	stack_t *aux;
	int count = 0;

	aux = *head;
	while (aux)
	{
		aux = aux->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lin);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	aux = aux->next;
	aux->n += ((*head)->n);
	free(*head);
	*head = aux;
}

/**
 *_nop - the nop opcode
 *@head: head
 *@lin: number possible error
 */
void _nop(stack_t **head, unsigned int lin)
{
	(void) head;
	(void) lin;
}
