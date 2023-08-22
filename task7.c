#include "main.h"

/**
* get_prc - Calculates the prc for printing
* @format: Formatted string in which to print the arguments
* @i: lst of arguments to be prt.
* @lst: lst of arguments.
* Return: Precision.
*/
int get_prc(const char *format, int *i, va_list lst)
{
int curr_i = *i + 1;
int prc = -1;

if (format[curr_i] != '.')
return (prc);

prc = 0;

for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
{
if (is_digit(format[curr_i]))
{
prc *= 10;
prc += format[curr_i] - '0';
}
else if (format[curr_i] == '*')
{
curr_i++;
prc = va_arg(lst, int);
break;
}
else
break;
}

*i = curr_i - 1;

return (prc);
}
