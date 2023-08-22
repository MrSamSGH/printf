#include "main.h"

/**
* get_flg - Calculates active flg
* @format: Formatted string in which to print the arguments
* @i: take a parameter.
* Return: Flags:
*/
int get_flg(const char *format, int *i)
{
int j, curr_i;
int flg = 0;
const char flg_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int flg_ARR[] = {F_MN, F_PL, F_ZR, F_H, F_SP, 0};

for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
{
for (j = 0; flg_CH[j] != '\0'; j++)
if (format[curr_i] == flg_CH[j])
{
flg |= flg_ARR[j];
break;
}

if (flg_CH[j] == 0)
break;
}

*i = curr_i - 1;

return (flg);
}

