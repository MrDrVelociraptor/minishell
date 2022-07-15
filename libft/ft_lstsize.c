/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 11:50:21 by nspeedy           #+#    #+#             */
/*   Updated: 2021/09/29 13:25:20 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_lstsize(t_list *lst)
{
	int	position;

	if (!lst)
		return (0);
	position = 0;
	while (lst != 0)
	{
		position++;
		lst = lst->next;
	}
	return (position);
}
