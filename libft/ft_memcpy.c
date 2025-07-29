/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmileshk <vmileshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:30:53 by thrychka          #+#    #+#             */
/*   Updated: 2025/07/02 11:36:34 by vmileshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*src_str;
	char			*dest_str;

	src_str = (char *)src;
	dest_str = (char *)dest;
	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		dest_str[i] = src_str[i];
		i++;
	}
	return (dest);
}
