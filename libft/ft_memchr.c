/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrychka <thrychka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:34:46 by thrychka          #+#    #+#             */
/*   Updated: 2024/07/08 19:51:12 by thrychka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

// #include "libft.h"

// void	*ft_memchr(const void *ptr, int value, size_t num)
// {
// 	size_t			i;
// 	unsigned char	*p;

// 	i = 0;
// 	p = (unsigned char *)ptr;
// 	while (i < num)
// 	{
// 		if (p[i] == (unsigned char)value)
// 			return ((void *)(p + i));
// 		i++;
// 	}
// 	return (NULL);
// }

// int main() {
//     unsigned char data[] = { 0x01, 0x02, 0x03, 0x04, 0x05 };
//     int value = 0x03;
//     size_t num = 5;
//     void *result = ft_memchr(data, value, num);
//     if (result != NULL) {
//         printf("Value found at address: %p\n", result);
//         printf("Offset in array: %ld\n", (unsigned char*)result - data);
//     } else {
//         printf("Value not found\n");
//     }
//     return 0;
// }