/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:56:59 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/16 06:17:13 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*command;
	t_env	envir;
	t_data	*data = NULL;
	// int		fd_out;
	// int		fd_in;
	int		i = -1;

	if (ac && !*av)
		init_env(env, &envir);
	while (1)
	{
		command = readline("minishell> ");
		if (!command)
			break ;
		data = parsing(command);
		while (data)
		{
			while (data->cmd[++i])
				printf("- %s\n", data->cmd[i]);
			printf("f %d\n", data->flag);
			data = data->next;
		}
		add_history(command);
		free(command);
	}
	return (0);
}
