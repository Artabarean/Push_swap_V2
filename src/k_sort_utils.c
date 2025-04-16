/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:43:59 by alex              #+#    #+#             */
/*   Updated: 2025/04/16 13:04:22 by alex             ###   ########.fr       */
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

void    find_largest_poss(t_list *sk, int *max_pos, int *nmax_pos, t_struct *a)
{
    int i;
    int len;

    i = 0;
    len = stack_len(sk);
    while (i < len)
    {
        if (sk->array[i] > a->max)
        {
            a->max = sk->array[i];
            *max_pos = i;
        }
        i++;
    }
    i = 0;
    while (i < len)
    {
        if (sk->array[i] > a->next_max && sk->array[i] < a->max)
        {
            a->next_max = sk->array[i];
            *nmax_pos = i;
        }
        i++;
    }
}
