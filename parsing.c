/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:44:39 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/12 16:53:01 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

void	handel_word(t_data *data, char *string, int *i)
{
	char	*str;
	int		j;

	j = *i;
	while (string[*i] && string[*i] != 32 && string[*i] != 34
		&& string[*i] != 39)
		*i++;
	str = ft_substr(string, j, *i - j);
	ft_newdata(data, str, -1);
}

bool	handel_quotes(t_data *data, char *str, int *i)
{
	int	j;

	if (str[*i] == 34)
	{
		j = check_quotes(data, str, *i, 34);
		if (j == -1)
			return (0);
		*i += j;
	}
	if (str[*i] == 39)
	{
		j = check_quotes(data, str, *i, 39);
		if (j == -1)
			return (0);
		*i += j;
	}
	if (str[*i] == 32)
	{
		ft_newdata(data, str, 32);
		while (str[*i] == 32)
			(*i)++;
	}
	return (1);
}

int	*split_cmd(char *str)
{
	t_data	*data;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 32 || str[i] == 39)
			if (!handel_quotes(data, str, &i))
				return (-1);
		else if (str[i] != 60 && str[i] != 62 && str[i] != 124)
			handel_word(data, str, &i);
		else if (str[i] == 124)
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
