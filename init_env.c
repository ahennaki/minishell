/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 01:23:27 by aennaki           #+#    #+#             */
/*   Updated: 2023/06/11 03:11:47 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(char **env)
{
	t_env	*envir;
	size_t	i;

	if (!env || !*env)
		return ;
	envir = NULL;
	while (*env)
	{
		i = strichr(*env, '=');
		ft_lstadd_back(&envir, ft_lstnew(ft_substr(*env, 0, i),
				ft_substr(*env, i + 1, ft_strlen(*env) - i)));
	}
}
