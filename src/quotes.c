/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:03:37 by nspeedy           #+#    #+#             */
/*   Updated: 2022/07/28 13:47:48 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_d;

void	check_quotes(t_split *sp, const char *s, int i)
{
	if (s[i] == '\"' || s[i] == '\'')
	{
		if (s[i] == sp->c)
		{
			sp->inquote = false;
			sp->c = '\0';
		}
		else if (sp->inquote)
			return ;
		else
		{
			sp->inquote = true;
			sp->c = s[i];
		}
	}
}

static size_t	new_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	track;
	size_t	length;
	size_t	offset;
	t_split	s;

	length = ft_strlen(src);
	if (size == 0)
		return (length);
	track = 0;
	offset = 0;
	s.inquote = false;
	while (src[track] && track < size)
	{
		if ((src[track] != '\'' && src[track] != '"')
			|| (s.inquote && src[track] != s.c))
			dest[track - offset] = src[track];
		else
		{
			q_check(&s, src, track);
			offset++;
		}
		track++;
	}
	dest[track - offset] = '\0';
	return (length);
}

void	rm_quote(char *str)
{
	char	*tmp;
	int		len;

	if (ft_strrchr(str, '"') || ft_strrchr(str, '\''))
	{
		len = ft_strlen(str);
		tmp = (char *)malloc(sizeof(char) * (len - 2));
		new_strlcpy(tmp, str, len);
		ft_strlcpy(str, tmp, len);
		free(tmp);
	}
}

static int	ft_fillsplit(const char *str, char **split, int len, char delim)
{
	t_split	s;

	memset(&s, 0, 14);
	while (s.i < len)
	{
		s.j = 0;
		while ((str[s.i + s.j] != delim || s.inquote) && str[s.i + s.j])
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

char	**space_split(const char *s, char delim)
{
	char	**split;
	t_split	sp;

	memset(&sp, 0, 14);
	while (s[sp.i])
	{
		check_quotes(&sp, s, sp.i);
		if (s[sp.i] == delim && !sp.inquote)
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
