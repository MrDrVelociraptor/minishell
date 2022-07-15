/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:34:41 by nspeedy           #+#    #+#             */
/*   Updated: 2021/09/29 10:26:43 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destp;
	const unsigned char	*srcp;

	if (dest > src)
	{
		destp = dest + n;
		srcp = src + n;
		while (n > 0)
		{
			n--;
			*--destp = *--srcp;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
