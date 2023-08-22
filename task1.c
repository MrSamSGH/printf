#include "main.h"

/**
* print_char - Prints a char
* @types: lst a of arguments
* @bff: bff array to handle print
* @flg:  Calculates active flg
* @wdh: wdh
* @prc: prc specification
* @sz: size specifier
* Return: Number of chars printed
*/
int print_char(va_list types, char bff[], int flg, int wdh,
		int prc, int sz)
{
char c = va_arg(types, int);

return (handle_write_char(c, bff, flg, wdh, prc, sz));
}

/**
* print_string - Prints a string
* @types: lst a of arguments
* @bff: bff array to handle print
* @flg:  Calculates active flg
* @wdh: get wdh.
* @prc: prc specification
* @sz: size specifier
* Return: Number of chars printed
*/
int print_string(va_list types, char bff[],
int flg, int wdh, int prc, int sz)
{
int length = 0, i;
char *str = va_arg(types, char *);

UNUSED(bff);
UNUSED(flg);
UNUSED(wdh);
UNUSED(prc);
UNUSED(sz);
if (str == NULL)
{
str = "(null)";
if (prc >= 6)
str = "      ";
}

while (str[length] != '\0')
length++;

if (prc >= 0 && prc < length)
length = prc;

if (wdh > length)
{
if (flg & F_MN)
{
write(1, &str[0], length);
for (i = wdh - length; i > 0; i--)
write(1, " ", 1);
return (wdh);
}
else
{
for (i = wdh - length; i > 0; i--)
write(1, " ", 1);
write(1, &str[0], length);
return (wdh);
}
}

return (write(1, str, length));
}

/**
* print_percent - Prints a percent sign
* @types: lsta of arguments
* @bff: bff array to handle print
* @flg:  Calculates active flg
* @wdh: get wdh.
* @prc: prc specification
* @sz: size specifier
* Return: Number of chars printed
*/
int print_percent(va_list types, char bff[],
int flg, int wdh, int prc, int sz)
{
UNUSED(types);
UNUSED(bff);
UNUSED(flg);
UNUSED(wdh);
UNUSED(prc);
UNUSED(sz);
return (write(1, "%%", 1));
}

/**
* print_int - Print int
* @types: lsta of arguments
* @bff: bff array to handle print
* @flg:  Calculates active flg
* @wdh: get wdh.
* @prc: prc specification
* @sz: size specifier
* Return: Number of chars printed
*/
int print_int(va_list types, char bff[],
int flg, int wdh, int prc, int sz)
{
int i = BFF_sz - 2;
int is_ng = 0;
long int n = va_arg(types, long int);
unsigned long int num;

n = convert_sz_number(n, sz);

if (n == 0)
bff[i--] = '0';

bff[BFF_sz - 1] = '\0';
num = (unsigned long int)n;

if (n < 0)
{
num = (unsigned long int)((-1) * n);
is_ng = 1;
}

while (num > 0)
{
bff[i--] = (num % 10) + '0';
num /= 10;
}

i++;

return (write_number(is_ng, i, bff, flg, wdh, prc, sz));
}


/**
* print_binary - Prints an unsigned number
* @types: lsta of arguments
* @bff: bff array to handle print
* @flg:  Calculates active flg
* @wdh: get wdh.
* @prc: prc specification
* @sz: sz specifier
* Return: Numbers of char printed.
*/
int print_binary(va_list types, char bff[],
int flg, int wdh, int prc, int sz)
{
unsigned int n, m, i, sum;
unsigned int a[32];
int count;

UNUSED(bff);
UNUSED(flg);
UNUSED(wdh);
UNUSED(prc);
UNUSED(sz);

n = va_arg(types, unsigned int);
m = 2147483648; /* (2 ^ 31) */
a[0] = n / m;
for (i = 1; i < 32; i++)
{
m /= 2;
a[i] = (n / m) % 2;
}
for (i = 0, sum = 0, count = 0; i < 32; i++)
{
sum += a[i];
if (sum || i == 31)
{
char z = '0' + a[i];

write(1, &z, 1);
count++;
}
}
return (count);
}

