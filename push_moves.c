#include "pushswap.h"
/*
	USO UN PUNTERO AUXILIAR Q SE IGUALA AL DE ORIGEN
	SI EL DESTINO ESTA VACIO LO IGUALO Y LO IGUALO AL STACK DE DESTINO
	SI NO AÑADO JUSTO DESPUES DEL PRIMERO EN EL AUXILIAR TODO EL DESTINO
*/
//SACA EL PRIMERO Y LO METE EN EL OTRO STACK
void	push(t_stacks **dest, t_stacks **og)
{
	t_stacks	*aux;
	t_stacks	*point_dest;
	t_stacks	*point_og;

	if (ft_lstsize(*og) == 0)
		return ;
	point_dest = *dest;
	point_og = *og;
	aux = point_og;
	point_og = point_og->next;
	*og = point_og;
	if (point_dest == NULL)
	{
		point_dest = aux;
		point_dest->next = NULL;
		*dest = point_dest;
	}
	else
	{
		aux->next = point_dest;
		*dest = aux;
	}
	return ;
}

void	pb(t_stacks **b, t_stacks **a, t_data *nab)
{
	push(b, a);
	nab->na = ft_lstsize(*a);
	nab->nb = ft_lstsize(*b);
	ft_printf("pb\n");
}

void	pa(t_stacks **a, t_stacks **b, t_data *nab)
{
	push(a, b);
	nab->na = ft_lstsize(*a);
	nab->nb = ft_lstsize(*b);
	ft_printf("pa\n");
}
