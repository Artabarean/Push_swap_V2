/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_from_strings.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:19:18 by alex              #+#    #+#             */
/*   Updated: 2025/04/08 12:34:47 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_init_from_strings(t_list *stack, char **strings)
{
	int		i;
	long	value;

	value = 0;
	i = 0;
	while (strings[i])
		i++;
	i--;
	while (i >= 0)
	{
		value = ft_atoi_long(strings[i]);
		stack_push(stack, value);
		i--;
	}
}
