/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:53:05 by atabarea          #+#    #+#             */
/*   Updated: 2025/04/14 12:51:43 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ctype.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_list
{
	long	*array;
	int		size;
	int		top;
}			t_list;

size_t		ft_strlen(char *s);
char		*ft_remove_zeros(char *result);
int			ft_isdigit(int c);
int			char_search(char **numbers);
int			arguments_valid(long *array, int top);
void		sorter(t_list *a, int top, int mid, int bot);
void		sort_three(t_list *a);
void		free_stacks(t_list *sa, t_list *sb);
void		push_to_a(t_list *src, t_list *dst);
void		rotate(t_list *stack, char name);
void		reverse_rotate(t_list *stack, char name);
void		stack_init_from_strings(t_list *stack, char **strings);
t_list		*stack_init(int size);
void		k_sort(t_list *a, t_list *b);
int			stack_pop(t_list *stack);
void		stack_push(t_list *stack, long value);
void		swap_a(t_list *stack);
int			check_max_min(long *nums, int top);
void		swap_b(t_list *stack);
void		rotate__iterate_b(t_list *b, int *max_indx);
void		reverse_rotate_iterate_b(t_list *b, int *max_indx);
int			stack_is_sorted(t_list *stack);
int			stack_is_empty(t_list *stack);
int			stack_len(t_list *stack);
int			push_swap(int argc, char **numbers, int count);
void		organizer(t_list *a, t_list *b);
void		sort_small(t_list *a, t_list *b);
int			find_smallest_position(t_list *stack);
int			find_min_value(t_list *stack);
void		move_to_bot(t_list *stack, int pos, char name);
void		sort_large(t_list *a, t_list *b);
int			find_largest_position(t_list *stack);
char		**ft_split(char const *s, char c);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);
void		rotate_b(t_list *stack);
void		rotate_a(t_list *stack);
void		reverse_rotate_b(t_list *stack);
void		reverse_rotate_a(t_list *stack);
void		push_to_b(t_list *src, t_list *dst);
long		ft_atoi_long(char *nptr);
void		sort_four(t_list *a, t_list *b);
char		**ft_free_array(char **liberated, size_t size);

#endif