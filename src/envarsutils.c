/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envarsutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:21:36 by nspeedy           #+#    #+#             */
/*   Updated: 2022/07/19 16:49:55 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_d;

int	env_size(char **environ)
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

char	**env_keys(void)
{
	int		i;
	int		j;
	char	*t;
	char	**keys;

	i = 0;
	j = 0;
	while (g_d.env[i])
		i++;
	keys = ft_calloc(sizeof(char *), i + 1);
	while (g_d.env && g_d.env[j])
	{
		t = ft_strchr(g_d.env[j], '=') + 1;
		keys[j] = ft_substr(g_d.env[j], 0,
				ft_strlen(g_d.env[j]) - ft_strlen(t));
		j++;
	}
	keys[j] = NULL;
	return (keys);
}

bool	check_key(char *cmargs)
{
	int		i;
	char	*c;
	char	*tmp;
	char	**keys;

	i = 0;
	if (cmargs == NULL)
		return (true);
	c = ft_strchr(cmargs, '=') + 1;
	tmp = ft_substr(cmargs, 0, ft_strlen(cmargs) - ft_strlen(c));
	keys = env_keys();
	while (keys[i])
	{
		if (ft_strncmp(keys[i], tmp, ft_strlen(keys[i])) == 0)
		{
			return (true);
		}
		i++;
	}
	return (false);
}

bool	check_key_un(char *cmargs)
{
	int		i;
	char	**keys;

	i = 0;
	if (cmargs == NULL)
		return (true);
	keys = env_keys();
	while (keys[i])
	{
		if (ft_strncmp(keys[i], cmargs, ft_strlen(cmargs)) == 0)
			return (true);
		i++;
	}
	return (false);
}
