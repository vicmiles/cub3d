/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrychka <thrychka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:25:15 by thrychka          #+#    #+#             */
/*   Updated: 2024/06/19 15:25:55 by thrychka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_isprint(char c)
{
	if ((c >= 32) && (c <= 126))
		return (1);
	return (0);
}

// int main(void)
// {
//     printf("%d\n", ft_isprint(' '));
//     printf("%d\n", isprint(' '));
//     printf("%d\n", ft_isprint('='));
//     printf("%d\n", isprint('='));
// }