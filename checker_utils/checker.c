/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkisala <mkisala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:17:44 by mkisala           #+#    #+#             */
/*   Updated: 2026/02/23 20:24:18 by mkisala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted_checker(t_stack *a)
{
	t_node	*tmp;

	tmp = a->top;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	check_integer(char *str)
{
	long	val;
	int		sign;

	if (!*str)
		return (0);
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (0);
	val = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		val = val * 10 + (*str - '0');
		if (val * sign > 2147483647 || val * sign < -2147483648)
			return (0);
		str++;
	}
	return (1);
}

int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
