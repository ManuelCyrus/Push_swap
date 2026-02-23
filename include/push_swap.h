#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

/* STRUCTS */
typedef struct s_node
{
    int data;
    int index;
    struct s_node *next;
    struct s_node *prev;
} t_node;

typedef struct s_stack
{
    t_node *top;
    int size;
} t_stack;

/* STACK */
t_node  *new_node(int data);
void    push_top(t_stack *stack, t_node *node);
t_node  *pop(t_stack *stack);
void push_bottom(t_stack *stack, t_node *node);
void free_stack(t_stack *stack);
void error_free(t_stack *a, t_stack *b);



/* OPERATIONS */
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);

/* INDEX + SORT */
void assign_index(t_stack *a);
void radix_sort(t_stack *a, t_stack *b);
void sort_stack(t_stack *a, t_stack *b);

/* UTILS */
int     is_sorted(t_stack *a);
long ft_atol(const char *str, t_stack *a);
void    error(void);

/* PARSING */
char    **ft_split(const char *s, char c);
void    check_duplicates(t_stack *a);
void    parse_string(t_stack *a, char *str);
void    parse_args(t_stack *a, int ac, char **av);

#endif