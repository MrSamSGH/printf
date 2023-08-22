#include "main.h"

/**
* is_printable - Evaluates if a char is printable
* @c: Char to be evaluated.
* Return: 1 if c is printable, 0 otherwise
*/
int is_printable(char c)
{
if (c >= 32 && c < 127)
return (1);

return (0);
}

/**
* append_hexa_code - Append ascci in hexadecimal code to bff
* @bff: Array of chars.
* @i: Index at which to start appending.
* @ascii_code: ASSCI CODE.
* Return: Always 3
*/
int append_hexa_code(char ascii_code, char bff[], int i)
{
char map_to[] = "0123456789ABCDEF";
if (ascii_code < 0)
ascii_code *= -1;

bff[i++] = '\\';
bff[i++] = 'x';

bff[i++] = map_to[ascii_code / 16];
bff[i] = map_to[ascii_code % 16];

return (3);
}

/**
* is_digit - Verifies if a char is a digit
* @c: Char to be evaluated
* Return: 1 if c is a digit, 0 otherwise
*/
int is_digit(char c)
{
if (c >= '0' && c <= '9')
return (1);

return (0);
}
