#include "include/push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* ============================
   Funções de verificação
   ============================ */
int is_sorted_checker(t_stack *a)
{
    t_node *tmp = a->top;
    while (tmp && tmp->next)
    {
        if (tmp->data > tmp->next->data)
            return 0;
        tmp = tmp->next;
    }
    return 1;
}

void print_error(void)
{
    write(2, "Error\n", 6);
    exit(EXIT_FAILURE);
}

/* ============================
   Parsing de argumentos
   ============================ */
int check_integer(char *str)
{
    long val = 0;
    int i = 0, sign = 1;

    if (!str[i]) return 0;
    if (str[i] == '-' || str[i] == '+') { if (str[i] == '-') sign = -1; i++; }
    if (!str[i]) return 0;

    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9') return 0;
        val = val * 10 + (str[i] - '0');
        if (val * sign > 2147483647 || val * sign < -2147483648)
            return 0;
        i++;
    }
    return 1;
}

int has_duplicates(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (arr[i] == arr[j]) return 1;
    return 0;
}

void parse_args_stack(int ac, char **av, t_stack *a)
{
    int *tmp_arr = malloc(sizeof(int) * (ac - 1));
    if (!tmp_arr) exit(EXIT_FAILURE);

    for (int i = 0; i < ac - 1; i++)
    {
        if (!check_integer(av[i + 1])) { free(tmp_arr); print_error(); }
        tmp_arr[i] = atoi(av[i + 1]);
    }
    if (has_duplicates(tmp_arr, ac - 1)) { free(tmp_arr); print_error(); }

    for (int i = ac - 2; i >= 0; i--) 
        push_top(a, new_node(tmp_arr[i]));

    free(tmp_arr);
}


void execute_instruction(char *line, t_stack *a, t_stack *b)
{
    if (!strcmp(line, "sa")) sa(a);
    else if (!strcmp(line, "sb")) sb(b);
    else if (!strcmp(line, "ss")) ss(a,b);
    else if (!strcmp(line, "pa")) pa(a,b);
    else if (!strcmp(line, "pb")) pb(a,b);
    else if (!strcmp(line, "ra")) ra(a);
    else if (!strcmp(line, "rb")) rb(b);
    else if (!strcmp(line, "rr")) rr(a,b);
    else if (!strcmp(line, "rra")) rra(a);
    else if (!strcmp(line, "rrb")) rrb(b);
    else if (!strcmp(line, "rrr")) rrr(a,b);
    else print_error();
}


int get_line(char **line)
{
    char c;
    size_t i = 0, size = 128;
    *line = malloc(size);
    if (!*line) exit(EXIT_FAILURE);

    while (read(0, &c, 1) == 1)
    {
        if (c == '\n') { (*line)[i] = '\0'; return 1; }
        (*line)[i++] = c;
        if (i >= size)
        {
            size *= 2;
            *line = realloc(*line, size);
            if (!*line) exit(EXIT_FAILURE);
        }
    }
    if (i == 0) { free(*line); return 0; }
    (*line)[i] = '\0';
    return 1;
}

int main(int ac, char **av)
{
    t_stack a, b;
    a.top = NULL; a.size = 0;
    b.top = NULL; b.size = 0;

    if (ac < 2) return 0;

    parse_args_stack(ac, av, &a);

    char *line;
    while (get_line(&line))
    {
        execute_instruction(line, &a, &b);
        free(line);
    }

    if (is_sorted_checker(&a) && b.size == 0)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);

    free_stack(&a);
    free_stack(&b);
    return 0;
}