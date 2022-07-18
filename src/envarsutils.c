/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envarsutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <nspeedy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:21:36 by nspeedy           #+#    #+#             */
/*   Updated: 2022/07/18 17:20:46 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_d;

char	**env_keys(char **environ)
{
	int		i;
	int		j;
	char	*t;
	char	**keys;

	i = 0;
	j = 0;
	while (environ[i])
		i++;
	keys = ft_calloc(sizeof(char *), i + 1);
	while (environ[j])
	{
		t = ft_strchr(environ[j], '=') + 1;
		keys[j] = ft_substr(environ[j], 0,
				ft_strlen(environ[j]) - ft_strlen(t));
		//printf("keys[j] ==== %s\n", keys[j]);
		
		j++;
	}
	keys[j] = NULL;
	return (keys);
}

bool	check_key(char **cmargs)
{
	int		i;
	char	*c;
	char	*tmp;
	char	**keys;

	i = 0;
	c = ft_strchr(cmargs[1], '=') + 1;
	tmp = ft_substr(cmargs[1], 0, ft_strlen(cmargs[1]) - ft_strlen(c));
	keys = env_keys(environ);
	while (keys[i])
	{
		if (ft_strncmp(keys[i], tmp, ft_strlen(keys[i])) == 0)
			return (true);
		i++;
	}
	return (false);
}
