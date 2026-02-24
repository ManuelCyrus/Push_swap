/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkisala <mkisala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:54:41 by mkisala           #+#    #+#             */
/*   Updated: 2026/02/23 18:55:03 by mkisala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	*stack_to_array(t_stack *a)
{
	int		*arr;
	t_node	*tmp;
	int		i;

	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		error_free(a, NULL);
	tmp = a->top;
	i = 0;
	while (i < a->size)
	{
		arr[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}

static void	sort_array(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	assign_index(t_stack *a)
{
	int		*arr;
	t_node	*tmp;
	int		j;

	arr = stack_to_array(a);
	sort_array(arr, a->size);
	tmp = a->top;
	while (tmp)
	{
		j = 0;
		while (j < a->size)
		{
			if (tmp->data == arr[j])
			{
				tmp->index = j;
				break ;
			}
			j++;
		}
		tmp = tmp->next;
	}
	free(arr);
}
