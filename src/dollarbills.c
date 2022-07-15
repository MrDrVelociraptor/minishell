/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollarbills.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <nspeedy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:04:01 by nspeedy           #+#    #+#             */
/*   Updated: 2022/07/15 13:23:16 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_data	g_d;

t_dollar    *find(char *n_args, t_dollar *d)
{
    d->found = d->i - 1;
    d->find = d->i;
    if (n_args[d->i] == '?')
        ft_printf("%d\n", g_d.statval);
    else
    {
        while (n_args[d->i] != '$' && n_args[d->i] != ' ' && n_args[d->i] != '\0')
        { 
            d->found++;
            d->i++;
        }
        d->prev = ft_substr(n_args, 0, d->find - 1);
        d->tmp = ft_substr(n_args, d->find, d->found - d->find);
        d->str = ft_substr(n_args, d->found + 1, ft_strlen(n_args));
    }
    return (d);
}

char	*dollar_bils(char *n_args)
{
    t_dollar    d;
    
    memset(&d, 0, sizeof(t_dollar));   
    while (n_args[d.i] != '\0')  
    {   
        if (n_args[d.i++] == '$')
        {
            find(n_args, &d);
            while (environ[d.envi])
            {
                if (ft_strncmp(d.tmp, environ[d.envi], ft_strlen(d.tmp)) == 0)
                {
                    d.tmp = ft_strchr(environ[d.envi], '=') + 1;
                    n_args = ft_strjoin(d.prev, d.tmp);
                    n_args = ft_strjoin(n_args, d.str);
                    d.i = 0;
                    d.envi = 0;
                    break ;
                }
                d.envi++;
            }
        }
        d.find = 0;
    }   
    return (n_args);
}
