#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
    int i;
    char *s = dest;

    for (i = 0; i < n - 1 && *src != '\0'; i++, dest++, src++)
        *dest = *src;

    if (i < n)
    {
        while (i < n)
        {
            *dest = '\0';
            dest++;
            i++;
        }
    }
    return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
    char *s = dest;

    while (*dest != '\0')
        dest++;

    for (; n > 0 && *src != '\0'; n--, dest++, src++)
        *dest = *src;

    if (n > 0)
        *dest = '\0';
    return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
    do {
        if (*s == c)
            return (s);
    } while (*s++ != '\0');

    return (NULL);
}
