/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyunta <dyunta@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:04:15 by dyunta            #+#    #+#             */
/*   Updated: 2023/02/08 00:04:15 by dyunta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string. */

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	while (ft_strchr(set, (int)s1[i]) && s1[i])
		i++;
	if (i >= (int)ft_strlen(s1))
		return (ft_strdup(""));
	j = (int)ft_strlen(s1);
	while (ft_strchr(set, (int)s1[j]))
		j--;
	ptr = (char *)malloc(sizeof(char) * j - i + 2);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s1[i], j - i + 2);
	return (ptr);
}
