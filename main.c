#include "include/push_swap.h"

int main(int ac,char **av)
{
    t_stack a = {NULL,0};
    t_stack b = {NULL,0};

    if (ac < 2)
        return 0;

    if (ac == 2)
        parse_string(&a,av[1]);
    else
        parse_args(&a,ac,av);

    check_duplicates(&a);

    if (is_sorted(&a))
    {
        free_stack(&a);
        return 0;
    }

    assign_index(&a);
    sort_stack(&a,&b);

    free_stack(&a);
    free_stack(&b);
    return 0;
}