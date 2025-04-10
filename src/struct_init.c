/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:24:38 by alex              #+#    #+#             */
/*   Updated: 2025/04/08 13:08:53 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_lst	*struct_init(int initializer)
{
	t_lst	*auxvar;

	auxvar = (t_lst *)malloc(sizeof(t_lst));
	if (!auxvar)
		return (NULL);
	auxvar->len = initializer;
	auxvar->ck_ct = initializer;
	auxvar->ck_size = initializer;
	auxvar->min = initializer;
	auxvar->max = initializer;
	auxvar->median = initializer;
	auxvar->ck_min = initializer;
	auxvar->ck_max = initializer;
	auxvar->pushed = initializer;
	auxvar->best_pos = initializer;
	auxvar->c = initializer;
	auxvar->i = initializer;
	auxvar->min_pos = initializer;
	auxvar->best_cost = initializer;
	auxvar->stack_indx = initializer;
	auxvar->size_a = initializer;
	return (auxvar);
}
