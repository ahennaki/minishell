/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 07:23:00 by aennaki           #+#    #+#             */
/*   Updated: 2023/07/20 07:28:53 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	int	i;

	i = 0;
	while (len--)
		((unsigned char *)ptr)[i++] = (unsigned char)c;
	return (ptr);
}
