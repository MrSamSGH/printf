#include "main.h"

/**
* get_sz - Calculates the sz to cast the argument
* @format: Formatted string in which to print the arguments
* @i: lst of arguments to be prt.
* Return: Precision.
*/
int get_sz(const char *format, int *i)
{
int curr_i = *i + 1;
int sz = 0;

if (format[curr_i] == 'l')
sz = S_LN;
else if (format[curr_i] == 'h')
sz = S_SHR;

if (sz == 0)
*i = curr_i - 1;
else
*i = curr_i;

return (sz);
}
