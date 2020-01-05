#include "monty.h"

/**
 *main - Read monty opcode
 *@argc: num arguments to read
 *@argv: containing the arguments
 *Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *f_;
	size_t sizze;
	stack_t *head = NULL;
	char *m_code = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f_ = fopen(argv[1], "r");
	if (!(f_) || f_ == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&m_code, &sizze, f_)) != EOF)
	{
		line_number++;
	}
	free(m_code);
	freee(&head);
	fclose(f_);
	exit(EXIT_SUCCESS);
}
