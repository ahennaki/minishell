/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:41:10 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/16 07:12:58 by aennaki          ###   ########.fr       */
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

t_data	*ft_datanew(void)
{
	t_data	*lst;

	lst = malloc(sizeof(t_data));
	if (!lst)
		return (NULL);
	lst->cmd = NULL;
	lst->flag = 0;
	lst->next = NULL;
	return (lst);
}

void	ft_initdata(t_data *data, char *comd, int flag)
{
	int		i;

	i = 0;
	puts("dd");
	if (!data->cmd)
	{
		printf("l");
		(data->cmd)[0] = ft_strdup(comd);
		printf("l");
		(data->cmd)[1] = 0;
		return ;
	}
	printf("l");
	while (data->cmd[i])
		i++;
	data->cmd[i] = ft_strdup(comd);
	data->cmd[i + 1] = 0;
	data->flag = flag;
	data->next = NULL;
}
