/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 08:55:51 by nspeedy           #+#    #+#             */
/*   Updated: 2021/12/20 12:06:31 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*gnl_read_line(int fd, char *buf, char *store)
{
	int		read_line;
	char	*temp;

	read_line = 1;
	while (read_line > 0)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (0);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!store)
			store = ft_strdup("");
		temp = store;
		store = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (store);
}

static char	*gnl_append_new_line(char *line)
{
	size_t	count_nl;
	char	*store;

	count_nl = 0;
	while (line[count_nl] != '\n' && line[count_nl] != '\0')
		count_nl++;
	if (line[count_nl] == '\0')
		return (0);
	store = ft_substr(line, count_nl + 1, ft_strlen(line) - count_nl);
	if (*store == '\0')
	{
		free(store);
		store = 0;
	}
	line[count_nl + 1] = '\0';
	return (store);
}

char	*ft_get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*store;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	line = gnl_read_line(fd, buf, store);
	free(buf);
	buf = NULL;
	if (!line)
		return (line);
	store = gnl_append_new_line(line);
	return (line);
}
