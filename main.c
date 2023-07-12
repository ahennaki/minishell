/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:56:59 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/03 12:14:09 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*command;
	t_env	envir;
	t_data	*data;
	int		fd_out;
	int		fd_in;

	init_env(env, &envir);
	while (1)
	{
		command = readline("minishell> ");
		if (!command)
			break ;
		data = parsing(command);
		add_history(command);
		free(command);
	}
	return (0);
}
