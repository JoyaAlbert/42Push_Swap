#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "printf/ft_printf.h"

typedef struct nodes
{
    int data;
	int	index;
    struct nodes *next;
} t_stacks;

typedef struct data
{
    int na;
    int nb;
} t_data;

//utils
int         ft_atoi(char *str);
int         ft_isdigit(int c);
t_stacks	*minvalue(t_stacks **stack);
void		argscheck(char **argv, int argc);
void		numrep(char **argv, int argc);

//utils lists
void        ft_lstadd_back(t_stacks **lst, t_stacks *new);
t_stacks    *ft_lstnew(int content);
void		free_one_stack(t_stacks **stack);
t_stacks	*last_element(t_stacks *list);
void		get_index(t_stacks **stack);
void		printlist(t_stacks **stack);
int	ft_lstsize(t_stacks *head);

//moves
void		sb(t_stacks **stack);
void		sa(t_stacks **stack);
void		ss(t_stacks **a, t_stacks **b);
void 		pa(t_stacks **a, t_stacks **b, t_data *nab);
void		pb(t_stacks **b, t_stacks **a, t_data *nab);
void		ra(t_stacks **a);
void		rb(t_stacks **a);
void		rr(t_stacks **a, t_stacks **b);
void		rra(t_stacks **a);
void		rrb(t_stacks **a);
void		rrr(t_stacks **a, t_stacks **b);

//short sort
void		shortsort(t_stacks **a, t_stacks **b, t_data *nab);
#endif