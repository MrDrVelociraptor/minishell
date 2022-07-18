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
	printf("here\n");

	// printf("here\n");
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

void	add_var(char **cmargs)
{
	int		i;
	int 	j;
	char	**tmp;

	i = 0;
	while (g_d.env && g_d.env[i])
		i++;
	printf("i up top %d\n", i);

	j = i + 1;
	tmp = malloc(sizeof(t_env) * j);
	i = 0;
	while (g_d.env && g_d.env[i])
	{
		printf("i ==== %d\n", i);
		tmp[i] = ft_strdup(g_d.env[i]);
		i++;
	}
	printf("********** %d\n", j);

	tmp[i] = ft_strdup(cmargs[1]);
	printf("cmargs === %s\n", tmp[i]);
	free(g_d.env);
	tmp[i + 1] = '\0';
	g_d.env = tmp;
}

bool	exportal(char **cmargs)
{
	if (ft_strncmp("export", cmargs[0], 6) == 0 && check_key(cmargs[1]) == false)
	{
		printf("hello\n");
		printf("here *** %d\n", check_key(cmargs[1]));
	

			printf("now here\n");
			add_var(cmargs);
			
			return (true);


	}
	else 
		print_envs();
	return (false);
}

// need append func
// 	- Loop through exisiting t_env envs to get array size + 2
// 	1 for new string & null byte
// 	- Duplicate all members into new char **.
// 	- Add new string to last element in char **.
// 	- Free the old array.
// 	- Assign old array to point to new char **.
