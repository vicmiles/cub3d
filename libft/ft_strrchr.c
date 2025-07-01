/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrychka <thrychka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:57:58 by thrychka          #+#    #+#             */
/*   Updated: 2024/07/11 16:01:05 by thrychka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	size;

	size = ft_strlen(s);
	if ((char)c == '\0' && s[size] == '\0')
		return (&((char *)s)[size]);
	while (size > 0)
	{
		size--;
		if (s[size] == (char)c)
			return (&((char *)s)[size]);
	}
	return (0);
}

// int main()
// {
// 	// initializing string
// 	char str[] = "Geeksforeeks";

// 	// character to be searched
// 	char chr = 'e';

// 	// Storing pointer returned by
// 	char* ptr = ft_strrchr(str, chr);

//     printf("%s", ptr);

//     	// initializing string
// 	char strs[] = "Geeksforeeks";

// 	// character to be searched
// 	char ch = 'e';

// 	// Storing pointer returned by
// 	char* pt = ft_strrchr(strs, ch);

//     printf("%s", pt);

// 	return 0;
// }
