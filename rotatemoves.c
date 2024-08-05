#include "pushswap.h"

/*IGUALO UN PUNTERO A LA LISTA Y OTRO AL ULTIMO ELEMENTO DE LA LISTA
MUEVO TODO UNA POSICION QUITANDO LA PRIMERA POSICION
EN P_START SOLO ESTA EL PRIMER NODO Y EL NEXT ES NULL 
ASI QUE LO PONEMOS AL FINAL DEL ULTIMO NODO */
//FIRST TO LAST
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
