/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:14:54 by alex              #+#    #+#             */
/*   Updated: 2025/04/08 14:36:55 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_list *a)
{
	int	mid;
	int	bot;
	int	top;

	top = a->array[a->top];
	mid = a->array[a->top - 1];
	bot = a->array[a->top - 2];
	sorter(a, top, mid, bot);
}

void	sorter(t_list *a, int top, int mid, int bot)
{
	if (bot < top && top < mid)
	{
		reverse_rotate_a(a);
		swap_a(a);
	}
	if (mid < bot && bot < top)
		swap_a(a);
	if (mid < top && top < bot)
		rotate_a(a);
	if (top < bot && bot < mid)
		reverse_rotate_a(a);
	if (top < mid && mid < bot)
	{
		rotate_a(a);
		swap_a(a);
	}
}

void	optimize_small_groups(t_list *a, t_list *b)
{
	int	size_a;
	int	min_pos;

	size_a = a->top + 1;
	if (size_a == 3)
	{
		sort_three(a);
		return ;
	}
	if (size_a == 2 && a->array[0] > a->array[1])
		swap_a(a);
	if (size_a <= 5)
	{
		min_pos = find_smallest_position(a);
		if (min_pos != 0)
		{
			move_to_bot(a, min_pos, 'a');
		}
		push_to_b(a, b);
		if (a->top + 1 == 3)
		{
			sort_three(a);
		}
		push_to_a(b, a);
	}
}

void	sort_four(t_list *a, t_list *b)
{
	int	smallest_pos;

	smallest_pos = find_smallest_position(a);
	while (smallest_pos != a->array[0])
		rotate_a(a);
	push_to_b(a, b);
	sort_three(a);
	push_to_a(b, a);
}
