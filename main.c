#include "monty.h"
char *tok;
/**
 *main - Read monty opcode
 *@argc: number args
 *@argv: args
 *Return: Always
 */
int main(int argc, char *argv[])
{
	FILE *file;
	size_t sizet;
	stack_t *head = NULL;
	char *line = NULL;
	unsigned int lin = 0;
	int st = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!(file) || file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &sizet, file)) != EOF)
	{
		lin++;
		_tkn(line, lin, &head, file, &st);
	}
	free(line);
	freee(&head);
	fclose(file);
	exit(EXIT_SUCCESS);
}
/**
 *slf - Select
 *@lin: line possible error.
 *@head: head.
 */
void slf(unsigned int lin, stack_t **head)
{
	int count = 0;
	instruction_t m_opcodes[] = {
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};


	while (m_opcodes[count].opcode != NULL)
	{
		if (strcmp(m_opcodes[count].opcode, tok) == 0)
		{
			m_opcodes[count].f(head, lin);
			return;
		}
		count++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", lin, tok);
	exit(EXIT_FAILURE);
}
