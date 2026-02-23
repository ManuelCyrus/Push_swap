// ============================
// index.c
// ============================
#include "../../include/push_swap.h"

static int *stack_to_array(t_stack *a)
{
    int *arr = malloc(sizeof(int) * a->size);
    if (!arr) error_free(a,NULL);

    t_node *tmp = a->top;
    for (int i = 0; i < a->size; i++)
    {
        arr[i] = tmp->data;
        tmp = tmp->next;
    }
    return arr;
}

static void sort_array(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
}

void assign_index(t_stack *a)
{
    int *arr = stack_to_array(a);
    sort_array(arr, a->size);

    t_node *tmp = a->top;
    while (tmp)
    {
        for (int j = 0; j < a->size; j++)
        {
            if (tmp->data == arr[j])
            {
                tmp->index = j;
                break;
            }
        }
        tmp = tmp->next;
    }
    free(arr);
}