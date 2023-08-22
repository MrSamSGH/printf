#include "main.h"

/**
* get_wdh - Calculates the wdh for printing
* @format: Formatted string in which to print the arguments.
* @i: lst of arguments to be prt.
* @lst: lst of arguments.
* Return: width.
*/
int get_wdh(const char *format, int *i, va_list lst)
{
int curr_i;
int wdh = 0;

for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
{
if (is_digit(format[curr_i]))
{
wdh *= 10;
wdh += format[curr_i] - '0';
}
else if (format[curr_i] == '*')
{
curr_i++;
wdh = va_arg(lst, int);
break;
}
else
break;
}

*i = curr_i - 1;

return (wdh);
}

