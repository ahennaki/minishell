/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:41:10 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/20 07:13:27 by aennaki          ###   ########.fr       */
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

t_data	*ft_datanew(char *cmd, t_token tok)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->cmd = cmd;
	data->tok = tok;
	data->next = NULL;
	return (data);
}

// void	ft_initdata(t_data *data, char *comd, int flag)
// {
// 	int		i;

// 	i = 0;
// 	puts("dd");
// 	*(data->cmd) = ft_strdup("");
// 	if (!(data->cmd))
// 	{
// 		printf("l");
// 		*(data->cmd) = ft_strdup(comd);
// 		printf("l");
// 		*(data->cmd) = 0;
// 		return ;
// 	}
// 	printf("l");
// 	while (data->cmd)
// 		i++;
// 	// data->cmd = ft_strdup(comd);
// 	// data->cmd = 0;
// 	data->flag = flag;
// 	data->next = NULL;
// }
