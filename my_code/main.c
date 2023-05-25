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
	int bytes_read = 0, line_num = 1, isStack = 1;
	size_t space = 0;
	char *string = NULL;

	check_args(argc);
	f = get_file(argv[1]);

	while ((bytes_read = getline(&string, &space, f)) != -1)
	{
		char *firstToken = NULL, *secondToken = NULL;
		int num = 0;

		firstToken = strtok(string, " \t");
		secondToken = strtok(NULL, " \t\n");

		if (check_comment(firstToken) || check_empty_line(firstToken, string))
		{
			line_num++;
			continue;
		}

		num = check_arg2(secondToken);
		if (firstToken)
		{
			set_stack_or_queue(firstToken, &isStack);
			call_opfunc(firstToken, head, num, line_num, isStack);
		}
		else
			break;
		line_num++;
	}
	free_dlistint(head);
	fclose(f);
	free(string);

	return (0);
}
