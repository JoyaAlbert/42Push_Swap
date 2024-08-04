#include "pushswap.h"

int is_sorted(t_stacks **stack)
{
	t_stacks *point;

	point = *stack;
	if(point == NULL)
		return (0);
	while(point->next != NULL)
	{
		if (point->data > point->next->data)
			return -1;
		point = point->next;
	}
	return 0;
}

void freestacks(t_stacks **stacka, t_stacks **stackb, t_data *nab)
{
	free_one_stack(stacka);
	free_one_stack(stackb);
	free(nab);
}
void datatake(t_stacks **a, int argc, char **argv, t_data *nab)
{
	int i;
	t_stacks *new;

	i = 1;
	while(argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(a, new);
		i++;
	}
	nab->na = argc -1;
	nab->nb = 0;
}

int main(int argc, char **argv)
{
	t_stacks	**a;
	t_stacks	**b;
	t_data		*nab;

	argscheck(argv, argc);
	numrep(argv, argc);
	a = (t_stacks **)malloc(sizeof(t_stacks));
	b = (t_stacks **)malloc(sizeof(t_stacks));
	nab = (t_data *)malloc(sizeof(t_data));
	if(!a || !b || !nab)
		return (0);
	datatake(a, argc, argv, nab);
	get_index(a);
	if(is_sorted(a) == 0)
	{
		freestacks(a, b, nab);
		return (0);
	}
	if(nab->na <= 5)
		shortsort(a, b, nab);
	printlist(a);
	freestacks(a, b, nab);
}
