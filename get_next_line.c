/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:43:16 by ntairatt          #+#    #+#             */
/*   Updated: 2023/04/18 22:57:00 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
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
	if (!fs || (!*s1 && !*s2))
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
}*/

char	*split_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf)
	{
		free(buf);
		return (NULL);
	}
	line = (char *)malloc(ft_strlen(buf) * sizeof(char));
	if (!line)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		line[i] = buf[i];
		i++;
	}
	return (line);
}

char	*update_buf(char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = next_char(buf, '\n');
	if (j <= 0)
		return (NULL);
	while(buf[j])
		buf[i++] = buf[j++];
	buf[i] = '\0';
	return (buf);
}

char	*get_buf(int fd, char *buf)
{
	int		n_read;
	char	*new_line;

	n_read = 1;
	new_line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	while (next_char(buf, '\n') == 0 && n_read > 0)
	{
		n_read = read(fd, new_line, BUFFER_SIZE);
		if (n_read == -1)
		{
			free(new_line);
			return (NULL);
		}
		new_line[n_read] = '\0';
		buf = ft_strjoin(buf, new_line);
	}
	free(new_line);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	buf = get_buf(fd, buf);
	line = split_line(buf);
	buf = update_buf(buf);
	return (line);
}
