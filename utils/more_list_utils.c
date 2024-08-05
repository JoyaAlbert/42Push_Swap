#include "../pushswap.h"

int	ft_lstsize(t_stacks *stack)
{
	int			i;
	t_stacks	*aux;

	aux = stack;
	i = 0;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}
/**
void printlist(t_stacks **stack) 
{
	if (stack == NULL || *stack == NULL) 
	{
		printf("La lista está vacía.\n");
		return;
	}

	t_stacks *actual = *stack;
	while (actual != NULL) 
	{
		printf("Data: %d   Index: %d\n", actual->data, actual->index);
		actual = actual->next;
	}
}*/

t_stacks	*minvalue(t_stacks **stack)
{
	t_stacks	*start;
	t_stacks	*min;
	int			flag;

	start = *stack;
	min = NULL;
	flag = 0;
	if (start)
	{
		while (start)
		{
			if (start->index == -1 && (!flag || start->data < min->data))
			{
				min = start;
				flag = 1;
			}
			start = start->next;
		}
	}
	return (min);
}
