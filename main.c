#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry
 * @argc: arg count
 * @argv: arg variable
 *
 * Return: 0
 */
int main(int argc, char **argv)
{

	FILE *f = NULL;
	char *path = NULL, *buffer = NULL;
	size_t space;
	int count = 1, bytes_read;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	path = argv[1];
	f = fopen(path, "r");
	if (f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", path);
		exit(EXIT_FAILURE);
	}
	while ((bytes_read = getline(&buffer, &space, f)) != -1)
	{
		char *first = strtok(buffer, " ");
		char *second_str = strtok(NULL, " ");
		int second = 0;

		if (first[strlen(first) - 1] == '\n')
			first[strlen(first) - 1] = '\0';
		if (second_str && second_str[strlen(second_str) - 1] == '\n')
			second_str[strlen(second_str) - 1] = '\0';
		if (strcmp(first, "push") == 0 && check_only_figures(first, second_str) == 1)
			second = atoi(second_str);
		else if (strcmp(first, "push") == 0)
			second = -9999;

		check_code(first, second, count);
		count++;
	}
	return (0);
}
/**
 * check_only_figures - check
 * @first: opcode
 * @second: value in string
 *
 * Return: int
 */
int check_only_figures(char *first __attribute__((unused)),
					   char *second)
{
	int i = 0;

	if (second == NULL || second[i] == '\0')
		return (0);
	if (second && second[0] == '-' && second[1])
		i = 1;
	for (; second[i] != '\0'; i++)
	{
		if (second[i] < '0' || second[i] > '9')
			return (0);
	}
	return (1);
}
