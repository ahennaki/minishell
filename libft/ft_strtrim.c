/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:43:02 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/02 13:32:03 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	fi;
	size_t	li;

	if (!s1 || !set)
		return (NULL);
	fi = 0;
	while (s1[fi] && ft_strchr(set, s1[fi]))
		fi++;
	li = ft_strlen(s1) - 1;
	while (li > fi && ft_strchr(set, s1[li]))
		li--;
	return (ft_substr(s1, fi, (li - fi + 1)));
}
