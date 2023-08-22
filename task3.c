#include "main.h"

/**
* handle_write_char - Prints a string
* @c: char types.
* @bff: bff array to handle print
* @flg:  Calculates active flg.
* @wdh: get wdh.
* @prc: prc specifier
* @sz: sz specifier
* Return: Number of chars printed.
*/
int handle_write_char(char c, char bff[],
int flg, int wdh, int prc, int sz)
{
int i = 0;
char padd = ' ';

UNUSED(prc);
UNUSED(sz);

if (flg & F_ZR)
padd = '0';

bff[i++] = c;
bff[i] = '\0';

if (wdh > 1)
{
bff[BFF_sz - 1] = '\0';
for (i = 0; i < wdh - 1; i++)
bff[BFF_sz - i - 2] = padd;

if (flg & F_MN)
return (write(1, &bff[0], 1) +
write(1, &bff[BFF_sz - i - 1], wdh - 1));
else
return (write(1, &bff[BFF_sz - i - 1], wdh - 1) +
write(1, &bff[0], 1));
}

return (write(1, &bff[0], 1));
}

/**
* write_number - Prints a string
* @is_ng: lsta of arguments
* @ind: char types.
* @bff: bff array to handle print
* @flg:  Calculates active flg
* @wdh: get wdh.
* @prc: prc specifier
* @sz: sz specifier
* Return: Number of chars prt.
*/
int write_number(int is_ng, int ind, char bff[],
int flg, int wdh, int prc, int sz)
{
int length = BFF_sz - ind - 1;
char padd = ' ', ex_ch = 0;

UNUSED(sz);

if ((flg & F_ZR) && !(flg & F_MN))
padd = '0';
if (is_ng)
ex_ch = '-';
else if (flg & F_PL)
ex_ch = '+';
else if (flg & F_SP)
ex_ch = ' ';

return (write_num(ind, bff, flg, wdh, prc,
length, padd, ex_ch));
}

/**
* write_num - Write a number using a bufffer
* @ind: Index at which the number starts on the bff
* @bff: bff
* @flg: flg
* @wdh: wdh
* @prec: prc specifier
* @length: Number length
* @padd: Pading char
* @ex_c: Extra char
* Return: Number of printed chars.
*/
int write_num(int ind, char bff[],
int flg, int wdh, int prec,
int length, char padd, char ex_c)
{
int i, padd_start = 1;

if (prec == 0 && ind == BFF_sz - 2 && bff[ind] == '0' && wdh == 0)
return (0); /* printf(".0d", 0)  no char is prt */
if (prec == 0 && ind == BFF_sz - 2 && bff[ind] == '0')
bff[ind] = padd = ' ';
if (prec > 0 && prec < length)
padd = ' ';
while (prec > length)
bff[--ind] = '0', length++;
if (ex_c != 0)
length++;
if (wdh > length)
{
for (i = 1; i < wdh - length + 1; i++)
bff[i] = padd;
bff[i] = '\0';
if (flg & F_MN && padd == ' ')
{
if (ex_c)
bff[--ind] = ex_c;
return (write(1, &bff[ind], length) + write(1, &bff[1], i - 1));
}
else if (!(flg & F_MN) && padd == ' ')/* extra char to left of buff */
{
if (ex_c)
bff[--ind] = ex_c;
return (write(1, &bff[1], i - 1) + write(1, &bff[ind], length));
}
else if (!(flg & F_MN) && padd == '0')
{
if (ex_c)
bff[--padd_start] = ex_c;
return (write(1, &bff[padd_start], i - padd_start) +
write(1, &bff[ind], length - (1 - padd_start)));
}
}
if (ex_c)
bff[--ind] = ex_c;
return (write(1, &bff[ind], length));
}

/**
* write_unsgnd - Writes an unsigned number
* @is_ng: Number indicating if the num is negative
* @ind: Index at which the number starts in the bff
* @bff: Array of chars
* @flg: flg specifiers
* @wdh: wdh specifier
* @prc: prc specifier
* @sz: sz specifier
* Return: Number of written chars.
*/
int write_unsgnd(int is_ng, int ind,
char bff[],
int flg, int wdh, int prc, int sz)
{

int length = BFF_sz - ind - 1, i = 0;
char padd = ' ';

UNUSED(is_ng);
UNUSED(sz);

if (prc == 0 && ind == BFF_sz - 2 && bff[ind] == '0')
return (0);

if (prc > 0 && prc < length)
padd = ' ';

while (prc > length)
{
bff[--ind] = '0';
length++;
}

if ((flg & F_ZR) && !(flg & F_MN))
padd = '0';

if (wdh > length)
{
for (i = 0; i < wdh - length; i++)
bff[i] = padd;

bff[i] = '\0';

if (flg & F_MN)
{
return (write(1, &bff[ind], length) + write(1, &bff[0], i));
}
else
{
return (write(1, &bff[0], i) + write(1, &bff[ind], length));
}
}

return (write(1, &bff[ind], length));
}

/**
* write_pointer - Write a memory address
* @bff: Arrays of chars
* @ind: Index at which the number starts in the bff
* @length: Length of number
* @wdh: Wwdh specifier
* @flg: flg specifier
* @padd: Char representing the padding
* @ex_c: Char representing extra char
* @padd_start: Index at which padding should start
* Return: Number of written chars.
*/
int write_pointer(char bff[], int ind, int length,
int wdh, int flg, char padd, char ex_c, int padd_start)
{
int i;

if (wdh > length)
{
for (i = 3; i < wdh - length + 3; i++)
bff[i] = padd;
bff[i] = '\0';
if (flg & F_MN && padd == ' ')
{
bff[--ind] = 'x';
bff[--ind] = '0';
if (ex_c)
bff[--ind] = ex_c;
return (write(1, &bff[ind], length) + write(1, &bff[3], i - 3));
}
else if (!(flg & F_MN) && padd == ' ')
{
bff[--ind] = 'x';
bff[--ind] = '0';
if (ex_c)
bff[--ind] = ex_c;
return (write(1, &bff[3], i - 3) + write(1, &bff[ind], length));
}
else if (!(flg & F_MN) && padd == '0')/* extra char to left of padd */
{
if (ex_c)
bff[--padd_start] = ex_c;
bff[1] = '0';
bff[2] = 'x';
return (write(1, &bff[padd_start], i - padd_start) +
write(1, &bff[ind], length - (1 - padd_start) - 2));
}
}
bff[--ind] = 'x';
bff[--ind] = '0';
if (ex_c)
bff[--ind] = ex_c;
return (write(1, &bff[ind], BFF_sz - ind - 1));
}

