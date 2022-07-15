/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:22:04 by nspeedy           #+#    #+#             */
/*   Updated: 2021/09/29 10:52:39 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*scpy;

	len = ft_strlen(s);
	scpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!scpy)
		return (0);
	len = 0;
	while (s[len])
	{
		scpy[len] = s[len];
		len++;
	}
	scpy[len] = '\0';
	return (scpy);
}
