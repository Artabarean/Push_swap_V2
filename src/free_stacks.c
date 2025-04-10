/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:08:16 by atabarea          #+#    #+#             */
/*   Updated: 2025/04/08 12:33:37 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stacks(t_list *sa, t_list *sb)
{
	if (sa && sb)
	{
		if (sa->array && sb->array)
		{
			free(sa->array);
			free(sb->array);
		}
		free(sa);
		free(sb);
	}
}
