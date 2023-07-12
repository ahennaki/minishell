/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:19:29 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/02 13:31:48 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = -1;
	while (++i < n)
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return ((char *) s1);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = malloc(i + j + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, i);
	ft_memcpy(str + i, s2, j);
	str[i + j] = '\0';
	return (str);
}
