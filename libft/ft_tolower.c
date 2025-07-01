/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrychka <thrychka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:16:46 by thrychka          #+#    #+#             */
/*   Updated: 2024/07/03 19:56:06 by thrychka         ###   ########.fr       */
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

// int main()
// {
// 	char ch;

// 	ch = '3';
// 	printf("%c in uppercase is represented as %c\n",
// 		ch, tolower(ch));
//     ch = '3';
// 	printf("%c in uppercase is represented as %c\n",
// 		ch, ft_tolower(ch));

// 	return 0;
// }