/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:24:43 by atabarea          #+#    #+#             */
/*   Updated: 2025/04/08 12:57:23 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_remove_zeros(char *result)
{
	int	negative;

	negative = 0;
	if (!result || !*result)
		return (NULL);
	if ('-' == *result)
	{
		negative = 1;
		result++;
	}
	if ('+' == *result)
		result++;
	if (!*result)
		return (write(2, "Error\n", 6), result);
	while ('0' == *result && *(result + 1))
		result++;
	if (*result && negative)
	{
		*(result - 1) = '-';
		result--;
	}
	return (result);
}

long	ft_atoi_long(char *nptr)
{
	int		i;
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	nptr = ft_remove_zeros(nptr);
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
