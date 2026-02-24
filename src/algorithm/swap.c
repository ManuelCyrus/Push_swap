/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkisala <mkisala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:56:16 by mkisala           #+#    #+#             */
/*   Updated: 2026/02/23 19:04:34 by mkisala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	swap_stack(t_stack *s)
{
	t_node	*a;
	t_node	*b;
	int		tmp_data;
	int		tmp_index;

	if (!s || s->size < 2)
		return ;
	a = s->top;
	b = a->next;
	tmp_data = a->data;
	tmp_index = a->index;
	a->data = b->data;
	a->index = b->index;
	b->data = tmp_data;
	b->index = tmp_index;
}

void	sa(t_stack *a)
{
	swap_stack(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap_stack(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
	write(1, "ss\n", 3);
}
