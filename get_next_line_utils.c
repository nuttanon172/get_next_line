/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:43:48 by ntairatt          #+#    #+#             */
/*   Updated: 2023/04/07 20:26:50 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fs;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	fs = (char *)malloc(((s1_len + s2_len + 1) * sizeof(char)));
	if (!fs)
		return (0);
	while (*s1)
	{
		fs[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		fs[i] = *s2++;
		i++;
	}
	fs[i] = '\0';
	return (fs);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (*(s + i) == (char)c)
		return ((char *)s + i);
	return (0);
}
