/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:34:16 by ajoya-pi          #+#    #+#             */
/*   Updated: 2024/08/08 09:34:18 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_stacks **dest, t_stacks **og)
{
	t_stacks	*aux;
	t_stacks	*point_dest;
	t_stacks	*point_og;

	if (ft_lstsize(og) == 0)
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

//first of a to b
void	pb(t_stacks **b, t_stacks **a, t_data *nab)
{
	push(b, a);
	nab->na--;
	nab->nb++;
	ft_printf("pb\n");
}

//first of b to a
void	pa(t_stacks **a, t_stacks **b, t_data *nab)
{
	push(a, b);
	nab->na++;
	nab->nb--;
	ft_printf("pa\n");
}
