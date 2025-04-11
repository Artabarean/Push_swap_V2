/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:30:19 by atabarea          #+#    #+#             */
/*   Updated: 2025/04/11 11:20:59 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(t_list *stack)
{
	int	i;

	i = 0;
	if (stack->top <= 0)
		return (0);
	while (i < stack->top)
	{
		if (stack->array[i] > stack->array[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	stack_is_empty(t_list *stack)
{
	return (stack->top < 0);
}

int	stack_len(t_list *stack)
{
	return (stack->top + 1);
}

int	push_swap(int argc, char **numbers, int count)
{
	t_list	*sa;
	t_list	*sb;

	int     i;
	i = 0;
	sa = stack_init(count);
	sb = stack_init(count);
	if (!sa || !sb)
		return (free_stacks(sa, sb), 1);
	stack_init_from_strings(sa, numbers);
	sa->top = count - 1;
	while (i <= sa->top)
	 {
	     printf("%ld, ", sa->array[i]);
	     i++;
	 }
	 printf("\n");
	 i = 0;
	if (arguments_valid(sa->array, sa->top) == 1)
		return (write(2, "Error\n", 6), 1);
	if (check_max_min(sa->array, sa->top) == 1)
		return (write(2, "Error\n", 6), 1);
	if (stack_is_sorted(sa) == 1)
	{
		if (stack_len(sa) == 2)
			swap_a(sa);
		else if (stack_len(sa) == 3)
			sort_three(sa);
		else
			organizer(sa, sb);
	}
	while (i <= sa->top)
	{
	     printf("%ld, ", sa->array[i]);
	     i++;
	}
	 printf("\n");
	if (argc == 2)
		free(numbers);
	return (free_stacks(sa, sb), 0);
}

int	main(int argc, char *argv[])
{
	char	**numbers;
	int		count;

	if (argc == 1)
		return (1);
	if ((argc == 2 && !argv[1][0]))
		return (write(2, "Error\n", 6), 1);
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = &argv[1];
	if (char_search(numbers) == 1)
		return (write(2, "Error\n", 6), 1);
	count = 0;
	while (numbers[count])
		count++;
	return (push_swap(argc, numbers, count));
}
