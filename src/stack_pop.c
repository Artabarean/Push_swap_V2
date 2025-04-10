/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:03:42 by alex              #+#    #+#             */
/*   Updated: 2025/04/08 12:34:57 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_pop(t_list *stack)
{
	int		i;
	long	value;

	if (stack->top < 0)
		return (-1);
	i = 0;
	value = stack->array[0];
	while (i < stack->top)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->top--;
	return (value);
}
