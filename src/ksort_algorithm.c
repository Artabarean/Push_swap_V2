/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:59:10 by atabarea          #+#    #+#             */
/*   Updated: 2025/04/14 12:47:03 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	k_sort(t_list *a, t_list *b)
{
	int	max_pos;
	int	len;

	len = stack_len(b);
	max_pos = find_largest_position(b);
	if (max_pos <= len / 2)
	{
		while (max_pos > 0)
		{
			rotate_b(b);
			max_pos--;
		}
	}
	else
	{
		while (max_pos < len)
		{
			reverse_rotate_b(b);
			max_pos++;
		}
	}
	push_to_a(b, a);
}

void	process_stack_a(t_list *a, t_list *b, int *i, int range)
{
	*i = find_min_value(a);
	if (a->array[0] <= *i)
	{
		push_to_b(a, b);
		rotate_b(b);
		(*i)++;
	}
	else if (*i < a->array[0] && a->array[0] <= *i + range)
	{
		push_to_b(a, b);
		(*i)++;
	}
	else
		rotate_a(a);
}

void	sort_large(t_list *a, t_list *b)
{
	int	i;
	int range;
	int	size;
	
	size = stack_len(a);
	if (size <= 100)
		range = size / 6;
	else if (size <= 300)
		range = size / 12;
	else if (size <= 400)
		range = size / 14;
	else
		range = size / 16;
	i = find_min_value(a);
	if (stack_len(a) == 0)
        return;
	while (stack_len(a))
		process_stack_a(a, b, &i, range);
	while (stack_len(b))
		k_sort(a, b);
}
