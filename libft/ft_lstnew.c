/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:41:10 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/12 14:27:59 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

t_env	*ft_lstnew(char *env, int i)
{
	t_env	*lst;

	lst = malloc(sizeof(t_env));
	if (!lst)
		return (NULL);
	lst->var = ft_substr(env, 0, i);
	lst->value = ft_substr(env, i + 1, ft_strlen(env) - i);
	lst->next = NULL;
	return (lst);
}

void	*ft_newdata(t_data	*data, char *cmd, int flag)
{
	int		i;

	i = 0;
	while ((data->cmd)[i])
		i++;
	(data->cmd)[i] = ft_strdup(cmd);
	(data->cmd)[i + 1] = 0;
	data->flag = flag;
}
