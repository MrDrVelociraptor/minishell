/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:35:37 by nspeedy           #+#    #+#             */
/*   Updated: 2021/09/29 10:21:12 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	strlen;

	strlen = ft_strlen(s);
	while (strlen != 0 && *(s + strlen) != c)
		strlen--;
	if (*(s + strlen) == c)
		return ((char *)(s + strlen));
	return (0);
}
