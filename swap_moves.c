#include "pushswap.h"

void	swap(t_stacks **stack)
{
	t_stacks	*point;
	t_stacks	*next;
	int			aux;
	int			i_aux;

	point = *stack;
	next = point->next;
	if (point == NULL && next == NULL)
		exit(EXIT_FAILURE);
	aux = point->data;
	i_aux = point->index;
	point->index = next->index;
	point->data = next->data;
	next->data = aux;
	next->index = i_aux;
}

void	sb(t_stacks **stack)
{
	swap(stack);
	ft_printf("sb\n");
}

void	sa(t_stacks **stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	ss(t_stacks **a, t_stacks **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
