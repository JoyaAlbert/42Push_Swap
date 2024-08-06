#include "../pushswap.h"

void	ft_lstadd_back(t_stacks **lst, t_stacks *new)
{
	t_stacks	*aux;

	aux = *lst;
	if (lst == NULL )
	{
		free_one_stack(&new);
		exit(EXIT_FAILURE);
	}
	if (*lst == NULL)
		*lst = new;
	else
	{

		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new;
	}
	new->next = NULL;
}

t_stacks	*ft_lstnew(int content)
{
	t_stacks	*newnode;

	newnode = (t_stacks *)malloc(sizeof(t_stacks));
	if (!newnode)
		return (NULL);
	newnode->data = content;
	newnode->next = NULL;
	newnode->index = -1;
	return (newnode);
}

void	free_one_stack(t_stacks **stack)
{
	t_stacks	*point;
	t_stacks	*aux;

	point = *stack;
	while (point != NULL)
	{
		aux = point;
		point = point->next;
		free(aux);
	}
	free(stack);
}

t_stacks	*last_element(t_stacks *list)
{
	t_stacks	*aux;

	aux = list;
	while (aux->next != NULL)
		aux = aux->next;
	return (aux);
}

void	get_index(t_stacks **stack)
{
	t_stacks	*point;
	int			index;

	point = minvalue(stack);
	index = 0;
	while (point)
	{
		point->index = index++;
		point = minvalue(stack);
	}
}
