/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:21:09 by atabarea          #+#    #+#             */
/*   Updated: 2025/04/08 12:33:47 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
	s = ptr;
}
/*#include <stdio.h>
int	main(void)
{
	char	s[10] = "holapepito";
	size_t	len = 4;

	printf("%s\n", s);
	ft_bzero(s, len);
	printf("%s\n", s);
	return (0);
}*/