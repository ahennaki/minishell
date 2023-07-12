/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:06:43 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/02 13:31:35 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	nbr_word(char const *s, char c)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			nbr++;
		if (s[i] == c && (s[i + 1] != c && s[i + 1]))
			nbr++;
		i++;
	}
	return (nbr);
}

static int	wd_strlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**free_dest(char **dest, int i)
{
	while (i >= 0)
	{
		free(dest[i]);
		i--;
	}
	free(dest);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		j;
	int		lw;

	if (!s)
		return (NULL);
	dest = (char **) malloc((nbr_word(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < nbr_word(s, c))
	{
		while (s[j] == c)
			j++;
		lw = wd_strlen(s + j, c);
		dest[i] = ft_substr(s, j, lw);
		if (!dest[i])
			return (free_dest(dest, i));
		j += lw;
	}
	dest[i] = NULL;
	return (dest);
}

// int	main(void)
// {
// 	char	**str;
// 	int		i;

// 	i = 0;
// 	str = ft_split("   ", ' ');
// 	puts("a");
// 	while (str[i])
// 		printf("#%s#\n", str[i++]);
// 	return (0);
// }