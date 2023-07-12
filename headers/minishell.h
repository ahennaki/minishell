/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:54:58 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/12 12:11:40 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

typedef enum e_token
{
	NONE,
	HDC,
	APD,
	PIPE,
	IN,
	OUT,
	END
}	t_token;

// void	echo_command(char **arg);
// void	cd_command(char **arg);
// void	pwd_command(void);
void	init_env(char **env, t_env	*envir);

// builtins
char	*search_env(char *str, t_env *env);
void	change_env(char *pwd, char *oldpwd, t_env **env);

#endif