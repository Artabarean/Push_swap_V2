/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:11:42 by atabarea          #+#    #+#             */
/*   Updated: 2025/04/08 12:33:11 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	char_search(char **num)
{
	int	i;
	int	j;

	i = 0;
	while (num[i])
	{
		j = 0;
		while (num[i][j])
		{
			if (!ft_isdigit(num[i][j]))
			{
				if (num[i][j] != '-' || j != 0 || !ft_isdigit(num[i][j + 1]))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
