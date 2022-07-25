/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <arowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:26:22 by alex              #+#    #+#             */
/*   Updated: 2022/07/25 16:21:28 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_d;

char	*check_key_cd(char *cmargs)
{
	int		i;

	i = 0;
	if (cmargs == NULL)
		return (NULL);
	while (g_d.env[i])
	{
		if (ft_strncmp(g_d.env[i], cmargs, ft_strlen(cmargs)) == 0)
			return (ft_strchr(g_d.env[i], '=') + 1);
		i++;
	}
	return (NULL);
}

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
		if (!g_d.command_args[1])
		{
			getcwd(o, sizeof(o));
			chdir(check_key_cd("HOME"));
			ch_cwd(check_key_cd("HOME"), o);
			return (0);
		}
		getcwd(o, sizeof(o));
		chdir(g_d.command_args[1]);
		getcwd(c, sizeof(c));
		ch_cwd(c, o);
		return (0);
	}
	return (1);
}
