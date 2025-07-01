/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thrychka <thrychka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:34:35 by thrychka          #+#    #+#             */
/*   Updated: 2024/07/11 16:00:41 by thrychka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_separator(char s, char c)
{
	return (s == c);
}

static int	ft_count_strings(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && ft_check_separator(s[i], c))
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && !ft_check_separator(s[i], c))
			i++;
	}
	return (count);
}

static int	ft_strlen_sep(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && !ft_check_separator(s[i], c))
		i++;
	return (i);
}

static char	*ft_word(char *s, char c)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = ft_strlen_sep(s, c);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	while (i < len_word)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**rs;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	rs = (char **)malloc(sizeof(char *) * (ft_count_strings((char *)s, c) + 1));
	if (rs == NULL)
		return (NULL);
	while (s[j] != '\0')
	{
		while (s[j] != '\0' && ft_check_separator(s[j], c))
			j++;
		if (s[j] != '\0')
		{
			rs[i] = ft_word(&((char *)s)[j], c);
			i++;
		}
		while (s[j] && !ft_check_separator(s[j], c))
			j++;
	}
	rs[i] = 0;
	return (rs);
}

// // Функция для печати результатов split
// void print_split_result(char **result)
// {
//     int i = 0;
//     while (result[i] != NULL)
//     {
//         printf("result[%d]: %s\n", i, result[i]);
//         i++;
//     }
// }

// // Основная функция для тестирования ft_split
// int main()
// {
//     char **result;
//     char *str;
//     char delimiter;

//     // Тестовый пример 1
//     str = "hello world this is a test";
//     delimiter = ' ';
//     result = ft_split(str, delimiter);
//     printf("Test 1: \"%s\" split by '%c'\n", str, delimiter);
//     print_split_result(result);

//     // Освобождение памяти
//     for (int i = 0; result[i] != NULL; i++)
//     {
//         free(result[i]);
//     }
//     free(result);

//     // Тестовый пример 2
//     str = "   leading and trailing spaces   ";
//     delimiter = ' ';
//     result = ft_split(str, delimiter);
//     printf("Test 2: \"%s\" split by '%c'\n", str, delimiter);
//     print_split_result(result);

//     // Освобождение памяти
//     for (int i = 0; result[i] != NULL; i++)
//     {
//         free(result[i]);
//     }
//     free(result);

//     // Тестовый пример 3
//     str = "split,,by,commas";
//     delimiter = ',';
//     result = ft_split(str, delimiter);
//     printf("Test 3: \"%s\" split by '%c'\n", str, delimiter);
//     print_split_result(result);

//     // Освобождение памяти
//     for (int i = 0; result[i] != NULL; i++)
//     {
//         free(result[i]);
//     }
//     free(result);

//     // Тестовый пример 4
//     str = "no_delimiters_here";
//     delimiter = ',';
//     result = ft_split(str, delimiter);
//     printf("Test 4: \"%s\" split by '%c'\n", str, delimiter);
//     print_split_result(result);

//     // Освобождение памяти
//     for (int i = 0; result[i] != NULL; i++)
//     {
//         free(result[i]);
//     }
//     free(result);

//     return 0;
// }
