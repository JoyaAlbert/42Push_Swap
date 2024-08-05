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

void	freestacks(t_stacks **stacka, t_stacks **stackb, t_data *nab)
{
	free_one_stack(stacka);
	free_one_stack(stackb);
	free(nab);
}

void	datatake(t_stacks **a, int argc, char **argv, t_data *nab)
{
	int			i;
	t_stacks	*new;

	i = 1;
	while (argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(a, new);
		i++;
	}
	nab->na = argc -1;
	nab->nb = 0;
}

void	sort_stack(t_stacks **stack_a, t_stacks **stack_b, t_data *nab)
{
	int	i;
	int	j;
	int	stack_size;

	i = 0;
	stack_size = ft_lstsize(*stack_a);
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
	t_stacks	**a;
	t_stacks	**b;
	t_data		*nab;

	if (argc >= 3)
	{
		argscheck(argv);
		numrep(argv, argc);
		a = (t_stacks **)malloc(sizeof(t_stacks));
		b = (t_stacks **)malloc(sizeof(t_stacks));
		nab = (t_data *)malloc(sizeof(t_data));
		if (!a || !b || !nab)
			return (0);
		datatake(a, argc, argv, nab);
		get_index(a);
		if (is_sorted(a) == 0)
		{
			freestacks(a, b, nab);
			return (0);
		}
		if (nab->na <= 5)
			shortsort(a, b, nab);
		sort_stack(a, b, nab);
		freestacks(a, b, nab);
	}
}
