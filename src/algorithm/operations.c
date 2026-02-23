#include "../../include/push_swap.h"

/* SWAP */
static void swap(t_stack *s)
{
    if (!s || s->size < 2) return;
    t_node *a = s->top;
    t_node *b = a->next;
    int tmp_data = a->data;
    int tmp_index = a->index;
    a->data = b->data;
    a->index = b->index;
    b->data = tmp_data;
    b->index = tmp_index;
}

void sa(t_stack *a){ swap(a); write(1,"sa\n",3); }
void sb(t_stack *b){ swap(b); write(1,"sb\n",3); }
void ss(t_stack *a,t_stack *b){ swap(a); swap(b); write(1,"ss\n",3); }

/* PUSH */
static void push(t_stack *src, t_stack *dst)
{
    t_node *n = pop(src);
    if (n) push_top(dst, n);
}

void pa(t_stack *a,t_stack *b){ push(b,a); write(1,"pa\n",3); }
void pb(t_stack *a,t_stack *b){ push(a,b); write(1,"pb\n",3); }

/* ROTATE */
void ra(t_stack *a){ if (a && a->size >= 2) { push_bottom(a, pop(a)); write(1,"ra\n",3); } }
void rb(t_stack *b){ if (b && b->size >= 2) { push_bottom(b, pop(b)); write(1,"rb\n",3); } }
void rr(t_stack *a,t_stack *b){ ra(a); rb(b); write(1,"rr\n",3); }

/* REVERSE ROTATE */
void rra(t_stack *a){ if (a && a->size >= 2) { t_node *last = a->top; t_node *prev = NULL; while (last->next) { prev = last; last = last->next; } prev->next = NULL; last->next = a->top; a->top = last; write(1,"rra\n",4); } }
void rrb(t_stack *b){ if (b && b->size >= 2) { t_node *last = b->top; t_node *prev = NULL; while (last->next) { prev = last; last = last->next; } prev->next = NULL; last->next = b->top; b->top = last; write(1,"rrb\n",4); } }
void rrr(t_stack *a,t_stack *b){ rra(a); rrb(b); write(1,"rrr\n",4); }