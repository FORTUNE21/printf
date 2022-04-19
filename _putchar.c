#include <unistd.h>

/**
 *  _putchar - write a character
 *  @c: the character to print to stdout
 *
 *  Return : int
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
