/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:34:25 by ajoya-pi          #+#    #+#             */
/*   Updated: 2024/08/08 09:34:28 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(t_stacks **stack)
{
	t_stacks	*point;

	point = *stack;
	if (point == NULL)
		return (0);
	while (point->next != NULL)
	{
		if (point->data > point->next->data)
			return (-1);
		point = point->next;
	}
	return (0);
}

void	freeallstacks(t_stacks **stacka, t_stacks **stackb, t_data *nab)
{
	free_one_stack(stacka);
	free_one_stack(stackb);
	free(nab);
}

void	datatake(t_stacks **a, int argc, char **argv, t_data *nab)
{
	int			i;
	t_stacks	*new;

	if (argc != 2)
		i = 1;
	else
		i = 0;
	*a = NULL;
	while (argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(a, new);
		i++;
	}
	nab->na = ft_lstsize(a);
	nab->nb = 0;
}

void	sort_stack(t_stacks **stack_a, t_stacks **stack_b, t_data *nab)
{
	int	i;
	int	j;
	int	stack_size;

	i = 0;
	stack_size = ft_lstsize(stack_a);
	while (is_sorted(stack_a) == -1)
	{
		j = 0;
		while (*stack_a && j < stack_size && is_sorted(stack_a) == -1)
		{
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_b, stack_a, nab);
			j++;
		}
		i++;
		while (*stack_b)
			pa(stack_a, stack_b, nab);
	}
}

int	main(int argc, char **argv)
{
	if (argc >= 3 && ft_strchr(argv[1], ' ') == NULL)
		separated_inputs(argv, argc);
	else if (argc == 2)
		getdataarray(argv[1], argc);
	else if (argc >= 3 && ft_strchr(argv[1], ' ') != NULL)
		checkfirstarg(argv, argc);
}
