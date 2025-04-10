/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:59:10 by atabarea          #+#    #+#             */
/*   Updated: 2025/04/10 11:42:53 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	k_sort(t_list *a, t_list *b)
{
	int	i;

	i = 0;
	while (b->array[i] != b->array[a->top])
		i++;
    if (i < ((a->top + 1) / 2))
    {
        while (i > 0)
        {
            rotate_b(b);
            i--;
        }
    }
    else
    {
        while (i < (a->top + 1))
        {
            i++;
			reverse_rotate_b(b);
        }
    }
    push_to_a(b, a);
}

void	process_stack_a(t_list *a, t_list *b, int *i, int range)
{
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
	int	range;

	i = 0;
	if (stack_len(a) <= 100)
		range = 20;
	else
	range = 25;
	while (stack_len(a))
		process_stack_a(a, b, &i, range);
	while (stack_len(a))
		k_sort(a, b);
}
