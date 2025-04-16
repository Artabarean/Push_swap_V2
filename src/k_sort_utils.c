/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:43:59 by alex              #+#    #+#             */
/*   Updated: 2025/04/16 12:06:42 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int sequence(int max_pos, int next_max_pos, int len)
{
    int max_half;
    int next_max_half;
    int distance;
    
    max_half = 0;
    if (max_pos > len / 2)
        max_half = 1;
    next_max_half = 0;
    if (next_max_pos > len / 2)
        next_max_half = 1;
    if (max_half == next_max_half)
        return (1);
    if (max_pos > next_max_pos)
        distance = max_pos - next_max_pos;
    else
		distance = next_max_pos - max_pos;
    if (distance > len / 2)
        distance = len - distance;
    if (distance < len / 4)
        return (1);
    return (0);
}

void    find_largest_positions(t_list *stack, int *max_pos, int *next_max_pos)
{
    int i;
    int len;
    int max;
    int next_max;
    
    max = INT_MIN;
    next_max = INT_MIN;
    *max_pos = -1;
    *next_max_pos = -1;
    len = stack_len(stack);
    i = 0;
    while (i < len)
    {
        if (stack->array[i] > max)
        {
            max = stack->array[i];
            *max_pos = i;
        }
        i++;
    }
    i = 0;
    while (i < len)
    {
        if (stack->array[i] > next_max && stack->array[i] < max)
        {
            next_max = stack->array[i];
            *next_max_pos = i;
        }
        i++;
    }
}