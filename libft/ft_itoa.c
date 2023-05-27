/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:04:15 by dyunta            #+#    #+#             */
/*   Updated: 2023/02/08 00:04:15 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled. */

static int	get_int_len(long long n);
static char	*reverse_str(char *str, int index);
static int	checkers(long long n, char *buffer);

char	*ft_itoa(int n)
{
	int			is_neg;
	int			i;
	char		*buffer;
	long long	long_n;

	long_n = (long long)n;
	is_neg = 0;
	i = 0;
	if (long_n < 0)
		is_neg = 1;
	buffer = (char *)malloc(sizeof(char) * get_int_len(long_n) + 1 + is_neg);
	if (!buffer)
		return (NULL);
	if (is_neg)
		long_n *= -1;
	if (checkers(long_n, buffer))
		return (buffer);
	while (long_n)
	{
		buffer[i++] = (long_n % 10) + '0';
		long_n /= 10;
	}
	if (is_neg)
		buffer[i++] = '-';
	return (reverse_str(buffer, i));
}

static int	get_int_len(long long n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*reverse_str(char *str, int index)
{
	char	aux;
	int		i;
	int		j;

	str[index] = '\0';
	i = 0;
	j = (int)ft_strlen(str) - 1;
	while (i < j)
	{
		aux = str[i];
		str[i] = str[j];
		str[j] = aux;
		i++;
		j--;
	}
	return (str);
}

static int	checkers(long long n, char *buffer)
{
	if (n == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return (1);
	}
	return (0);
}
