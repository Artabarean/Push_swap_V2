/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_iterate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:10:58 by atabarea          #+#    #+#             */
/*   Updated: 2025/04/11 10:30:35 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate__iterate_b(t_list *b, int *max_indx)
{
	rotate_b(b);
	max_indx--;
}

void	reverse_rotate_iterate_b(t_list *b, int *max_indx)
{
	max_indx++;
	reverse_rotate_b(b);
}