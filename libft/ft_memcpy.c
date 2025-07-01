/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrychka <thrychka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:30:53 by thrychka          #+#    #+#             */
/*   Updated: 2024/07/08 19:46:31 by thrychka         ###   ########.fr       */
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

// int main () {
//    const char src[50] = "";
//    char dest[50];
//    strcpy(dest,"a");
//    printf("Before memcpy dest = %s\n", dest);
//    ft_memcpy(dest, src, 2);
//    printf("After memcpy dest = %s\n", dest);
//    return(0);
// }
