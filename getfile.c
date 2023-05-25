#include "monty.h"

/**
 * getfile - gets a file
 * @path: path to get
 *
 * Return: file
 */
FILE *getfile(char *path)
{
	FILE *f = NULL;

	f = fopen(path, "r");
	if (f == NULL)
	{
		fprintf(stderr, "Error: Can't open  %s\n", path);
		exit(EXIT_SUCCESS);
	}
	return (f);
}
