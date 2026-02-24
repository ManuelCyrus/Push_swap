/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkisala <mkisala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:17:00 by mkisala           #+#    #+#             */
/*   Updated: 2026/02/23 23:32:49 by mkisala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	fill_tmp_array(int *tmp_arr, char **av, int ac)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		if (!check_integer(av[i + 1]))
			print_error();
		tmp_arr[i] = atoi(av[i + 1]);
		i++;
	}
}

void	parse_args_stack(int ac, char **av, t_stack *a)
{
	int	*tmp_arr;
	int	i;

	tmp_arr = malloc(sizeof(int) * (ac - 1));
	if (!tmp_arr)
		exit(EXIT_FAILURE);
	fill_tmp_array(tmp_arr, av, ac);
	if (has_duplicates(tmp_arr, ac - 1))
		print_error();
	i = ac - 2;
	while (i >= 0)
	{
		push_top(a, new_node(tmp_arr[i]));
		i--;
	}
	free(tmp_arr);
}

/* Executa uma instrução da pilha */
void	execute_instruction(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(line, "sa"))
		sa(a);
	else if (!ft_strcmp(line, "sb"))
		sb(b);
	else if (!ft_strcmp(line, "ss"))
		ss(a, b);
	else if (!ft_strcmp(line, "pa"))
		pa(a, b);
	else if (!ft_strcmp(line, "pb"))
		pb(a, b);
	else if (!ft_strcmp(line, "ra"))
		ra(a);
	else if (!ft_strcmp(line, "rb"))
		rb(b);
	else if (!ft_strcmp(line, "rr"))
		rr(a, b);
	else if (!ft_strcmp(line, "rra"))
		rra(a);
	else if (!ft_strcmp(line, "rrb"))
		rrb(b);
	else if (!ft_strcmp(line, "rrr"))
		rrr(a, b);
	else
		print_error();
}

static char	*resize_line(char *line, size_t *size)
{
	char	*new_line;
	size_t	i;

	*size *= 2;
	new_line = malloc(*size);
	if (!new_line)
	{
		free(line);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	free(line);
	return (new_line);
}

int	get_line(char **line)
{
	char	c;
	size_t	i;
	size_t	size;

	i = 0;
	size = 128;
	*line = malloc(size);
	if (!*line)
		exit(EXIT_FAILURE);
	while (read(0, &c, 1) == 1)
	{
		if (c == '\n')
			break ;
		(*line)[i++] = c;
		if (i >= size)
			*line = resize_line(*line, &size);
	}
	if (i == 0 && c != '\n')
	{
		free(*line);
		return (0);
	}
	(*line)[i] = '\0';
	return (1);
}
