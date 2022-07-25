/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <nspeedy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:51:11 by nspeedy           #+#    #+#             */
/*   Updated: 2022/07/25 17:02:16 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_d;

int	strarrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_strarray(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	exsit(char *cmdline, char **arglist)
{
	int	exit_code;

	if (ft_strncmp("exit", cmdline, 4) == 0)
	{
		if (ft_strncmp("exit", cmdline, ft_strlen(cmdline)) == 0)
			exit(0);
		arglist = ft_split(cmdline, ' ');
		exit_code = ft_atoi(arglist[1]);
		exit(exit_code);
	}
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
