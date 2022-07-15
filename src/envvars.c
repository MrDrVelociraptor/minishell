/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envvars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <nspeedy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:21:36 by nspeedy           #+#    #+#             */
/*   Updated: 2022/07/15 16:07:59 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_d;

bool	over_write(char **cmargs)
{
	int		i;
	char	*tmp;

	i = 0;
	if (ft_strncmp("export", cmargs[0], 6) == 0 && cmargs[1])
	{
		if (check_key(cmargs[1]) == true)
		{
			while (environ[i])
			{
				tmp = ft_strchr(environ[i], '=') + 1;
				if (ft_strncmp(environ[i], cmargs[1],
						ft_strlen(environ[i]) - ft_strlen(tmp)) == 0)
				{
					ft_calloc(sizeof(char *), ft_strlen(environ[i]));
					environ[i] = ft_strdup(cmargs[1]);
				}
				i++;
			}
			execve("export", g_d.command_args, environ);
			return (true);
		}
	}
	return (false);
}

bool	new_env(char **cmargs)
{
	int		i;

	i = 0;
	if (ft_strncmp("export", cmargs[0], 6) == 0 && cmargs[1])
	{
		if (check_key(cmargs[1]) == false)
		{
			while (environ[i])
				i++;
			if (it_strchr(cmargs[1], '=') == 1)
			{
				environ[i] = ft_calloc(sizeof(char *), ft_strlen(cmargs[1]));
				environ[i] = ft_strdup(cmargs[1]);
			}
		}
		//execve("export", g_d.command_args, environ);
		return (true);
    }
    return (false);
}

bool	print_env(char **cmargs)
{
	int		i;
	char	*t;
	char	*x;

	i = 0;
	if (ft_strncmp("export", cmargs[0], 6) == 0 && !cmargs[1])
	{
		while (environ[i])
		{
			t = ft_strchr(environ[i], '=') + 1;
			x = ft_substr(environ[i], 0, ft_strlen(environ[i]) - ft_strlen(t));
			ft_printf("%s%s\n", x, t);
			i++;
		}
		return (true);
	}
	return (false);
}

bool	exportal(char **cmargs)
{
	if (print_env(cmargs))
		return (true);
	if (over_write(cmargs))
		return (true);
	if (new_env(cmargs))
		return (true);
	return (false);
}
