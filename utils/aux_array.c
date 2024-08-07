#include "../pushswap.h"

void	leave_and_free(char **str)
{
	freematrix(str);
	exit(EXIT_FAILURE);
}

void	numreparray(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i] != NULL)
	{
		j = 0;
		while (args[j] != NULL)
		{
			if (((ft_atoi(args[i]) == ft_atoi(args[j])) && i != j)
				|| ft_atoi(args[j]) > INT_MAX || ft_atoi(args[j]) < INT_MIN
				|| (ft_strlen(args[i]) == 2 && ft_strncmp(args[i], "-0", 2) == 0))
			{
				write(2, "Error\n", 6);
				leave_and_free(args);
			}
			j++;
		}
		i++;
	}
}


void	checkarray(char **str)
{
	int i;
	int	j;

	i = 0;
	while (str[i] != NULL)
	{	
		j = 0;
		while (str[i][j] != '\0')
		{
			if (j == 0 && (str[i][0] == '-' || str[i][0] == '+'))
				j++;
			if (ft_isdigit((int)str[i][j]) == 0 || j > 11)
			{
				write(2, "Error\n", 6);
				leave_and_free(str);
			}
			j++;
		}
		i++;
	}
	if (i == 1)
		leave_and_free(str);
}

void	getdataarray(char *str, int argc)
{
	t_stacks	**a;
	t_data		*nab;
	char		**args;

	if (str[0] == '\0')
		return ;
	args = ft_split(str, ' ');
	checkarray(args);
	a = (t_stacks **)malloc(sizeof(t_stacks));
	nab = (t_data *)malloc(sizeof(t_data));
	if (!a || !nab)
		return ;
	datatake(a, argc, args, nab);
	numreparray(args);
	freematrix(args);
	get_index(a);
	nab->na = ft_lstsize(a);
	if (is_sorted(a) == 0)
	{
		freemem(a,nab);
		return ;
	}
	sort(a, nab);
}
