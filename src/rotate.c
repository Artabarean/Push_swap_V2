/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:45:59 by atabarea          #+#    #+#             */
/*   Updated: 2025/04/08 12:34:31 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_list *stack)
{
	int	bot_value;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (stack->top <= 0)
		return ;
	i = stack->top;
	bot_value = stack->array[0];
	while (j < i)
	{
		stack->array[j] = stack->array[j + 1];
		j++;
	}
	stack->array[stack->top] = bot_value;
	write(1, "ra\n", 3);
}

void	rotate_b(t_list *stack)
{
	int	bot_value;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (stack->top <= 0)
		return ;
	i = stack->top;
	bot_value = stack->array[0];
	while (j < i)
	{
		stack->array[j] = stack->array[j + 1];
		j++;
	}
	stack->array[stack->top] = bot_value;
	write(1, "rb\n", 3);
}

void	rotate(t_list *stack, char name)
{
	int	bot_value;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (stack->top <= 0)
		return ;
	i = stack->top;
	bot_value = stack->array[0];
	while (j < i)
	{
		stack->array[j] = stack->array[j + 1];
		j++;
	}
	stack->array[stack->top] = bot_value;
	write(1, "r", 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}
