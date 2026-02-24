/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkisala <mkisala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:57:15 by mkisala           #+#    #+#             */
/*   Updated: 2026/02/23 19:04:35 by mkisala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate_stack(t_stack *s)
{
	t_node	*n;

	if (!s || s->size < 2)
		return ;
	n = pop(s);
	push_bottom(s, n);
}

void	ra(t_stack *a)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	rotate_stack(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	write(1, "rr\n", 3);
}
