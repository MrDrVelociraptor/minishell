/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <nspeedy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:51:14 by nspeedy           #+#    #+#             */
/*   Updated: 2022/07/15 15:57:54 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	g_d;

int	main(void)
{
	int		new_p[2];
	int		old_p[2];

	siggles();
	g_d.env = ft_fill_envs();
	g_d.cmdline = readline(">>> ");
	while (g_d.cmdline != NULL)
	{
		g_d.arglist = space_split(g_d.cmdline, '|');
		exsit(g_d.cmdline, g_d.arglist);
		if (g_d.arglist != NULL)
		{
			add_history(g_d.cmdline);
			if (manage(old_p, new_p) == 1)
				return (1);
			free_strarray(g_d.arglist);
		}
		free(g_d.cmdline);
		g_d.cmdline = readline(">>> ");
	}
	return (0);
}
