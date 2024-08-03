#include "../pushswap.h"

void ft_lstadd_back(t_stacks **lst, t_stacks *new) 
{
	t_stacks *aux;

    if (lst == NULL )
        exit(EXIT_FAILURE);
    if (*lst == NULL) 
        *lst = new;
    else 
	{
        aux = *lst;
        while (aux->next != NULL)
            aux = aux->next;
        aux->next = new;
    }
    new->next = NULL;
}

t_stacks *ft_lstnew(int content)
{
	t_stacks	*newnode;

	newnode = (t_stacks *)malloc(sizeof(t_stacks));
	if (!newnode)
		return (NULL);
	newnode->data = content;
	newnode->next = NULL;
	return (newnode);
}

void    free_one_stack(t_stacks **stack)
{
	t_stacks *point;
	t_stacks *aux;

	point = *stack;
	while(point != NULL)
	{
		aux = point;
		point = point->next;
		free(aux);
	}
	free(stack);
}

t_stacks	*last_element(t_stacks *list)
{
	t_stacks *aux;

	aux = list;
	while(aux->next != NULL)
		aux = aux->next;
	return (aux);
}