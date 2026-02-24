/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkisala <mkisala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:59:21 by mkisala           #+#    #+#             */
/*   Updated: 2026/02/23 19:28:52 by mkisala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->index;
	second = a->top->next->index;
	third = a->top->next->next->index;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static int	get_min_pos(t_stack *stack)
{
	t_node	*tmp;
	int		min_idx;
	int		pos;
	int		i;

	tmp = stack->top;
	min_idx = tmp->index;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->index < min_idx)
		{
			min_idx = tmp->index;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

static void	rotate_a_up(t_stack *a, int pos)
{
	while (pos > 0)
	{
		ra(a);
		pos--;
	}
}

static void	rotate_a_down(t_stack *a, int moves)
{
	while (moves > 0)
	{
		rra(a);
		moves--;
	}
}

void	sort_four_five(t_stack *a, t_stack *b)
{
	int	pos;
	int	moves;

	while (a->size > 3)
	{
		pos = get_min_pos(a);
		if (pos <= a->size / 2)
			rotate_a_up(a, pos);
		else
		{
			moves = a->size - pos;
			rotate_a_down(a, moves);
		}
		pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
