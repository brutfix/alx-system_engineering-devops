#include "main.h"

/**
* create_file - Creates a file.
* @filename: A pointer to the name of the file to create.
* @text_content: A pointer to a string to write to the file.
*
* Return: If the function fails - -1. Otherwise - 1.
*/
int create_file(const char *filename, char *text_content)
{
	int p, e, l = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}
	p = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	e = write(p, text_content, l);
	if (p == -1 || e == -1)
		return (-1);
	close(p);
	return (1);
}
