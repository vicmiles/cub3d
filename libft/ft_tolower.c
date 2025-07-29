/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmileshk <vmileshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:16:46 by thrychka          #+#    #+#             */
/*   Updated: 2025/07/02 11:39:10 by vmileshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_tolower(char a)
{
	char	res;

	if ((a >= 65) && (a <= 90))
	{
		res = a - 'A' + 'a';
		return (res);
	}
	return (a);
}
