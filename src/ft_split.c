/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:15:09 by atabarea          #+#    #+#             */
/*   Updated: 2025/03/28 10:28:56 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	ft_wrdcnt(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (!s[i + 1] || s[i + 1] == c))
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_lttrcnt(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

static char	*ft_createstr(char const *s, char c, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

static char	**ft_free_array(char **liberated, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		free(liberated[index]);
		index++;
	}
	free(liberated);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	char const	*ptr;
	size_t		i;

	if (!s)
		return (NULL);
	result = ft_calloc(ft_wrdcnt(s, c) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	ptr = s;
	while (*ptr == c)
		ptr++;
	while (i < ft_wrdcnt(s, c))
	{
		result[i] = ft_createstr(ptr, c, ft_lttrcnt(ptr, c));
		if (!result[i])
			return (ft_free_array(result, i));
		ptr += ft_lttrcnt(ptr, c);
		while (*ptr == c)
			ptr++;
		i++;
	}
	result[i] = NULL;
	return (result);
}
// #include <stdio.h>
// int main()
// {
//     char **result;
//     char str[] = "  hola esto es   un k ebab ";
//     size_t i = 0;
//     result = ft_split(str, ' ');
//     if (result)
//     {
//         while (result[i])
//         {
//             printf("Word %zu: '%s'\n", i + 1, result[i]);
//             free(result[i]);
//             i++;
//         }
//         free(result);
//     }
//     else
//     {
//         printf("An error has ocurred.\n");
//     }
//     return (0);
//}