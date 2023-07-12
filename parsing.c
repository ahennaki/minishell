/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:44:39 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/12 15:19:12 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

int	tst(t_data *data, char *str, int i)
{
	
	if (str[i] == 34)
	{
		i = check_quotes(data, str, i, 34);
		if (i = -1)
			return (-1);
	}
}

t_data	*split_cmd(char *str)
{
	t_data	*data;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 60 && str[i] != 62 && str[i] != 124)
			
	}
}

t_data	*parsing(char *command)
{
	t_data	*data;
	char	*str;

	str = ft_strtrim(command, " \t\n\v\f\r");
	if (!str)
		return (0);
}
