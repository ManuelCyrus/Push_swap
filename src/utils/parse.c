/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkisala <mkisala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:53:34 by mkisala           #+#    #+#             */
/*   Updated: 2026/02/23 18:53:34 by mkisala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_split(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	check_duplicates(t_stack *a)
{
	t_node	*i;
	t_node	*j;

	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->data == j->data)
				error_free(a, NULL);
			j = j->next;
		}
		i = i->next;
	}
}

void	parse_args(t_stack *a, int ac, char **av)
{
	long	n;
	int		err;
	int		i;

	i = 1;
	while (i < ac)
	{
		n = ft_atol(av[i], &err);
		if (err)
			error_free(a, NULL);
		push_bottom(a, new_node((int)n));
		i++;
	}
}

static void	fill_numbers(t_stack *a, char **nums, char *joined)
{
	long	n;
	int		err;
	int		i;

	i = 0;
	while (nums[i])
	{
		n = ft_atol(nums[i], &err);
		if (err)
		{
			free(joined);
			free_split(nums);
			error_free(a, NULL);
			return ;
		}
		push_bottom(a, new_node((int)n));
		i++;
	}
}

void	parse_string(t_stack *a, char *str, char *joined)
{
	char	**nums;

	nums = ft_split(str, ' ');
	if (!nums || !nums[0])
	{
		free(joined);
		free_split(nums);
		error_free(a, NULL);
		return ;
	}
	fill_numbers(a, nums, joined);
	free(joined);
	free_split(nums);
}
