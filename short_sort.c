#include "pushswap.h"

void	sort_3(t_stacks **stack)
{
	t_stacks	*a;

	a = *stack;
	if (a->data < a->next->data && a->next->next->data < a->next->data)
	{
		rra(stack);
		a = *stack;
	}
	if (a->data < a->next->data && a->next->next->data < a->next->data)
	{
		rra(stack);
		sa(stack);
		a = *stack;
	}
	if (a->data > a->next->data && a->next->next->data > a->data)
		sa(stack);
	if (a->data > a->next->data && a->next->next->data < a->next->data)
	{
		sa(stack);
		rra(stack);
	}
	if (a->data > a->next->data && a->data > a->next->next->data)
		ra(stack);
}

void	sort_4(t_stacks **stacka, t_stacks **stackb, t_data *nab)
{
	t_stacks	*a;

	a = *stacka;
	if (nab->nb == 0)
	{
		while (a->index != 0)
		{
			ra(stacka);
			a = *stacka;
		}
	}
	else
	{
		while (a->index != 1)
		{
			ra(stacka);
			a = *stacka;
		}
	}
	pb(stackb, stacka, nab);
	sort_3(stacka);
	pa(stacka, stackb, nab);
}

void	sort_5(t_stacks **stacka, t_stacks **stackb, t_data *nab)
{
	t_stacks	*a;

	a = *stacka;
	while (a->index != 0)
	{
		ra(stacka);
		a = *stacka;
	}
	pb(stackb, stacka, nab);
	sort_4(stacka, stackb, nab);
	pa(stacka, stackb, nab);
}

void	shortsort(t_stacks **a, t_stacks **b, t_data *nab)
{
	if (nab->na == 2)
		sa(a);
	if (nab->na == 3)
	{
		sort_3(a);
	}
	if (nab->na == 4)
		sort_4(a, b, nab);
	if (nab->na == 5)
		sort_5(a, b, nab);
}

void	sort(t_stacks **a, t_data *nab)
{
	t_stacks **b;

	b = (t_stacks **)malloc(sizeof(t_stacks));
	if(!b)
	{
		freemem(a, nab);
		exit(EXIT_FAILURE);
	}
	*b = NULL;
	if (nab->na <= 5)
		shortsort(a, b, nab);
	else
		sort_stack(a, b, nab);
	freeallstacks(a, b, nab);
}
