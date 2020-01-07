#include "monty.h"
char *tok;
/**
 *tokenizer - Recive tokens
 *@lintok: line token from
 *@lin: number of line
 *@head: head.
 *@file: file close
 *@s: status
 */
void _tkn(char *lintok, unsigned int lin, stack_t **head, FILE *file, int *s)
{
	int n_num = 0;

	tok = strtok(lintok, TOKDEL);
	if (tok && tok[0] == '#')
		tok = NULL;
	if (tok && strcmp(tok, QUE) == 0)
	{
		*s = 1;
		tok = NULL;
	}
	else if (tok && strcmp(tok, STK) == 0)
	{
		*s = 0;
		tok = NULL;
	}
	while (tok)
	{
		if (strcmp(tok, "push") == 0)
		{
			tok = strtok(NULL, TOKDEL);
			if (check_integer(head, lin, lintok, file))
			{
				n_num = atoi(tok);
				if (*s == 0)
					_pushstack(head, n_num);
				else if (*s == 1)
					_pushqueue(head, n_num);
			}
			tok = NULL;
		}
		else
		{
			slf(lin, head);
			tok = NULL;
		}
	}
}
