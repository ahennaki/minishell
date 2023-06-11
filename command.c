/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:00:14 by aennaki           #+#    #+#             */
/*   Updated: 2023/05/19 18:54:43 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_command(char **arg)
{
	char	*str;
	int		i;
	int		c;

	i = 0;
	while (arg[++i])
		str = ft_strjoin(str, arg[i]);
	i = 1;
	c = 0;
	while (str[i])
	{
		if (str[i] == 92)
				i++;
		if ((str[i] == 34 || str[i] == 39) && str[i - 1] != 92)
			i++;
		printf("%c ", str[i]);
		i++;
	}
	printf("\n");
}

void	cd_command(char **arg)
{
	if (!arg[1])
		printf("cd: missing argument\n");
	else if (chdir(arg[1]) != 0)
		perror("cd");
}

void	pwd_command(void)
{
	char	*cwd;

	if (getcwd(cwd, sizeof(cwd)))
		printf("%s\n", cwd);
	else
		perror("pwd");
}
