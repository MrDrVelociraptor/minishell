
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:26:22 by alex              #+#    #+#             */
/*   Updated: 2022/07/13 16:48:22 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_d;

void	ch_cwd(char path[], char oldpath[])
{
	int		i;

	i = 0;
	while (g_d.env && g_d.env[i])
		i++;
	i = 0;
	while (g_d.env && g_d.env[i])
	{
		if (ft_strncmp(g_d.env[i], "PWD=", 4) == 0)
			g_d.env[i] = ft_strjoin("PWD=", path);
		else if (ft_strncmp(g_d.env[i], "OLDPWD=", 7) == 0)
			g_d.env[i] = ft_strjoin("OLDPWD=", oldpath);
		i++;
	}
}

int	cd(void)
{
	char	c[256];
	char	o[256];

	if (ft_strncmp(g_d.command_args[0], "cd", 2) == 0)
	{
		getcwd(o, sizeof(o));
		chdir(g_d.command_args[1]);
		getcwd(c, sizeof(c));
		ch_cwd(c, o);
		return (0);
	}
	return (1);
}