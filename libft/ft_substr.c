/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:04:15 by dyunta            #+#    #+#             */
/*   Updated: 2023/02/08 00:04:15 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’. */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	alloc_size;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	alloc_size = ft_strlen(s) - start;
	if (alloc_size > len)
		alloc_size = len;
	str = (char *)malloc(sizeof(char) * alloc_size + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, alloc_size + 1);
	return (str);
}
