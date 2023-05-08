#include "main.h"
#include <stdlib.h>

/**
* read_textfile- Read text file and print to POSIX STDOUT.
* @filename: text file being read
* @letters: number of letters to be read
* Return: w- actual number of bytes read and printed
* 0 when filename is NULL.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *rat;
	ssize_t p, e, t;

	p = open(filename, O_RDONLY);
	if (p == -1)
			return (0);
	rat = malloc(sizeof(char) * letters);
	t = read(p, rat, letters);
	e = write(STDOUT_FILENO, rat, t);

	free(rat);
	close(p);
	return (e);
}
