/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:04:15 by dyunta            #+#    #+#             */
/*   Updated: 2023/02/08 00:04:15 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://stackoverflow.com/questions
// /20725573/what-is-overlapping-in-memmove-definition
// https://aticleworld.com/memmove-function-implementation-in-c/

#include "libft.h"

/* The memmove() function copies len bytes from string src to string dst.
     The two strings may overlap; the copy is always done in a non-destructive
     manner. 
	
	The memmove() function returns the original value of dst.*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr;

	if (!dst && !src)
		return (NULL);
	ptr = dst;
	if (src < dst)
	{
		while (len--)
			*(ptr + len) = *((char *)src + len);
		return (dst);
	}
	if (src > dst)
	{
		while (len--)
			*ptr++ = *(char *)src++;
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}
