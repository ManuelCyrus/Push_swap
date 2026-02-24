/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkisala <mkisala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:14:50 by mkisala           #+#    #+#             */
/*   Updated: 2026/02/23 17:27:43 by mkisala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	*joined;

	a.top = NULL;
	a.size = 0;
	b.top = NULL;
	b.size = 0;
	if (ac < 2)
		return (0);
	joined = ft_strjoin_args(ac, av);
	if (!joined)
		return (1);
	parse_string(&a, joined, joined);
	check_duplicates(&a);
	if (is_sorted(&a))
	{
		free_stack(&a);
		return (0);
	}
	assign_index(&a);
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
