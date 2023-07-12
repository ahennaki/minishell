/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:34:56 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/02 13:32:55 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*search_env(char *str, t_env *env)
{
	while (env)
	{
		if (!ft_memcmp(str, env->var, ft_strlen(str)))
			return (env->value);
		env = env->next;
	}
	return (0);
}

void	change_env(char *pwd, char *oldpwd, t_env **env)
{
	if (!pwd || !oldpwd || !env || !*env)
		return ;
	while (*env)
	{
		if (!ft_memcmp("PWD", (*env)->var, 3))
			(*env)->value = pwd;
		if (!ft_memcmp("OLDPWD", (*env)->var, 6))
			(*env)->value = oldpwd;
		*env = (*env)->next;
	}
}
