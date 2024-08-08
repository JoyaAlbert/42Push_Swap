/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:34:44 by ajoya-pi          #+#    #+#             */
/*   Updated: 2024/08/08 09:34:46 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "printf/ft_printf.h"
# include <limits.h>

typedef struct nodes
{
	int				data;
	int				index;
	struct nodes	*next;
}	t_stacks;

typedef struct data
{
	int	na;
	int	nb;
}	t_data;

//libft
long		ft_atoi(char *str);
int			ft_isdigit(int c);
char		*ft_strchr(const char *s, int c);
char		**ft_split(char const *s, char c);
int			ft_strlen(const char *str);
int			ft_strncmp(char *s1, char *s2, unsigned int n);

//utils
void		getdataarray(char *str, int argc);
void		datatake(t_stacks **a, int argc, char **argv, t_data *nab);
void		freematrix(char **args);
t_stacks	*minvalue(t_stacks **stack);
void		argscheck(char **argv);
void		numrep(char **argv, int argc);

//utils lists
void		ft_lstadd_back(t_stacks **lst, t_stacks *new);
t_stacks	*ft_lstnew(int content);
void		free_one_stack(t_stacks **stack);
void		freeallstacks(t_stacks **stacka, t_stacks **stackb, t_data *nab);
t_stacks	*last_element(t_stacks *list);
int			ft_lstsize(t_stacks **stack);
void		freemem(t_stacks **stacka, t_data *nab);

//moves
void		sb(t_stacks **stack);
void		sa(t_stacks **stack);
void		ss(t_stacks **a, t_stacks **b);
void		pa(t_stacks **a, t_stacks **b, t_data *nab);
void		pb(t_stacks **b, t_stacks **a, t_data *nab);
void		ra(t_stacks **a);
void		rb(t_stacks **a);
void		rr(t_stacks **a, t_stacks **b);
void		rra(t_stacks **a);
void		rrb(t_stacks **a);
void		rrr(t_stacks **a, t_stacks **b);

//sort
void		separated_inputs(char	**argv, int argc);
void		checkfirstarg(char **argv, int argc);
int			is_sorted(t_stacks **stack);
void		get_index(t_stacks **stack);
void		sort_stack(t_stacks **stack_a, t_stacks **stack_b, t_data *nab);
void		sort(t_stacks **stack_a, t_data *nab);

#endif
