/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:17:47 by atabarea          #+#    #+#             */
/*   Updated: 2025/04/08 12:34:53 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*stack_init(int size)
{
	t_list	*stack;

	stack = (t_list *)malloc(sizeof(t_list));
	if (!stack)
		return (NULL);
	stack->array = (long *)malloc(sizeof(long) * size);
	if (!stack->array)
	{
		free(stack);
		return (NULL);
	}
	stack->size = size;
	stack->top = -1;
	return (stack);
}
