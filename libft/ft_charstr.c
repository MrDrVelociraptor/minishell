/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:35:29 by nspeedy           #+#    #+#             */
/*   Updated: 2022/01/05 14:31:28 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_char(t_args *arg)
{
	ft_putchar_fd(va_arg(arg->args, int), 1);
	arg->counter++;
}

void	ft_string(t_args *arg)
{
	char	*str;
	int		len;

	str = va_arg(arg->args, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		arg->counter += 6;
	}
	else
	{
		len = ft_strlen(str);
		ft_putstr_fd(str, 1);
		arg->counter += len;
	}
}
