#include "main.h"

/**
* print_unsigned - Prints an unsigned number
* @types: lst a of arguments
* @bff: bff array to handle print
* @flg:  Calculates active flg
* @wdh: get wdh
* @prc: prc specification
* @sz: sz specifier
* Return: Number of chars printed.
*/
int print_unsigned(va_list types, char bff[],
int flg, int wdh, int prc, int sz)
{
int i = BFF_sz - 2;
unsigned long int num = va_arg(types, unsigned long int);

num = convert_sz_unsgnd(num, sz);

if (num == 0)
bff[i--] = '0';

bff[BFF_sz - 1] = '\0';

while (num > 0)
{
bff[i--] = (num % 10) + '0';
num /= 10;
}

i++;

return (write_unsgnd(0, i, bff, flg, wdh, prc, sz));
}


/**
* print_octal - Prints an unsigned number in octal notation
* @types: lsta of arguments
* @bff: bff array to handle print
* @flg:  Calculates active flg
* @wdh: get wdh
* @prc: prc specification
* @sz: sz specifier
* Return: Number of chars printed.
*/
int print_octal(va_list types, char bff[],
int flg, int wdh, int prc, int sz)
{

int i = BFF_sz - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;

UNUSED(wdh);

num = convert_sz_unsgnd(num, sz);

if (num == 0)
bff[i--] = '0';

bff[BFF_sz - 1] = '\0';

while (num > 0)
{
bff[i--] = (num % 8) + '0';
num /= 8;
}

if (flg & F_H && init_num != 0)
bff[i--] = '0';

i++;

return (write_unsgnd(0, i, bff, flg, wdh, prc, sz));
}

/**
* print_hexadecimal - Prints an unsigned number in hexadecimal notation
* @types: lsta of arguments
* @bff: bff array to handle print
* @flg:  Calculates active flg
* @wdh: get wdh
* @prc: prc specification
* @sz: sz specifier
* Return: Number of chars printed.
*/
int print_hexadecimal(va_list types, char bff[],
int flg, int wdh, int prc, int sz)
{
return (print_hexa(types, "0123456789abcdef", bff,
flg, 'x', wdh, prc, sz));
}

/**
* print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
* @types: lsta of arguments
* @bff: bff array to handle print
* @flg:  Calculates active flg
* @wdh: get wdh
* @prc: prc specification
* @sz: sz specifier
* Return: Number of chars printed.
*/
int print_hexa_upper(va_list types, char bff[],
int flg, int wdh, int prc, int sz)
{
return (print_hexa(types, "0123456789ABCDEF", bff,
flg, 'X', wdh, prc, sz));
}

/**
* print_hexa - Prints a hexadecimal number in lower or upper
* @types: lsta of arguments
* @map_to: Array of values to map the number to
* @bff: bff array to handle print
* @flg:  Calculates active flg
* @flag_ch: Calculates active flg
* @wdh: get wdh
* @prc: prc specification
* @sz: sz specifier
* @sz: sz specification
* Return: Number of chars printed.
*/
int print_hexa(va_list types, char map_to[], char bff[],
int flg, char flag_ch, int wdh, int prc, int sz)
{
int i = BFF_sz - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;

UNUSED(wdh);

num = convert_sz_unsgnd(num, sz);

if (num == 0)
bff[i--] = '0';

bff[BFF_sz - 1] = '\0';

while (num > 0)
{
bff[i--] = map_to[num % 16];
num /= 16;
}

if (flg & F_H && init_num != 0)
{
bff[i--] = flag_ch;
bff[i--] = '0';
}

i++;

return (write_unsgnd(0, i, bff, flg, wdh, prc, sz));
}

