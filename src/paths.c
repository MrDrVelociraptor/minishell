/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:50:59 by nspeedy           #+#    #+#             */
/*   Updated: 2022/07/26 09:18:38 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_d;

bool	is_builtin(void)
{
	return (ft_strncmp(g_d.command_args[0], "export", 6)
		&& ft_strncmp(g_d.command_args[0], "unset", 5)
		&& ft_strncmp(g_d.command_args[0], "cd", 2)
		&& ft_strncmp(g_d.command_args[0], "env", 3));
}

char	*check_access(char **paths, char *cmd[])
{
	int		i;
	char	*temp;
	char	*path;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, cmd[0]);
		free(temp);
		if (access(path, X_OK) == 0)
		{
			free_strarray(paths);
			return (path);
		}
		free(path);
		i++;
	}
	if (paths)
		free_strarray(paths);
	return (NULL);
}

char	*find_path(char *cmd[])
{
	int		i;
	char	**paths;

	i = 0;
	paths = NULL;
	while (g_d.env[i])
	{
		if (ft_strncmp("PATH=", g_d.env[i], 5) == 0)
		{
			paths = ft_split(g_d.env[i] + 5, ':');
			break ;
		}
		i++;
	}
	return (check_access(paths, cmd));
}
