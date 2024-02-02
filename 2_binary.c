#include "main.h"
/*********************** PRINTS UNSIGNED NUMBER***********************/
/**
* print_unsigned - Prints out an unsigned number
* @types: List a of arguments
* @buffer: Buffer array to handle printing
* @flags: Calculates the active flags
* @width: gets width
* @precision: Precisions specification
* @size: Size specifier
* Return: Number of chars printed.
*/
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision,
size));
}
/*****************PRINTS UNSIGNED NUMBERS IN OCTAL ****************/
/**
* print_octal - Prints out an unsigned number in octal notation
* @types: Lista of argumentss
* @buffer: Buffer array that handles print
* @flags: Calculates the active flags
* @width: gets width
* @precision: Precision specifications
* @size: Size specifier
* Return: Number of char printed
*/
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = (num % 8) + '0';
num /= 8;
}
if (flags & F_HASH && init_num != 0)
buffer[i--] = '0';
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision,
size));
}
/***************** PRINT UNSIGNED NUMBERS IN HEXADECIMAL FORM ***********/
/**
* print_hexadecimal - Prints out an unsigned number in hexadecimal notation
* @types: List of argumentss
* @buffer: Buffer array to handle the print
* @flags: Calculates the active flags
* @width: gets width
* @precision: Precision specifications
* @size: Size specifier
* Return: Number of chars that are printed
*/
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}
/*************** PRINTS UNSIGNED NUMBER IN UPPER HEXADECIMAL**************/
/**
* print_hexa_upper - Prints out an unsigned number in upper hexadecimal notation
* @types: Lista of the arguments
* @buffer: Buffer array to handle the print
* @flags: Calculates the active flags
* @width: gets width
* @precision: Precision specifications
* @size: Size specifier
* Return: Number of chars that are printed
*/
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}
/****************** PRINTT HEXX NUM IN LOWER OR UPPER **************/
/**
* print_hexa - Prints a hexadecimal number in lower or upper case
* @types: Lista of the arguments
* @map_to: Array of values that number is mapped to
* @buffer: Buffer array to handle the print
* @flags: Calculates active flags
* @flag_ch: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* @size: Size specification
* Return: Number of chars printed
*/
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = map_to[num % 16];
num /= 16;
}
if (flags & F_HASH && init_num != 0)
{
buffer[i--] = flag_ch;
buffer[i--] = '0';
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision,
size));
}
