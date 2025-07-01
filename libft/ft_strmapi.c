/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrychka <thrychka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:46:07 by thrychka          #+#    #+#             */
/*   Updated: 2024/07/11 16:34:26 by thrychka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include "ft_strlen.c"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (!s || !f)
		return (NULL);
	res = (char *)malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

// // Пример функции, которую будем использовать с ft_strmapi
// char to_uppercase(unsigned int i, char c)
// {
// 	if(!c)
// 	{
// 		return (i * 0);
// 	}
//     if (c >= 'a' && c <= 'z')
//         return (c - 32);
//     return (c);
// }

// // Пример функции, которая изменяет символы по их индексам
// char add_index(unsigned int index, char c)
// {
//     return (c + index);
// }

// // Основная функция для тестирования ft_strmapi
// int main()
// {
//     char *str;
//     char *result;

//     // Тестовый пример 1: перевод символов в верхний регистр
//     str = "hello world";
//     result = ft_strmapi(str, to_uppercase);
//     if (result)
//     {
//         printf("Original: %s\nModified: %s\n", str, result);
//         free(result);  // Освобождение памяти
//     }
//     else
//     {
//         printf("Memory allocation failed\n");
//     }

//     // Тестовый пример 2: добавление индекса к символу
//     str = "abcdef";
//     result = ft_strmapi(str, add_index);
//     if (result)
//     {
//         printf("Original: %s\nModified: %s\n", str, result);
//         free(result);  // Освобождение памяти
//     }
//     else
//     {
//         printf("Memory allocation failed\n");
//     }

//     return 0;
// }