/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envvars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <nspeedy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:21:36 by nspeedy           #+#    #+#             */
/*   Updated: 2022/07/18 18:12:47 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_d;

int			env_size(char **environ)
{
	int	i;

	i = 0;
	while (environ[i])
		i++;
	return (i);
}


char 	**ft_fill_envs(void)
{
	int	i;
	int	j;
	char **env;

	i = 0;
	j = env_size(environ);
	env = (char **)calloc(sizeof(char *), j);
	while (environ[i])
	{
		env[i] = ft_strdup(environ[i]);
		i++;
	}
	env[i + 1] = NULL;
	return (env);
}

void	print_envs(void)
{
	int			i;

	i = 0;
	while (g_d.env && g_d.env[i])
	{
		printf("%s\n", g_d.env[i]);
		i++;
	}
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
	j = i + 1;
	tmp = malloc(sizeof(t_env) * j);
	i = 0;
	while (g_d.env && g_d.env[i])
	{
		tmp[i] = ft_strdup(g_d.env[i]);
		i++;
	}
	tmp[i] = ft_strdup(cmargs[1]);
	free(g_d.env);
	tmp[i + 1] = '\0';
	g_d.env = tmp;
}

void	exportal(char **cmargs)
{
	if (ft_strncmp("export", cmargs[0], 6) == 0 && cmargs[1])
	{
		if (check_key(cmargs[1]) == false)
			add_var(cmargs);
	}
	if (ft_strncmp("export", cmargs[0], 6) == 0 && cmargs[1])
	{
		if (check_key(cmargs[1]) == true)
			ch_var(cmargs);
	}
	else 
		print_envs();
}

