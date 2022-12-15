#include "monty.h"

/**
 * is_string_printable - check that
 * @str: str to check
 *
 * Return: 1 if printable
 */
int is_string_printable(char *str)
{
	int i = 0;
	int is_print = 0;

	i = 0;
	while (str[i] != '\0')
	{
		if (isprint(str[i]))
		{
			is_print = 1;
			break;
		}
		i++;
	}

	return (is_print);
}

/**
 * check_args - check arg length
 * @argc: arg to check it's length
 *
 * Return: void
 */
void check_args(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * get_file - get wanted file
 * @path: path to file
 *
 * Return: FILE
 */
FILE *get_file(const char *path)
{
	FILE *f = fopen(path, "r");

	if (f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", path);
		exit(EXIT_FAILURE);
	}

	return (f);
}

/**
 * check_op_code - checkt the op code
 * @str: op_code
 * @line_number: line number
 */
void check_op_code(char *str, int line_number)
{
	char *op_codes[] = {"pall", "pall\n",
						"push",
						"pint", "pint\n",
						"pop", "pop\n",
						"swap", "swap\n",
						"add", "add\n",
						"sub", "sub\n",
						"nop", "nop\n",
						"pchar", "pchar\n",
						"mod", "mod\n",
						"div", "div\n",
						"mul", "mul\n",
						"pstr", "pstr\n",
						"rotl", "rotl\n",
						"rotr", "rotr\n", NULL};

	int i = 0;

	while (op_codes[i] != NULL)
	{
		if (strcmp(op_codes[i], str) == 0)
			return;
		i++;
	}
	if (str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = '\0';

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, str);
	exit(EXIT_FAILURE);
}

/**
 * check_arg2 - checks arg 2
 * @arg_2: arg 2
 *
 * Return: int
 */
int check_arg2(char *arg_2)
{
	int a = 0;
	int len = 0;

	if (arg_2 == NULL)
	{
		return (INT_NULL);
	}

	a = atoi(arg_2);
	len = strlen(arg_2);

	if (arg_2[0] == '0')
	{
		if (arg_2[len - 1] == '\n')
			arg_2[len - 1] = '\0';
		if (strlen(arg_2) == 1)
			return (0);
		return (INT_NULL);
	}
	else
	{
		if (a == 0 || arg_2 == NULL)
		{
			return (INT_NULL);
		}
		return (a);
	}
	return (0);
}
