/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrychka <thrychka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:42:58 by thrychka          #+#    #+#             */
/*   Updated: 2024/07/11 16:15:06 by thrychka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
// #include "ft_strlcpy.c"
// #include "ft_strlen.c"

int	get_num_length(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*return_min_int(int n)
{
	char	*mn;

	mn = malloc(12 * sizeof(char));
	if (mn == NULL)
		return (NULL);
	ft_strlcpy(mn, "-2147483648", get_num_length(n) + 1);
	return (mn);
}

void	to_str(char *ptr, int len, int n)
{
	while (n != 0)
	{
		ptr[--len] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		length;
	char	*ptr;

	length = get_num_length(n);
	if (n == -2147483648)
	{
		ptr = return_min_int(n);
		return (ptr);
	}
	ptr = malloc(length + 1);
	if (!ptr)
		return (NULL);
	ptr[length] = '\0';
	if (n == 0)
		ptr[0] = '0';
	if (n < 0)
	{
		ptr[0] = '-';
		n = -n;
	}
	to_str(ptr, length, n);
	return (ptr);
}

// // Driver program to test implementation of itoa()
// int main()
// {
//     printf("Number: %d\nBase: %d\tConverted String: %s\n",
//            1567, 10, ft_itoa(1567));
//     printf("Base: %d\t\tConverted String: %s\n", 2,
//            ft_itoa(1567));
//     printf("Base: %d\t\tConverted String: %s\n", 8,
//            ft_itoa(1567));
//     printf("Base: %d\tConverted String: %s\n", 16,
//            ft_itoa(1567));
//     return 0;
// }