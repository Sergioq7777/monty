#include "monty.h"
char *tok;
/**
 *check_integer - check integer
 *@head: head.
 *@lin: number error
 *@linef: line free
 *@f_: file to close
 *Return: 1 or 0
 *
 */
int check_integer(stack_t **head, unsigned int lin, char *linef, FILE *f_)
{
	int count = 0;

	if (tok && (tok[count] == '-' ||  tok[count] == '+'))
		count++;
	while (tok && tok[count] != '\0')
	{
		if (isdigit(tok[count]) == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", lin);
			freee(head);
			free(linef);
			fclose(f_);
			exit(EXIT_FAILURE);
		}
		count++;
	}
	if (!tok)
	{
		fprintf(stderr, "L%u: usage: push integer\n", lin);
		freee(head);
		free(linef);
		fclose(f_);
		exit(EXIT_FAILURE);
	}
	return (1);
}
