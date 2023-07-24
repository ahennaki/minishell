/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:44:39 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/24 23:44:20 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

void	handel_word(t_data *data, char *string, size_t *i)
{
	char	*str;
	int		j;

	j = *i;
	while (string[*i] && string[*i] != 32 && string[*i] != 34
		&& string[*i] != 39 && string[*i] != 124
		&& string[*i] != 60 && string[*i] != 62 && string[*i] != 59)
		(*i)++;
	str = ft_substr(string, j, *i - j);
	ft_add_data(&data, ft_datanew(str, NONE));
}

bool	handel_quotes(t_data *data, char *str, size_t *i)
{
	int	j;

	if (str[*i] == 34)
	{
		j = check_quotes(data, str, *i + 1, 34);
		if (j == -1)
			return (0);
		*i += j;
	}
	if (str[*i] == 39)
	{
		j = check_quotes(data, str, *i + 1, 39);
		if (j == -1)
			return (0);
		*i += j;
	}
	if (is_wspace(str[*i]))
	{
		ft_add_data(&data, ft_datanew(" ", SPACE));
		while (is_wspace(str[*i]))
			(*i)++;
	}
	return (1);
}

void	handel_redir(t_data *data, char *str, size_t *i)
{
	if (str[*i] == 60)
	{
		if (str[*i + 1] == 60)
		{
			ft_add_data(&data, ft_datanew(ft_substr(str, *i, 2), HERDOC));
			(*i)++;
		}
		else
			ft_add_data(&data, ft_datanew(ft_substr(str, *i, 1), IN));
		(*i)++;
	}
	if (str[*i] == 62)
	{
		if (str[*i + 1] == 62)
		{
			ft_add_data(&data, ft_datanew(ft_substr(str, *i, 2), APPEND));
			(*i)++;
		}
		else
			ft_add_data(&data, ft_datanew(ft_substr(str, *i, 1), OUT));
		(*i)++;
	}
}

void	init_data(t_data *data, char *str, size_t i)
{
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39 || is_wspace(str[i]))
		{	
			if (!handel_quotes(data, str, &i))
				break ;
		}
		else if (str[i] == 60 || str[i] == 62)
			handel_redir(data, str, &i);
		else if (str[i] == 124)
		{
			ft_add_data(&data, ft_datanew(ft_substr(str, i, 1), PIPE));
			i++;
		}
		else if (str[i] == 59)
		{
			ft_add_data(&data, ft_datanew(ft_substr(str, i, 1), END));
			i++;
		}
		else
			handel_word(data, str, &i);
	}
}

t_data	*lexer(char *command)
{
	t_data	*data;
	char	*str;

	str = ft_strtrim(command, " \t\n\v\f\r");
	if (!str)
		return (0);
	data = ft_datanew("", 0);
	init_data(data, str, 0);
	return (data);
}
