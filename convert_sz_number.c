#include "main.h"

/**
* convert_sz_number - Casts a number to the specified sz
* @num: Number to be casted.
* @sz: Number indicating the type to be casted.
* Return: Casted value of num
*/
long int convert_sz_number(long int num, int sz)
{
if (sz == S_LN)
return (num);
else if (sz == S_SHR)
return ((short)num);

return ((int)num);
}
