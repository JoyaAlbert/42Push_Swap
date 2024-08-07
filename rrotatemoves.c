/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotatemoves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:35:00 by ajoya-pi          #+#    #+#             */
/*   Updated: 2024/08/08 09:35:02 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//   LAST TO FIRST
void	rotate(t_stacks **stack)
{
	t_stacks	*p_start;
	t_stacks	*p_end;

	p_start = *stack;
	p_end = last_element(p_start);
	while (p_start != NULL)
	{
		if (p_start->next->next == NULL)
		{
			p_start->next = NULL;
			break ;
		}
		p_start = p_start->next;
	}
	p_end->next = *stack;
	*stack = p_end;
}

void	rra(t_stacks **a)
{
	rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stacks **b)
{
	rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stacks **a, t_stacks **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rrr\n");
}
