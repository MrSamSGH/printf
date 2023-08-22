#include "main.h"
/**
* handle_print - Prints an argument based on its type
* @fmtt: Formatted string in which to print the arguments.
* @lst: lst of arguments to be prt.
* @ind: ind.
* @bff: bff array to handle print.
* @flg: Calculates active flg
* @wdh: get wdh.
* @prc: prc specification
* @sz: sz specifier
* Return: 1 or 2
*/
int handle_print(const char *fmtt, int *ind, va_list lst, char bff[],
int flg, int wdh, int prc, int sz)
{
int i, unkw_len = 0, prt_ch = -1;
fmtt_t fmtt_types[] = {
{'c', print_char}, {'s', print_string}, {'%', print_percent},
{'i', print_int}, {'d', print_int}, {'b', print_binary},
{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
};
for (i = 0; fmtt_types[i].fmtt != '\0'; i++)
if (fmtt[*ind] == fmtt_types[i].fmtt)
return (fmtt_types[i].fn(lst, bff, flg, wdh, prc, sz));

if (fmtt_types[i].fmtt == '\0')
{
if (fmtt[*ind] == '\0')
return (-1);
unkw_len += write(1, "%%", 1);
if (fmtt[*ind - 1] == ' ')
unkw_len += write(1, " ", 1);
else if (wdh)
{
--(*ind);
while (fmtt[*ind] != ' ' && fmtt[*ind] != '%')
--(*ind);
if (fmtt[*ind] == ' ')
--(*ind);
return (1);
}
unkw_len += write(1, &fmtt[*ind], 1);
return (unkw_len);
}
return (prt_ch);
}

