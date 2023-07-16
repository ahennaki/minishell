/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:09:14 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/16 06:59:33 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_data
{
	char				**cmd;
	int					flag;
	struct s_data		*next;
}						t_data;

t_data	*ft_datanew(void);

int		ft_memcmp(const void *str1, const void *str2, size_t n);
int		check_quotes(t_data *data, char *str, int i, int c);
int		ft_atoi(const char *str);

size_t	ft_strichr(const char *str, char c);
size_t	ft_strlen(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *str);
char	*ft_itoa(int n);

void	ft_add_data(t_data **data, t_data *new);
void	ft_initdata(t_data	*data, char *cmd, int flag);
void	*ft_calloc(size_t n, size_t size);

bool	is_wspace(char c);

typedef struct s_env
{
	char			*var;
	char			*value;
	struct s_env	*next;
}					t_env;

t_env	*ft_lstnew(char *env, int i);

void	ft_lstadd_front(t_env **lst, t_env *new);
void	ft_lstadd_back(t_env **lst, t_env *new);

int		ft_lstsize(t_env *lst);

#endif
