#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/* flg */
#define F_MN 1
#define F_PL 2
#define F_ZR 4
#define F_H 8
#define F_SP 16

/* szS */
#define S_LN 2
#define S_SHR 1

#define UNUSED(x) (void)(x)
#define BFF_sz 1024

/**
 * struct fmtt - Struct op
 *
 * @fmtt: The format.
 * @fn: The function associated.
 */
struct fmtt
{
	char fmtt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmtt fmtt_t - Struct op
 *
 * @fmtt: The format.
 * @fm_tt: The function associated.
 */
typedef struct fmtt fmtt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmtt, int *i,
va_list lst, char bff[], int flg, int wdh, int prc, int sz);


/* Funtions to print chars and strings */
int print_char(va_list types, char bff[], int flg, int wdh,
		int prc, int sz);
int print_string(va_list types, char bff[],
	int flg, int wdh, int prc, int sz);
int print_percent(va_list types, char bff[],
	int flg, int wdh, int prc, int sz);

/* Functions to print numbers */
int print_int(va_list types, char bff[],
	int flg, int wdh, int prc, int sz);
int print_binary(va_list types, char bff[],
	int flg, int wdh, int prc, int sz);
int print_unsigned(va_list types, char bff[],
	int flg, int wdh, int prc, int sz);
int print_octal(va_list types, char bff[],
	int flg, int wdh, int prc, int sz);
int print_hexadecimal(va_list types, char bff[],
	int flg, int wdh, int prc, int sz);
int print_hexa_upper(va_list types, char bff[],
	int flg, int wdh, int prc, int sz);

int print_hexa(va_list types, char map_to[],
char bff[], int flg, char flag_ch, int wdh, int prc, int sz);

/* Function to print non printable characters */
int print_non_printable(va_list types, char bff[],
	int flg, int wdh, int prc, int sz);

/* Funcion to print memory address */
int print_pointer(va_list types, char bff[],
	int flg, int wdh, int prc, int sz);

/* Funciotns to handle other specifiers */
int get_flg(const char *format, int *i);
int get_wdh(const char *format, int *i, va_list lst);
int get_prc(const char *format, int *i, va_list lst);
int get_sz(const char *format, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list types, char bff[],
	int flg, int wdh, int prc, int sz);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char bff[],
	int flg, int wdh, int prc, int sz);

/* wdh handler */
int handle_write_char(char c, char bff[],
	int flg, int wdh, int prc, int sz);
int write_number(int is_positive, int ind, char bff[],
	int flg, int wdh, int prc, int sz);
int write_num(int ind, char bff[], int flg, int wdh, int prc,
	int length, char padd, char ex_c);
int write_pointer(char bff[], int ind, int length,
	int wdh, int flg, char padd, char ex_c, int padd_start);

int write_unsgnd(int is_ng, int ind,
char bff[],
	int flg, int wdh, int prc, int sz);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_sz_number(long int num, int sz);
long int convert_sz_unsgnd(unsigned long int num, int sz);

#endif
