/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:45:19 by nspeedy           #+#    #+#             */
/*   Updated: 2022/01/05 14:31:47 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_ptrlen(unsigned long n, int *len)
{
	char	*str;

	while (n > 15)
	{
		n = n / 16;
		*len += 1;
	}
	str = (char *)malloc((*len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[*len] = '\0';
	return (str);
}

void	ft_pointer(t_args *arg)
{
	int				len;
	char			*str;
	unsigned long	n;

	n = va_arg(arg->args, unsigned long);
	len = 1;
	str = ft_ptrlen(n, &len);
	ft_putstr_fd("0x", 1);
	arg->counter += 2;
	len--;
	while (len >= 0)
	{
		if (n % 16 < 10)
			str[len] = '0' + (n % 16);
		else
			str[len] = 'a' + (n % 16) - 10;
		n = n / 16;
		len--;
		arg->counter++;
	}
	ft_putstr_fd(str, 1);
	free(str);
}

void	ft_hex(t_args *arg, char c)
{
	unsigned int	n;
	int				len;
	char			*str;

	n = va_arg(arg->args, unsigned int);
	len = 1;
	str = ft_ptrlen(n, &len);
	len--;
	while (len >= 0)
	{
		if (n % 16 < 10)
			str[len] = '0' + (n % 16);
		else if (c == 'x')
			str[len] = 'a' + (n % 16) - 10;
		else
			str[len] = 'A' + (n % 16) - 10;
		n = n / 16;
		len--;
		arg->counter++;
	}
	ft_putstr_fd(str, 1);
	free(str);
}
