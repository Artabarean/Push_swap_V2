/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:06:20 by alex              #+#    #+#             */
/*   Updated: 2025/04/16 12:18:50 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_struct	*struct_init(int i)
{
	t_struct	*aux;

	aux = (t_struct *)malloc(sizeof(t_struct));
	if (!aux)
		return (NULL);
	aux->c_max = i;
	aux->c_nmax = i;
	aux->max_pos = i;
	aux->nmax_pos = i;
	return (aux);
}
