#include "monty.h"

/**
 * check_comment - check if comment
 * @arg_1: arg 1
 *
 * Return: int
 */
int check_comment(char *arg_1)
{
	if (strcmp(arg_1, "#") == 0 || strcmp(arg_1, "#\n") == 0)
		return (1);
	return (0);
}

/**
 * check_empty_line - check empty line
 * @arg_1: arg 1
 * @string: complete string
 *
 * Return: 1
 */
int check_empty_line(char *arg_1, char *string)
{
	if (
		is_string_printable(arg_1) == 0 ||
		strlen(arg_1) == 1 ||
		string[0] == '\n')
	{
		return (1);
	}

	return (0);
}
