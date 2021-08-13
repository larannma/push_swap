#include "../include/push_swap.h"

t_list     *get_pointer(t_stack *stack1)
{
    t_list  *stack;

    stack = stack1->begin;

    while (stack->next)
    {
        stack = stack->next;
    }
    return stack;
}

void    rotate(t_stack *stack, int flag)
{
    t_list  *old_second;
    t_list  *tmp;

    print_list(stack);
    old_second = stack->begin->next;
    tmp = get_pointer(stack);
    tmp->next = stack->begin;
    tmp->next->next = NULL;
    stack->begin = old_second;
    print_list(stack);
}