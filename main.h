#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

/* 4. */
#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1


#define NULL_STRING "(null)"
/* intializing all the parameters */
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @unsign: unsigned value
 *
 * @plus_flag: plus_flag specified
 * @space_flag: hashtag_flag specified
 * @hashtag_flag: _flag specified
 * @zero_flag: _flag specified
 * @minus_flag: _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */
typedef struct parameters
{
	unsigned int unsign		: 1;
	/* 7. */
	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	/* 11. */
	unsigned int zero_flag		: 1;
	/* 12. */
	unsigned int minus_flag		: 1;
	/* 9. */
	unsigned int width;
	/* 10 */
	unsigned int precision;
	/* 8. */
	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* _put.c module */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c module */
/* 0. */
int print_char(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
/* 1. */
int print_int(va_list ap, params_t *params);
/* 5. */
int print_S(va_list ap, params_t *params);

/* number.c module */
char *convert(long int num, int base, int flags, params_t *params);
/* 3. */
int print_unsigned(va_list ap, params_t *params);
/* 6. */
int print_address(va_list ap, params_t *params);

/* specifier.c module */
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/* convert_number.c module */
/* 3. */
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);
/* 2. */
int print_binary(va_list ap, params_t *params);

/* simple_printers.c module */
int print_from_to(char *start, char *stop, char *except);
/* 13. */
int print_rev(va_list ap, params_t *params);
/* 14. */
int print_rot13(va_list ap, params_t *params);

/* print_number.c module */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* params.c module */
void init_params(params_t *params, va_list ap);

/* string_fields.c modoule */
char *get_precision(char *p, params_t *params, va_list ap);

/* _prinf.c module */
/* 0. */
int _printf(const char *format, ...);

#endif
