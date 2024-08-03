#include "pushswap.h"

int	minvalue(t_stacks **stack)
{
	t_stacks	*head;
	int		min;

	head = *stack;
	min = head->data;
	while (head->next)
	{
		head = head->next;
		if ((head->data < min))
			min = head->data;
	}
	return (min);
}

void sort_3(t_stacks **stack, t_data *nab)
{
	t_stacks *a;

	a = *stack;
    if(a->data < a->next->data && a->next->next->data < a->next->data)
	{
        rra(stack);
		a = *stack;
	}
    if(a->data < a->next->data && a->next->next->data < a->next->data)
    {
        rra(stack);
        sa(stack);
		a = *stack;
    }
    if(a->data > a->next->data && a->next->next->data > a->data)
        sa(stack);
    if(a->data > a->next->data && a->next->next->data < a->next->data)
    {
        sa(stack);
        rra(stack);
    }
    if(a->data > a->next->data && a->data > a->next->next->data)
        ra(stack);
} 

void sort_4(t_stacks **stacka, t_stacks **stackb, t_data *nab)
{
	t_stacks *a;

	a = *stacka;
    while(a->data != minvalue(stacka))
	{
        ra(stacka);
		a = *stacka;
	}
    pb(stackb, stacka, nab);
  	sort_3(stacka, nab);
    pa(stacka, stackb, nab);
}

void sort_5(t_stacks **stacka, t_stacks **stackb,  t_data *nab)
{
	t_stacks *a;

	a = *stacka;
    while(a->data != minvalue(stacka))
	{
		ra(stacka);
		a = *stacka;
	}
    pb(stackb, stacka, nab);
    sort_4(stacka, stackb, nab);
    pa(stacka, stackb, nab);
}

void shortsort(t_stacks **a, t_stacks **b, t_data *nab)
{
    if (nab->na == 2)
        sa(a);
    if (nab->na == 3)
    {
        sort_3(a, nab);
    }
    if (nab->na == 4)
        sort_4(a, b, nab);
    if (nab->na == 5)
        sort_5(a, b, nab);
}