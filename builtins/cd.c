/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 01:29:54 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/02 13:32:48 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	cd_command(t_env **env, char **str)
{
	char	*pwd;
	char	*oldpwd;

	pwd = search_env("PWD", *env);
	oldpwd = search_env("OLDPWD", *env);
	if (!ft_memcmp(str[1], "-", ft_strlen(str[1])))
	{
		if (chdir(oldpwd))
			perror("chdir() to /dir failed");
		change_env(oldpwd, pwd, env);
		printf("%s\n", oldpwd);
	}
	if (chdir(str[1]))
		perror("chdir() to /dir failed");
	change_env(str[1], pwd, env);
}
