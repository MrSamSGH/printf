#include "main.h"

/****************** PRINT POINTER ******************/
/**
* print_pointer - Prints the value of a pointer variable
* @types: lst a of arguments
* @bff: bff array to handle print
* @flg:  Calculates active flg
* @wdh: get wdh
* @prc: prc specification
* @sz: sz specifier
* Return: Number of chars prt.
*/
int print_pointer(va_list types, char bff[],
int flg, int wdh, int prc, int sz)
{
char ex_c = 0, padd = ' ';
int ind = BFF_sz - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
unsigned long num_adr;
char map_to[] = "0123456789abcdef";
void *adr = va_arg(types, void *);

UNUSED(wdh);
UNUSED(sz);

if (adr == NULL)
return (write(1, "(nil)", 5));

bff[BFF_sz - 1] = '\0';
UNUSED(prc);

num_adr = (unsigned long)adr;

while (num_adr > 0)
{
bff[ind--] = map_to[num_adr % 16];
num_adr /= 16;
length++;
}

if ((flg & F_ZR) && !(flg & F_MN))
padd = '0';
if (flg & F_PL)
ex_c = '+', length++;
else if (flg & F_SP)
ex_c = ' ', length++;

ind++;

/*return (write(1, &bff[i], BFF_sz - i - 1));*/
return (write_pointer(bff, ind, length,
wdh, flg, padd, ex_c, padd_start));
}

/**
* print_non_printable - Prints ascii codes in hexa of non printable chars
* @types: lsta of arguments
* @bff: bff array to handle print
* @flg:  Calculates active flg
* @wdh: get wdh
* @prc: prc specification
* @sz: sz specifier
* Return: Number of chars prt
*/
int print_non_printable(va_list types, char bff[],
int flg, int wdh, int prc, int sz)
{
int i = 0, offset = 0;
char *str = va_arg(types, char *);

UNUSED(flg);
UNUSED(wdh);
UNUSED(prc);
UNUSED(sz);

if (str == NULL)
return (write(1, "(null)", 6));

while (str[i] != '\0')
{
if (is_printable(str[i]))
bff[i + offset] = str[i];
else
offset += append_hexa_code(str[i], bff, i + offset);

i++;
}

bff[i + offset] = '\0';

return (write(1, bff, i + offset));
}

/**
* print_reverse - Prints reverse string.
* @types: lsta of arguments
* @bff: bff array to handle print
* @flg:  Calculates active flg
* @wdh: get wdh
* @prc: prc specification
* @sz: sz specifier
* Return: Numbers of chars prt
*/

int print_reverse(va_list types, char bff[],
int flg, int wdh, int prc, int sz)
{
char *str;
int i, count = 0;

UNUSED(bff);
UNUSED(flg);
UNUSED(wdh);
UNUSED(sz);

str = va_arg(types, char *);

if (str == NULL)
{
UNUSED(prc);

str = ")Null(";
}
for (i = 0; str[i]; i++)
;

for (i = i - 1; i >= 0; i--)
{
char z = str[i];

write(1, &z, 1);
count++;
}
return (count);
}

/**
* print_rot13string - Print a string in rot13.
* @types: lsta of arguments
* @bff: bff array to handle print
* @flg:  Calculates active flg
* @wdh: get wdh
* @prc: prc specification
* @sz: sz specifier
* Return: Numbers of chars printed
*/
int print_rot13string(va_list types, char bff[],
int flg, int wdh, int prc, int sz)
{
char x;
char *str;
unsigned int i, j;
int count = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

str = va_arg(types, char *);
UNUSED(bff);
UNUSED(flg);
UNUSED(wdh);
UNUSED(prc);
UNUSED(sz);

if (str == NULL)
str = "(AHYY)";
for (i = 0; str[i]; i++)
{
for (j = 0; in[j]; j++)
{
if (in[j] == str[i])
{
x = out[j];
write(1, &x, 1);
count++;
break;
}
}
if (!in[j])
{
x = str[i];
write(1, &x, 1);
count++;
}
}
return (count);
}
