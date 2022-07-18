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

void	ft_fill_envs(t_env *env, char **envn)
{
	int	i;

	i = 0;
	env = malloc(sizeof(t_env));
	if (!env)
		return ;
	env->envs = calloc(sizeof(char *), env_size(envn));
	while (envn[i])
	{
		env->envs[i] = ft_strdup(envn[i]);
		i++;
	}
}

void	print_envs(void)
{
	t_env		*e;
	int			i;

	i = 0;
	ft_fill_envs(&e, environ);
	while (e->envs && e->envs[i])
	{
		printf("%s\n", e->envs[i]);
		i++;
	}
}

need append func
	- Loop through exisiting t_env envs to get array size + 2
	1 for new string & null byte
	- Duplicate all members into new char **.
	- Add new string to last element in char **.
	- Free the old array.
	- Assign old array to point to new char **.
