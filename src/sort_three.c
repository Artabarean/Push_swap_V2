/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:14:54 by alex              #+#    #+#             */
/*   Updated: 2025/04/11 12:30:39 by atabarea         ###   ########.fr       */
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

void	sort_four(t_list *a, t_list *b)
{
	int	smallest_pos;

	smallest_pos = find_min_value(a);
	while (smallest_pos != a->array[0])
		rotate_a(a);
	push_to_b(a, b);
	sort_three(a);
	push_to_a(b, a);
}
