/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:13:59 by nspeedy           #+#    #+#             */
/*   Updated: 2022/02/26 11:49:34 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	track;
	size_t	length;

	track = 0;
	while (src[track] != '\0')
		track++;
	length = track;
	if (size == 0)
		return (length);
	track = 0;
	while (src[track] && track < (size - 1))
	{
		dest[track] = src[track];
		track++;
	}
	dest[track] = '\0';
	return (length);
}
