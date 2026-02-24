/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkisala <mkisala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:00:37 by mkisala           #+#    #+#             */
/*   Updated: 2026/02/23 19:26:22 by mkisala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	get_max_pos(t_stack *stack)
{
	t_node	*tmp;
	int		max_idx;
	int		max_pos;
	int		pos;

	if (!stack->top)
		return (-1);
	tmp = stack->top;
	max_idx = tmp->index;
	max_pos = 0;
	pos = 0;
	while (tmp)
	{
		if (tmp->index > max_idx)
		{
			max_idx = tmp->index;
			max_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (max_pos);
}

static void	rotate_b_up(t_stack *b, int pos)
{
	while (pos > 0)
	{
		rb(b);
		pos--;
	}
}

static void	rotate_b_down(t_stack *b, int moves)
{
	while (moves > 0)
	{
		rrb(b);
		moves--;
	}
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	pos;
	int	half;
	int	moves;

	while (b->size > 0)
	{
		pos = get_max_pos(b);
		half = b->size / 2;
		if (pos <= half)
			rotate_b_up(b, pos);
		else
		{
			moves = b->size - pos;
			rotate_b_down(b, moves);
		}
		pa(a, b);
	}
}
