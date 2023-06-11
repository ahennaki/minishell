/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:56:59 by aennaki           #+#    #+#             */
/*   Updated: 2023/06/11 00:39:47 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*command;
	int		fd_in;
	int		fd_out;

	while (1)
	{
		command = readline("minishell> ");
		if (!command)
			break ;
		add_history(command);
		free(command);
	}
	return (0);
}
