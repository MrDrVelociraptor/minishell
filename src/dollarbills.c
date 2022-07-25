/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollarbills.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <arowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:04:01 by nspeedy           #+#    #+#             */
/*   Updated: 2022/07/25 16:50:15 by arowe            ###   ########.fr       */
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
			&& n_args[d->i] != ' ' && n_args[d->i] != '\0')
		{
			d->found++;
			d->i++;
		}
		d->prev = ft_substr(n_args, 0, d->find - 1);
		d->tmp = ft_substr(n_args, d->find, d->found - d->find);
		d->str = ft_substr(n_args, d->found + 1, ft_strlen(n_args));
	}
	return (d);
}

bool	isdollar(t_dollar *d, char **n_args)
{
	if (ft_strncmp(d->tmp, g_d.env[d->envi], ft_strlen(d->tmp)) == 0)
	{
		d->tmp = ft_strchr(g_d.env[d->envi], '=') + 1;
		*n_args = ft_strjoin(d->prev, d->tmp);
		*n_args = ft_strjoin(*n_args, d->str);
		d->i = 0;
		d->envi = 0;
		return (true);
	}
	return (false);
}

char	*dollar_bils(char *n_args)
{
	t_dollar	d;
	bool		inquote;

	memset(&d, 0, sizeof(t_dollar));
	inquote = false;
	while (n_args[d.i] != '\0')
	{
		if (n_args[d.i] == '\'')
			inquote = true;
		if (n_args[d.i++] == '$' && !inquote)
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
