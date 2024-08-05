#include "pushswap.h"

void	ra(t_stacks **a)
{
	t_stacks	*p_start;
	t_stacks	*p_end;

	p_start = *a;
	p_end = last_element(p_start);
	*a = p_start->next;
	p_start->next = NULL;
	p_end->next = p_start;
	ft_printf("ra\n");
}

void	rb(t_stacks **b)
{
	t_stacks	*p_start;
	t_stacks	*p_end;

	p_start = *b;
	p_end = last_element(p_start);
	*b = p_start->next;
	p_start->next = NULL;
	p_end->next = p_start;
	ft_printf("rb\n");
}

void	rr(t_stacks **a, t_stacks **b)
{
	t_stacks	*p_start;
	t_stacks	*p_end;

	p_start = *a;
	p_end = last_element(p_start);
	*a = p_start->next;
	p_start->next = NULL;
	p_end->next = p_start;
	p_start = *b;
	p_end = last_element(p_start);
	*b = p_start->next;
	p_start->next = NULL;
	p_end->next = p_start;
	ft_printf("rr\n");
}
