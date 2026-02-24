/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkisala <mkisala@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:25:29 by mkisala           #+#    #+#             */
/*   Updated: 2026/02/23 20:25:46 by mkisala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/* STRUCTS */
typedef struct s_node
{
	int					data;
	int					index;
	struct s_node		*next;
	struct s_node		*prev;
}	t_node;

typedef struct s_stack
{
	t_node		*top;
	int			size;
}	t_stack;

/* STACK */
t_node	*new_node(int data);
void	push_top(t_stack *stack, t_node *node);
t_node	*pop(t_stack *stack);
void	push_bottom(t_stack *stack, t_node *node);
void	free_stack(t_stack *stack);
void	error_free(t_stack *a, t_stack *b);

/* OPERATIONS */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* INDEX + SORT */
void	assign_index(t_stack *a);
void	sort_stack(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	sort_four_five(t_stack *a, t_stack *b);
char	*ft_strjoin_args(int ac, char **av);
void	chunk_sort(t_stack *a, t_stack *b);
int		is_sorted(t_stack *a);
void	push_back_to_a(t_stack *a, t_stack *b);
long	ft_atol(const char *str, int *err);
void	error(void);

/* PARSING */
char	**ft_split(const char *s, char c);
void	check_duplicates(t_stack *a);
void	parse_string(t_stack *a, char *str, char *joined);
void	parse_args(t_stack *a, int ac, char **av);
void	parse_args_stack(int ac, char **av, t_stack *a);

/* CHECKER */
void	execute_instruction(char *line, t_stack *a, t_stack *b);
int		is_sorted_checker(t_stack *a);
void	print_error(void);
int		check_integer(char *str);
int		has_duplicates(int *arr, int size);
int		ft_strcmp(const char *s1, const char *s2);
int		get_line(char **line);

#endif
