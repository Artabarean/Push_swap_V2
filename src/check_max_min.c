/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:43:26 by atabarea          #+#    #+#             */
/*   Updated: 2025/04/14 12:58:46 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_max_min(long *nums, int top)
{
	int	i;

	i = 0;
	while (i <= top)
	{
		if (nums[i] > INT_MAX || nums[i] < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	find_min_value(t_list *stack)
{
	int	i;
	int	min;
	int	length;

	length = stack_len(stack);
	min = INT_MAX;
	i = 0;
	while (i < length)
	{
		if (stack->array[i] < min)
			min = stack->array[i];
		i++;
	}
	return (min);
}
