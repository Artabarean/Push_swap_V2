/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:59:10 by atabarea          #+#    #+#             */
/*   Updated: 2025/04/16 12:25:10 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_element_rotation(t_list *b, int *position, int *other_pos, int len)
{
    if (*position <= len / 2)
    {
        while (*position > 0)
        {
            rotate_b(b);
            (*position)--;
            if (*other_pos == 0)
                *other_pos = len - 1;
            else
                (*other_pos)--;
        }
    }
    else
    {
        while (*position < len)
        {
            reverse_rotate_b(b);
            (*position)++;
            if (*other_pos == len - 1)
                *other_pos = 0;
            else
                (*other_pos)++;
        }
    }
}

void	k_sort(t_list *a, t_list *b, t_struct *aux)
{
	int	len;

    len = stack_len(b);
    find_largest_positions(b, &aux->max_pos, &aux->nmax_pos);
    aux->c_max = aux->max_pos;
    if (aux->max_pos > len / 2)
		aux->c_max = len - aux->max_pos;  
    aux->c_nmax = aux->nmax_pos;
    if (aux->nmax_pos > len / 2)
        aux->c_nmax = len - aux->nmax_pos;
    if (aux->c_nmax < aux->c_max && sequence(aux->max_pos, aux->nmax_pos, len))
    {
        handle_element_rotation(b, &aux->nmax_pos, &aux->max_pos, len);
        push_to_a(b, a);
        
        len = stack_len(b);
        handle_element_rotation(b, &aux->max_pos, &aux->nmax_pos, len);
        push_to_a(b, a);
    }
    else
    {
        handle_element_rotation(b, &aux->max_pos, &aux->nmax_pos, len);
        push_to_a(b, a);
    }
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
	t_struct *aux;

	aux = struct_init(0);
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
		k_sort(a, b, aux);
}
