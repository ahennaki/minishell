/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:44:21 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/04 13:35:27 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

t_token	init_token(char c1, char c2)
{
	if (!c1)
		return (END);
	if (c1 == '<' && c2 == '<')
		return (HDC);
	if (c1 == '>' && c2 == '>')
		return (APD);
	if (c1 == '|')
		return (PIPE);
	if (c1 == '<')
		return (IN);
	if (c1 == '>')
		return (OUT);
	return (NONE);
}

bool	check_token(char *str, size_t j)
{
	t_token	tok;
	size_t	i;

	i = j;
	while (str[i])
	{
		tok = init_token(str[i], str[i + 1]);
		
	}
}
