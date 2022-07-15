/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ints.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:14:49 by nspeedy           #+#    #+#             */
/*   Updated: 2022/01/05 14:32:16 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnums(unsigned int n, t_args *arg)
{
	if (n >= 10)
	{
		ft_putnums(n / 10, arg);
		arg->counter += 1;
	}
	ft_putchar_fd((n % 10) + '0', 1);
}

void	ft_int(t_args *arg)
{
	unsigned int	i;
	int				n;

	n = va_arg(arg->args, int);
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		arg->counter++;
		i = -n;
	}
	else
		i = n;
	ft_putnums(i, arg);
	arg->counter++;
}

void	ft_unsigned(t_args *arg)
{
	unsigned int	n;

	n = va_arg(arg->args, unsigned int);
	ft_putnums(n, arg);
	arg->counter++;
}
