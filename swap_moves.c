#include "pushswap.h"

void sa(t_stacks **stack)
{
	t_stacks	*point;
	t_stacks	*next;
	int			aux;

	point = *stack;
	next = point->next;
	if(point == NULL && next == NULL)
		exit(EXIT_FAILURE);
	aux = point->data;
	point->data = next->data;
	next->data = aux;
	ft_printf("sa");
}
void sb(t_stacks **stack)
{
	t_stacks	*point;
	t_stacks	*next;
	int			aux;

	point = *stack;
	next = point->next;
	if(point == NULL && next == NULL)
		exit(EXIT_FAILURE);
	aux = point->data;
	point->data = next->data;
	next->data = aux;
	ft_printf("sa");
}
void	ss(t_stacks **a, t_stacks **b)
{
	t_stacks	*point;
	t_stacks	*next;
	int			aux;

	point = *a;
	next = point->next;
	if(point == NULL && next == NULL)
		exit(EXIT_FAILURE);
	aux = point->data;
	point->data = next->data;
	next->data = aux;
	point = *b;
	next = point->next;
	if(point == NULL && next == NULL)
		exit(EXIT_FAILURE);
	aux = point->data;
	point->data = next->data;
	next->data = aux;
	ft_printf("ss");
}

void pa(t_stacks **a, t_stacks **b, t_data *nab)
{
	t_stacks	*aux;
	t_stacks	*point_a;
	t_stacks	*point_b;

	if (nab->nb != 0)
    {
		point_a = *a;
		point_b = *b;
		aux = point_b;
		point_b = point_b->next;
		if(nab->na == 0)
		{
			point_a = aux;
			point_a->next = NULL;
			*a = point_a;
		}
		else
		{
			aux->next = point_a;
			*a = aux;
		}
		nab->na++;
		nab->nb--;
	}
	ft_printf("pa");
}

void pb(t_stacks **b, t_stacks **a, t_data *nab)
{
	t_stacks	*aux;
	t_stacks	*point_a;
	t_stacks	*point_b;

	if (nab->na != 0)
    {
		point_b = *b;
		point_a = *a;
		aux = point_a;
		point_a = point_a->next;
		if(nab->nb == 0)
		{
			point_b = aux;
			point_a->next = NULL;
			*b = point_b;
		}
		else
		{
			aux->next = point_b;
			*b = aux;
		}
		nab->nb++;
		nab->na--;
	}
	ft_printf("pb");
}
