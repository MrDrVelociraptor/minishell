/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:58:46 by nspeedy           #+#    #+#             */
/*   Updated: 2021/09/29 10:14:48 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	ft_numnum(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*result;
	size_t			len;
	unsigned int	nbr;

	nbr = (unsigned int)n;
	len = ft_numnum(n);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (0);
	if (n < 0)
	{
		result[0] = '-';
		nbr *= -1;
	}
	if (nbr == 0)
		result[0] = '0';
	result[len--] = '\0';
	while (nbr)
	{
		result[len] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	return (result);
}
