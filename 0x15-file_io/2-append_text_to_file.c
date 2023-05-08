#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filame: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: If the function fails or filame is NULL - -1.
 * If the file does not exist the user lacks write permissions - -1.
 * Otherwise - 1.
 */
int append_text_to_file(const char *filame, char *text_content)
{
	int c, k, l = 0;

	if (filame == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}
	c = open(filame, O_WRONLY | O_APPEND);
	k = write(c, text_content, l);

	if (c == -1 || k == -1)
		return (-1);
	close(c);
	return (1);
}
