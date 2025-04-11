/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:26:28 by atabarea          #+#    #+#             */
/*   Updated: 2025/04/11 12:24:55 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_small(t_list *a, t_list *b)
{
	int	i;
	int	smallest_pos;

	i = 0;
	while (i < 2)
	{
		smallest_pos = find_smallest_position(a);
		move_to_bot(a, smallest_pos, 'a');
		push_to_b(a, b);
		i++;
	}
	sort_three(a);
	while (b->top >= 0)
		push_to_a(b, a);
}

int	find_smallest_position(t_list *stack)
{
	int	smallest;
	int	pos;
	int	i;

	smallest = stack->array[0];
	pos = 0;
	i = 1;
	while (i <= stack->top)
	{
		if (stack->array[i] < smallest)
		{
			smallest = stack->array[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	find_largest_position(t_list *stack)
{
	int	largest;
	int	pos;
	int	i;

	if (stack->top < 0)
		return (-1);
	largest = stack->array[0];
	pos = 0;
	i = 1;
	while (i <= stack->top)
	{
		if (stack->array[i] > largest)
		{
			largest = stack->array[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	move_to_bot(t_list *stack, int pos, char name)
{
	int	len;
	int	moves;

	len = stack->top + 1;
	if (pos == 0)
		return ;
	if (pos > len / 2)
	{
		moves = len - pos;
		while (moves > 0 && stack->top >= 0)
		{
			reverse_rotate(stack, name);
			moves--;
		}
	}
	else
	{
		moves = pos;
		while (moves > 0 && stack->top >= 0)
		{
			rotate(stack, name);
			moves--;
		}
	}
}

void	organizer(t_list *a, t_list *b)
{
	int		len;

	len = a->top + 1;
	if (len == 4)
		sort_four(a, b);
	else if (len == 5)
		sort_small(a, b);
	else if (len > 5)
		sort_large(a, b);
}
