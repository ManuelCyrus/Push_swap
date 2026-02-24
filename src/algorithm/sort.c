/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkisala <mkisala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:01:10 by mkisala           #+#    #+#             */
/*   Updated: 2026/02/23 19:30:37 by mkisala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	range;

	i = 0;
	if (a->size <= 100)
		range = 15;
	else
		range = 35;
	while (a->top)
	{
		if (a->top->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (a->top->index <= (i + range))
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	push_back_to_a(a, b);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	assign_index(a);
	if (a->size <= 1)
		return ;
	if (a->size == 2)
	{
		if (a->top->index > a->top->next->index)
			sa(a);
	}
	else if (a->size <= 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_four_five(a, b);
	else
		chunk_sort(a, b);
}
