#include "monty.h"

stack_t *head = NULL;

/**
 * main - entry
 * @argc: command line arg count
 * @argv: arr of command line args
 *
 * Return: 0 if successful
 */
int main(int argc, char const *argv[])
{
	FILE *f = NULL;
	int bytes_read = 0, line_num = 1;
	size_t space = 0;
	char *string = NULL;

	check_args(argc);
	f = get_file(argv[1]);

	while ((bytes_read = getline(&string, &space, f)) != -1)
	{
		char *arg_1 = NULL, *arg_2 = NULL;
		int num = 0;

		arg_1 = strtok(string, " \t"), arg_2 = strtok(NULL, " ");
		if (is_string_printable(arg_1) == 0
					|| strlen(arg_1) == 1 || string[0] == '\n')
		{
			line_num++;
			continue;
		}
		num = check_arg2(arg_2);
		if (arg_1)
			call_opfunc(arg_1, head, num, line_num);
		else
			break;
		line_num++;
	}
	free_dlistint(head);
	fclose(f);
	free(string);

	return (0);
}
