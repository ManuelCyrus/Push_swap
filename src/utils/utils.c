#include "../../include/push_swap.h"


void error(void)
{
    write(2,"Error\n",6);
    exit(1);
}

void error_free(t_stack *a, t_stack *b)
{
    if (a)
        free_stack(a);
    if (b)
        free_stack(b);
    write(2, "Error\n", 6);
    exit(1);
}

long ft_atol(const char *str, t_stack *a)
{
    long res = 0;
    int sign = 1;

    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }

    if (!(*str >= '0' && *str <= '9'))
        error_free(a, NULL);

    while (*str >= '0' && *str <= '9')
    {
        int digit = *str - '0';

        if (sign == 1 && res > (LONG_MAX - digit) / 10)
            error_free(a, NULL);

        if (sign == -1 && -res < (LONG_MIN + digit) / 10)
            error_free(a, NULL);

        res = res * 10 + digit;
        str++;
    }

    if (*str != '\0')
        error_free(a, NULL);

    res *= sign;

    if (res > INT_MAX || res < INT_MIN)
        error_free(a, NULL);

    return res;
}

int is_sorted(t_stack *a)
{
    t_node *tmp = a->top;
    for(int i=0;i<a->size-1;i++)
    {
        if(tmp->data>tmp->next->data) return 0;
        tmp=tmp->next;
    }
    return 1;
}