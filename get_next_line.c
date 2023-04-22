/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:43:16 by ntairatt          #+#    #+#             */
/*   Updated: 2023/04/22 23:10:45 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*split_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	i = 0;
	if (!line || !buf[i])
	{
		free(line);
		return (NULL);
	}
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_buf(char *buf)
{
	char	*new_buf;
	int		i;
	int		j;

	i = 0;
	j = next_char(buf, '\n');
	if (j < 1)
	{
		free(buf);
		return (NULL);
	}
	new_buf = (char *)malloc(sizeof(char) * (ft_strlen(buf) - i + 1));
	if (!new_buf)
		return (NULL);
	while (buf[j] != '\0')
		new_buf[i++] = buf[j++];
	new_buf[i] = '\0';
	free(buf);
	return (new_buf);
}

char	*get_buf(int fd, char *buf)
{
	int		n_read;
	char	*new_line;

	n_read = 1;
	new_line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	while (n_read > 0)
	{
		n_read = read(fd, new_line, BUFFER_SIZE);
		if (n_read == -1)
		{
			free(new_line);
			return (NULL);
		}
		new_line[n_read] = '\0';
		buf = ft_strjoin(buf, new_line);
		if (next_char(buf, '\n'))
			break ;
	}
	free(new_line);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > 1024)
		return (NULL);
	buf = get_buf(fd, buf);
	if (!buf)
		return (NULL);
	line = split_line(buf);
	buf = update_buf(buf);
	return (line);
}
