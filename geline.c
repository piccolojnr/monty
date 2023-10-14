#include "monty.h"

/**
 * _getline - reads a line from a file
 * @line: pointer to a buffer to store the line
 * @len: length of the buffer
 * @stream: stream: file stream to read from
 *
 * Return: number of bytes read from the file
 */
ssize_t _getline(char **line, size_t *len, FILE *stream)
{

    int c;
    size_t pos = 0;
    char *new_line;

    if (line == NULL || len == NULL || stream == NULL)
    {
        return -1;
    }

    if (*line == NULL)
    {
        *line = (char *)malloc(128); /* Initial buffer size */
        if (*line == NULL)
        {
            return -1; /* Memory allocation failed */
        }
        *len = 128;
    }

    while (1)
    {
        c = fgetc(stream);
        if (c == EOF || c == '\n')
        {
            (*line)[pos] = '\0';
            return (pos == 0 && c == EOF) ? (size_t)-1 : pos;
        }

        (*line)[pos] = (char)c;
        pos++;

        if (pos >= *len - 1)
        {
            /* Resize the buffer if it's too small */
            *len *= 2;
            new_line = (char *)realloc(*line, *len);
            if (new_line == NULL)
            {
                return -1; /* Memory reallocation failed */
            }
            *line = new_line;
        }
    }
}
