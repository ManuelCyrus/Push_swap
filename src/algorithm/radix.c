#include "../../include/push_swap.h"

static void sort_three(t_stack *a)
{
    int f = a->top->index;
    int s = a->top->next->index;
    int t = a->top->next->next->index;

    if (f > s && s < t && f < t) sa(a);
    else if (f > s && s > t) { sa(a); rra(a); }
    else if (f > s && s < t && f > t) ra(a);
    else if (f < s && s > t && f < t) { sa(a); ra(a); }
    else if (f < s && s > t && f > t) rra(a);
}


static void sort_four_five(t_stack *a, t_stack *b)
{
    while (a->size > 3)
    {
        int min_idx = a->top->index;
        t_node *tmp = a->top;
        int pos = 0, i = 0;
        while (tmp)
        {
            if (tmp->index < min_idx)
            {
                min_idx = tmp->index;
                pos = i;
            }
            tmp = tmp->next;
            i++;
        }

        if (pos <= a->size / 2)
            while (pos--) ra(a);
        else
            while (pos++ < a->size) rra(a);

        pb(a,b);
    }
    sort_three(a);
    while (b->size) pa(a,b);
}


static int get_max_pos(t_stack *stack)
{
    t_node  *tmp;
    int     max_idx;
    int     max_pos;
    int     pos;

    if (!stack->top)
        return (-1);
    tmp = stack->top;
    max_idx = tmp->index;
    max_pos = 0;
    pos = 0;
    while (tmp)
    {
        if (tmp->index > max_idx)
        {
            max_idx = tmp->index;
            max_pos = pos;
        }
        tmp = tmp->next;
        pos++;
    }
    return (max_pos);
}

/* Move de B para A ordenadamente */
static void push_back_to_a(t_stack *a, t_stack *b)
{
    while (b->size > 0)
    {
        int pos = get_max_pos(b);
        int half = b->size / 2;

        if (pos <= half)
        {
            while (pos--)
                rb(b);
        }
        else
        {
            int moves = b->size - pos;
            while (moves--)
                rrb(b);
        }
        pa(a, b);
    }
}

/* Algoritmo de Chunks para 100-500 números */
void chunk_sort(t_stack *a, t_stack *b)
{
    int i = 0;
    int range;

    if (a->size <= 100)
        range = 15;
    else
        range = 35;

    while (a->top)
    {
        if (a->top->index <= i)
        {
            pb(a, b);
            rb(b);
            i++;
        }
        else if (a->top->index <= (i + range))
        {
            pb(a, b); 
            i++;
        }
        else
            ra(a);
    }
    push_back_to_a(a, b);
}

void sort_stack(t_stack *a, t_stack *b)
{
    assign_index(a);
    if (a->size <= 1)
        return;
    if (a->size == 2)
    {
        if (a->top->index > a->top->next->index)
            sa(a);
    }
    else if (a->size == 3)
    {
        int f = a->top->index;
        int s = a->top->next->index;
        int t = a->top->next->next->index;
        if (f > s && s < t && f < t) sa(a);
        else if (f > s && s > t) { sa(a); rra(a); }
        else if (f > s && s < t && f > t) ra(a);
        else if (f < s && s > t && f < t) { sa(a); ra(a); }
        else if (f < s && s > t && f > t) rra(a);
    }
    else if (a->size <= 5)
        sort_four_five(a, b); 
    else
        chunk_sort(a, b);
}