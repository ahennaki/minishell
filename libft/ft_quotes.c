/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:30:19 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/16 05:54:56 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	check_quotes(t_data *data, char *str, int i, int c)
{
	char	*string;
	int		j;

	j = i;
	if (c == 39)
		while (str[i] && str[i] != 39)
			i++;
	if (c == 34)
		while (str[i] && str[i] != 34)
			i++;
	if (!str[i])
	{
		printf("Syntax error: check quotes!\n");
		return (-1);
	}
	string = ft_substr(str, j, i - j);
	ft_initdata(data, string, c);
	return (i);
}
