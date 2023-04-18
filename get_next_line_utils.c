/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:43:48 by ntairatt          #+#    #+#             */
/*   Updated: 2023/04/18 22:06:58 by ntairatt         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*fs;
	size_t	i;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		*s1 = 0;
	}
	i = 0;
	fs = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char)));
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

int	next_char(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}
