/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:33:04 by rmc-coma          #+#    #+#             */
/*   Updated: 2015/12/03 14:07:46 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lstnext;

	while ((*alst) != NULL)
	{
		lstnext = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = lstnext;
	}
}
