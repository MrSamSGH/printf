#include "main.h"
/**
* convert_sz_unsgnd - Casts a number to the specified sz
* @num: Number to be casted
* @sz: Number indicating the type to be casted
* Return: Casted value of num
*/
long int convert_sz_unsgnd(unsigned long int num, int sz)
{
if (sz == S_LN)
return (num);
else if (sz == S_SHR)
return ((unsigned short)num);

return ((unsigned int)num);
}
