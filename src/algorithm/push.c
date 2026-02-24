/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkisala <mkisala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:56:38 by mkisala           #+#    #+#             */
/*   Updated: 2026/02/23 19:04:29 by mkisala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push_stack(t_stack *src, t_stack *dst)
{
	t_node	*n;

	n = pop(src);
	if (n)
		push_top(dst, n);
}

void	pa(t_stack *a, t_stack *b)
{
	push_stack(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push_stack(a, b);
	write(1, "pb\n", 3);
}
