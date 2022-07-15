/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:30:10 by nspeedy           #+#    #+#             */
/*   Updated: 2021/09/29 10:23:03 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*position;

	position = dest;
	while (len > 0)
	{
		len--;
		*position++ = c;
	}
	return (dest);
}
