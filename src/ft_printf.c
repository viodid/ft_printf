/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:04:20 by dyunta            #+#    #+#             */
/*   Updated: 2023/03/21 19:47:48 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"
#include <stdarg.h>
#include <stdio.h>

/*
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.L
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
*/

// BONUS
/* Field minimum width:
https://www.lix.polytechnique.fr/
~liberti/public/computing/prog/c/C/FUNCTIONS/format.html#width */
/*
• %- Left-justify within the given field width; Right justification is the
default (see width sub-specifier).

• %0 Left-pads the number with zeroes (0) instead of spaces when padding is
specified (see width sub-specifier).

• %. For integer specifiers (d, i, u, x, X) − precision specifies
the minimum number of digits to be written. If the value to be written is
shorter than this number, the result is padded with leading zeros. The value
is not truncated even if the result is longer. A precision of 0 means that no
character is written for the value 0. For s − this is the maximum number of
characters to be printed. For c type − it has no effect. 
By default all characters are printed until the ending null character is
encountered. If The period is specified without an explicit value for
precision, 0 is assumed.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
		ft_putchar_fd(*str++, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = (unsigned int)(n * -1);
	}
	else
		nb = (unsigned int)n;
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd((char)(nb % 10 + 48), fd);
}

// Malloc enough bytes to store the hex digits
char	*getHexDigits(void) {
	int i;
	char *hexDigits;

	hexDigits = (char *)malloc(16 * sizeof(char));
	while (i < 10) {
		hexDigits[i] = '0' + i;
		i++;
	}
	while (i < 16) {
		hexDigits[i] = 'a' + i - 10;
		i++;
	}
	return hexDigits;
}

// The address string is built by iterating through the address value
// and converting each remainder to a hexadecimal digit.
// The size of the addressString array should be large enough to hold the
// the maximum number of hexadecimal digits required to represent the address.
// Since each hexadecimal digit represents 4 bits, and a typical pointer
// size is 8 bytes (64 bits), the maximum number of hexadecimal digits needed is 16.
// Therefore, a buffer of 20 characters (including space for the "0x" prefix
// and null terminator) provides sufficient space for the hexadecimal representation.
//
// Using a buffer that is too small could lead to buffer overflow and undefined behavior.

void printAddress(void* address) {
    char addressString[20];
    int numBytes;
    char *hexDigits;
    unsigned long long int addressValue = (unsigned long long int)address;

	numBytes = 0;
	hexDigits = getHexDigits();
    while (addressValue > 0) {
        int remainder = addressValue % 16;
        addressString[numBytes++] = hexDigits[remainder];
        addressValue /= 16;
    }

    write(STDOUT_FILENO, "0x", 2);
    for (int i = numBytes - 1; i >= 0; i--) {
        write(STDOUT_FILENO, &(addressString[i]), 1);
    }
    write(STDOUT_FILENO, "\n", 1);
}

int ft_printf(const char *str, ...)
{
	va_list ap;

	if (!str)
		return (0);
	va_start(ap, str);
	while (*str)
	{
		if (*str++ == '%')
		{
			if (*str == 'c')
				ft_putchar_fd(va_arg(ap, int), 1);
			else if (*str == 's')
				ft_putstr_fd(va_arg(ap, char *), 1);
			else if (*str == 'p')
				ft_putnbr_fd(va_arg(ap, int), 1);
			else if (*str == 'd' || *str == 'i')
				ft_putnbr_fd(va_arg(ap, int), 1);
			else if (*str == 'u')
				ft_putnbr_fd(va_arg(ap, unsigned int), 1);
			else if (*str == 'x')
				ft_putnbr_fd(va_arg(ap, int), 1);
			else if (*str == 'X')
				ft_putnbr_fd(va_arg(ap, int), 1);
			else if (*str == '%')
				ft_putchar_fd('%', 1);
			else
				return (0);
		}
		else
			ft_putchar_fd(*str, 1);
		str++;
	}

	ft_strchr(str, '%');
	int i = va_arg(ap, int);
	printf("%d\n", i);
	char *s = va_arg(ap, char *);
	printf("%s\n", s);
	va_end(ap);
	return (0);
}
