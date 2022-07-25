/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <nspeedy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:11:29 by nspeedy           #+#    #+#             */
/*   Updated: 2022/07/25 17:17:16 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_d;

static int	ft_fillsplit(const char *str, char **split, int len, char delim)
{
	t_split	s;

	memset(&s, 0, 14);
	while (s.i < len)
	{
		s.j = 0;
		while ((str[s.i + s.j] != delim || s.inquote || str[s.i + s.j - 1] == delim) && str[s.i + s.j])
		{
			check_quotes(&s, str, s.i + s.j);
			s.j++;
		}
		if (s.j != 0)
		{
			split[s.k] = (char *)malloc(sizeof(char) * (s.j + 1));
			if (!split[s.k])
				return (-1);
			ft_strlcpy(split[s.k], &str[s.i], s.j + 1);
			s.k++;
		}
		s.i++;
		s.i += s.j;
	}
	return (s.k);
}

char	**single_split(const char *s, char delim)
{
	char	**split;
	t_split	sp;

	memset(&sp, 0, 14);
	while (s[sp.i])
	{
		check_quotes(&sp, s, sp.i);
		if (s[sp.i] == delim && !sp.inquote && s[sp.i - 1] != delim)
			sp.k++;
		sp.i++;
	}
	split = (char **)malloc(sizeof(char *) * (sp.k + 2));
	if (!split)
		return (NULL);
	sp.k = ft_fillsplit(s, split, sp.i, delim);
	if (sp.k == -1)
		return (NULL);
	split[sp.k] = NULL;
	return (split);
}

int	heredoc(char *eof)
{
	char	*line;
	int		p[2];

	if (pipe(p) == -1)
	{
		printf("bad pipe\n");
		return (-1);
	}
	line = readline("> ");
	while (strncmp(line, eof, ft_strlen(line)))
	{
		write(p[1], line, ft_strlen(line));
		write(p[1], "\n", 1);
		line = readline("> ");
	}
	close(p[1]);
	return (p[0]);
}

int	redirect(int i)
{
	int		j;
	int		fd;
	char	**r;

	j = 1;
	r = single_split(g_d.arglist[i], '>');
	while (r[j])
	{
		if (r[j][0] == '>')
			fd = open(space_split(r[j] + 1, ' ')[0], O_WRONLY | O_APPEND | O_CREAT, 0644);
		else
			fd = open(space_split(r[j], ' ')[0], O_CREAT | O_RDWR | O_TRUNC, 0644);
		dup2(fd, 1);
		close(fd);
		j++;
	}
	if (j > 1)
		*ft_strchr(g_d.arglist[i], '>') = '\0';
	free(r);
	j = 1;
	r = single_split(g_d.arglist[i], '<');
	while (r[j])
	{
		if (r[j][0] == '<')
		{
			fd = heredoc(space_split(r[j] + 1, ' ')[0]);
			if (fd == -1)
				return (1);
		}
		else
			fd = open(space_split(r[j], ' ')[0], O_RDONLY, 0644);
		dup2(fd, 0);
		close(fd);
		j++;
	}
	if (j > 1)
		*ft_strchr(g_d.arglist[i], '<') = '\0';
	return (0);
}
