#include "main.h"

/**
* _putchar - writes the character c to stdout
* @c: Character to be printed
*
* Return: On success 1 or -1 on error, and errno is
* set appropiately
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
