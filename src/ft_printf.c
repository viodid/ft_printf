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

int ft_printf(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
	int i = va_arg(ap, int);
	printf("%d\n", i);
	char *s = va_arg(ap, char *);
	printf("%s\n", s);
	va_end(ap);
	return (0);
}
