/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:44:21 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/22 01:57:44 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

bool	is_token(t_token tok)
{
	return (tok == HERDOC || tok == APPEND || tok == IN
		|| tok == OUT || tok == D_QUOTES || tok == S_QUOTES
		|| tok == SPACE);
}

// bool	check_token(char *str, size_t j)
// {
// 	t_token	tok;
// 	size_t	i;

// 	i = j;
// 	while (str[i])
// 	{
// 		tok = init_token(str[i], str[i + 1]);
// 	}
// }
