/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:28:50 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/02 13:31:15 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

t_env	*ft_lstlast(t_env *lst)
{
	while (lst)
	{
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_env **lst, t_env *new)
{
	if (!*lst)
		*lst = new;
	else
		(ft_lstlast(*lst))->next = new;
}
