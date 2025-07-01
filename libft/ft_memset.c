/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrychka <thrychka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:35:28 by thrychka          #+#    #+#             */
/*   Updated: 2024/07/08 19:54:15 by thrychka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}
// int main () {
//    const char src[50] = "aaa";
//    char dest[50];
//    strcpy(dest,"");
//    printf("Before memcpy dest = %s\n", dest);
//    ft_memset(dest, src, 2);
//    printf("After memcpy dest = %s\n", dest);
//    return(0);
// }