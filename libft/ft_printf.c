/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:00:45 by nspeedy           #+#    #+#             */
/*   Updated: 2022/01/05 14:32:35 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_args	*ft_argz(void)
{
	t_args	*arg;

	arg = (t_args *)malloc(sizeof(t_args));
	if (arg == NULL)
		return (NULL);
	arg->counter = 0;
	return (arg);
}

static int	ft_flagcheck(const char c, t_args *arg)
{
	if (c == 'c')
		ft_char(arg);
	else if (c == 's')
		ft_string(arg);
	else if (c == 'p')
		ft_pointer(arg);
	else if (c == 'd' || c == 'i')
		ft_int(arg);
	else if (c == 'u')
		ft_unsigned(arg);
	else if (c == 'x' || c == 'X')
		ft_hex(arg, c);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		arg->counter++;
	}
	else
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	t_args		*arg;
	int			i;
	int			count;

	i = 0;
	count = 0;
	arg = ft_argz();
	va_start(arg->args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			i += ft_flagcheck(str[i + 1], arg);
		else
		{
			ft_putchar_fd(str[i], 1);
			arg->counter++;
		}
		i++;
	}
	count = arg->counter;
	va_end(arg->args);
	free(arg);
	return (count);
}
