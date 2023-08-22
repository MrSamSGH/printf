#include "main.h"

void print_bff(char bff[], int *bff_in);

/**
* _printf - Printf function
* @format: format.
* Return: prt chars.
*/
int _printf(const char *format, ...)
{
	int i, prt = 0, prt_ch = 0;
	int flg, wdh, prc, sz, bff_in = 0;
	va_list lst;
	char bff[BFF_sz];

if (format == NULL)
return (-1);

va_start(lst, format);

for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
bff[bff_in++] = format[i];
if (bff_in == BFF_sz)
print_bff(bff, &bff_in);
/* write(1, &format[i], 1);*/
prt_ch++;
}
else
{
print_bff(bff, &bff_in);
flg = get_flg(format, &i);
wdh = get_wdh(format, &i, lst);
prc = get_prc(format, &i, lst);
sz = get_sz(format, &i);
++i;
prt = handle_print(format, &i, lst, bff,
flg, wdh, prc, sz);
if (prt == -1)
return (-1);
prt_ch += prt;
}
}

print_bff(bff, &bff_in);

va_end(lst);

return (prt_ch);
}

/**
* print_bff - Prints the contents of the bff if it exist
* @bff: Array of chars
* @bff_in: Index at which to add next char, represents the length.
*/
void print_bff(char bff[], int *bff_in)
{
if (*bff_in > 0)
write(1, &bff[0], *bff_in);

*bff_in = 0;
}
