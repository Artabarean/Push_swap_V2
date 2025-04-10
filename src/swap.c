/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:20:41 by atabarea          #+#    #+#             */
/*   Updated: 2025/04/08 12:35:12 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_list *stack)
{
	int	temp;

	temp = 0;
	if (stack->top < 1)
		return ;
	temp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = temp;
	write(1, "sa\n", 3);
}

void	swap_b(t_list *stack)
{
	int	temp;

	temp = 0;
	if (stack->top < 1)
		return ;
	temp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = temp;
	write(1, "sb\n", 3);
}
