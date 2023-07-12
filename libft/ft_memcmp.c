/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:47:17 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/02 13:31:31 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < (n - 1)
		&& ((unsigned char *)ptr1)[i] == ((unsigned char *)ptr2)[i])
		i++;
	return (((unsigned char *)ptr1)[i] - ((unsigned char *)ptr2)[i]);
}
