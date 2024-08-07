#include "../pushswap.h"

int	ft_lstsize(t_stacks **stack)
{
	int			i;
	t_stacks	*aux;

	if (*stack == NULL)
		return (0);
	aux = *stack;
	i = 1;
	while (aux->next != NULL)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (const char)c)
		i++;
	if (s[i] == (const char)c)
		return ((char *)s + i);
	return (NULL);
}

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

void	freemem(t_stacks **stacka, t_data *nab)
{
	free_one_stack(stacka);
	free(nab);
}
