/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:43:16 by ntairatt          #+#    #+#             */
/*   Updated: 2023/04/07 20:36:47 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_line(char *line, char *buf)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	while (line[i])
	{
		buf[j] = line[i];
		i++;
		j++;
	}
	return (new_line);
}

char	*get_line(int fd, char *line, char *buf)
{
	int	n_read;

	n_read = 1;
	while (n_read > 0 && !ft_strchr(line, '\n'))
	{
		n_read = read(fd, buf, BUFFER_SIZE);
		if (n_read == -1)
			return (NULL);
		buf[n_read] = '\0';
		line = ft_strjoin(line, buf);
	}
	line = update_line(line, buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	line = get_line(fd, line, buf);
	return (line);
}

#include <stdio.h>

int	main()
{
	int fd1 = open("abc.txt", O_RDONLY);
	char *s;
	int i = 0;
	while (i++ < 1)
	{
		s = get_next_line(fd1);
		printf("s = %s\n", s);
	}
	close(fd1);
}
