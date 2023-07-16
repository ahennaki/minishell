/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:44:39 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/16 06:52:02 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

void	handel_word(t_data *data, char *string, size_t *i)
{
	char	*str;
	int		j;

	j = *i;
	while (string[*i] && string[*i] != 32 && string[*i] != 34
		&& string[*i] != 39)
		(*i)++;
	puts("f");
	str = ft_substr(string, j, *i - j);
	puts("f");
	ft_initdata(data, str, -1);
	puts("f");
}

bool	handel_quotes(t_data *data, char *str, size_t *i)
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
		ft_initdata(data, str, 32);
		while (str[*i] == 32)
			(*i)++;
	}
	return (1);
}

// void	handel_redir(t_data *data, char *str, int *i)
// {
// 	if (str[*i] == 60)
// 	{
// 		if (str[*i + 1] == 60)
// 		{
// 			ft_add_data(&data, ft)
// 		}
// 	}
// }

t_data	*split_cmd(t_data *data, char *str, size_t i)
{
	t_data	*head;

	data = ft_datanew();
	head = data;
	while (str[i])
	{
		puts("a");
		if (str[i] == 34 || str[i] == 32 || str[i] == 39)
		{	
		puts("b");
			if (!handel_quotes(data, str, &i))
				return (NULL);
		puts("c");
		}
		else if (str[i] != 60 && str[i] != 62 && str[i] != 124)
			handel_word(data, str, &i);
		else if (str[i] == 124)
		{
			ft_add_data(&data, ft_datanew());
			data = data->next;
			i++;
		}
		puts("d");
		// else
		// 	handel_redir()
	}
	return (head);
}

t_data	*parsing(char *command)
{
	t_data	*data;
	char	*str;

	str = ft_strtrim(command, " \t\n\v\f\r");
	if (!str)
		return (0);
	data = NULL;
	data = split_cmd(data, str, 0);
	return (data);
}
