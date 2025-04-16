/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:59:10 by atabarea          #+#    #+#             */
/*   Updated: 2025/04/16 11:27:48 by alex             ###   ########.fr       */
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

void	process_stack_a(t_list *a, t_list *b, int *min_val, int range)
{
	*min_val = find_min_value(a);
	if (a->array[0] <= *min_val)
	{
		push_to_b(a, b);
		rotate_b(b);
		(*min_val)++;
	}
	else if (*min_val < a->array[0] && a->array[0] <= *min_val + range)
	{
		push_to_b(a, b);
		(*min_val)++;
	}
	else
		rotate_a(a);
}

void	sort_large(t_list *a, t_list *b)
{
	int	min_val;
	int range;
	int	max_val;

	max_val = find_max_value(a);
	min_val = find_min_value(a);
	if (stack_len(a) <= 200)
		range = (max_val - min_val) / 8;
	else if (stack_len(a) <= 400)
		range = (max_val - min_val) / 11;
	else
		range = (max_val - min_val) / 14;
	if (range < 1)
		range = 1;
	if (stack_len(a) == 0)
        return;
	while (stack_len(a))
		process_stack_a(a, b, &min_val, range);
	while (stack_len(b))
		k_sort(a, b);
}
