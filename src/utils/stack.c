/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkisala <mkisala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:45:56 by mkisala           #+#    #+#             */
/*   Updated: 2026/02/23 17:46:29 by mkisala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_node	*new_node(int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		error();
	node->data = data;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	push_top(t_stack *stack, t_node *node)
{
	if (!stack->top)
	{
		stack->top = node;
		stack->size = 1;
		return ;
	}
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

void	push_bottom(t_stack *stack, t_node *node)
{
	t_node	*tmp;

	if (!stack->top)
	{
		stack->top = node;
		stack->size = 1;
		return ;
	}
	tmp = stack->top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	stack->size++;
}

t_node	*pop(t_stack *stack)
{
	t_node	*node;

	if (!stack->top)
		return (NULL);
	node = stack->top;
	stack->top = node->next;
	node->next = NULL;
	stack->size--;
	return (node);
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	while (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	stack->size = 0;
}
