/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envvars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <arowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:21:36 by nspeedy           #+#    #+#             */
/*   Updated: 2022/07/25 16:05:28 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_d;

void	run_ex_un_env(char **cmargs)
{
	if (ft_strncmp(cmargs[0], "export", 6) == 0)
		exportal(cmargs);
	if (ft_strncmp(cmargs[0], "unset", 5) == 0)
		exportal(cmargs);
	
}

void	ch_var(char **cmargs)
{
	int		i;
	char	*tmp;

	i = 0;
	while (g_d.env && g_d.env[i])
		i++;
	i = 0;
	while (g_d.env && g_d.env[i])
	{
		tmp = ft_strchr(g_d.env[i], '=') + 1;
		if (ft_strncmp(g_d.env[i], cmargs[1], ft_strlen(g_d.env[i]) - ft_strlen(tmp)) == 0)
			g_d.env[i] = ft_strdup(cmargs[1]);
		i++;
	}
}

void	add_var(char **cmargs)
{
	int		i;
	int 	j;
	char	**tmp;

	i = 0;
	while (g_d.env && g_d.env[i])
		i++;
	j = i + 2;
	tmp = malloc(sizeof(t_env) * j);
	i = 0;
	while (g_d.env && g_d.env[i])
	{
		tmp[i] = ft_strdup(g_d.env[i]);
		i++;
	}
	tmp[i] = ft_strdup(cmargs[1]);
	free(g_d.env);
	tmp[i + 1] = NULL;
	g_d.env = tmp;
}

void	rm_var(char **cmargs)
{
	int		i;
	int		j;
	bool	isgone;
	char	**new;

	i = 0;
	while (g_d.env[i])
		i++;
	new = (char **)malloc(sizeof(char *) * i);
	i = 0;
	j = i + 1;
	isgone = false;
	while (g_d.env && g_d.env[j])
	{
		if (ft_strncmp(g_d.env[i], cmargs[1], ft_strlen(cmargs[1])) == 0 || isgone)
		{
			new[i] = ft_strdup(g_d.env[j]);
			isgone = true;
		}
		else
			new[i] = ft_strdup(g_d.env[i]);
		i++;
		j++;
	}
	new[i] = NULL;
	g_d.env = new;
}

void	exportal(char **cmargs)
{
	if (ft_strncmp("export", cmargs[0], 6) == 0 && cmargs[1])
	{
		if (check_key(cmargs[1]) == false)
			add_var(cmargs);
		else if (check_key(cmargs[1]) == true)
			ch_var(cmargs);
	}
	else if (ft_strncmp("unset", cmargs[0], 5) == 0 && cmargs[1])
	{
		if (check_key_un(cmargs[1]) == true)
			rm_var(cmargs);
	}
	else if (ft_strncmp("export", cmargs[0], 6) == 0 && !cmargs[1]) 
		print_envs();
}

