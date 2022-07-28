/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollarbills.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:04:01 by nspeedy           #+#    #+#             */
/*   Updated: 2022/07/28 22:32:00 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_d;

t_dollar	*find(char *n_args, t_dollar *d)
{
	d->found = d->i - 1;
	d->find = d->i;
	if (n_args[d->i] == '?')
		ft_printf("%d\n", g_d.statval);
	else
	{
		while (n_args[d->i] != '$'
			&& n_args[d->i] != ' ' && n_args[d->i] != '\0'
			&& n_args[d->i] != '\'' && n_args[d->i] != '"')
		{
			d->found++;
			d->i++;
		}
		d->prev = ft_substr(n_args, 0, d->find - 1);
		d->tmp = ft_substr(n_args, d->find, d->found - d->find + 1);
		d->str = ft_substr(n_args, d->found + 1, ft_strlen(n_args));
	}
	return (d);
}

bool	isdollar(t_dollar *d, char **n_args)
{
	int	first_len;
	int	offset;

	if (ft_strncmp(d->tmp, g_d.env[d->envi], ft_strlen(d->tmp)) == 0)
	{
		first_len = ft_strlen(d->tmp) + 1;
		d->tmp = ft_strchr(g_d.env[d->envi], '=') + 1;
		offset = first_len - ft_strlen(d->tmp);
		*n_args = ft_strjoin(d->prev, d->tmp);
		*n_args = ft_strjoin(*n_args, d->str);
		d->envi = 0;
		d->i -= offset;
		return (true);
	}
	return (false);
}

void	handle_quotes(t_dollar *d, t_qbool *q, char *n_args)
{
	if (n_args[d->i] == '\'')
		q->inq = true;
	if (n_args[d->i] == '"' && q->indq)
	{
		d->i++;
		q->indq = false;
	}
	if (n_args[d->i] == '"')
		q->indq = true;
}

char	*dollar_bils(char *n_args)
{
	t_dollar	d;
	t_qbool		q;

	memset(&d, 0, sizeof(t_dollar));
	q.inq = false;
	q.indq = false;
	while (n_args[d.i] != '\0')
	{
		handle_quotes(&d, &q, n_args);
		if (n_args[d.i++] == '$' && (!q.inq || q.indq))
		{
			find(n_args, &d);
			while (g_d.env[d.envi])
			{
				if (isdollar(&d, &n_args))
					break ;
				d.envi++;
			}
		}
		d.find = 0;
	}
	return (n_args);
}
