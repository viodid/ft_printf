/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:04:15 by dyunta            #+#    #+#             */
/*   Updated: 2023/02/08 00:04:15 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*   The strdup() function allocates sufficient memory for a copy of the
     string str, does the copy, and returns a pointer to it.  The pointer may
     subsequently be used as an argument to the function free(3). */

char	*ft_strdup(const char *str)
{
	int		len;
	char	*ptr;
	char	*start_ptr;

	len = (int)ft_strlen(str);
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	start_ptr = ptr;
	while (*str)
		*ptr++ = *(char *)str++;
	*ptr = '\0';
	return (start_ptr);
}
