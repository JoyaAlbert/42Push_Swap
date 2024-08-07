#include "../pushswap.h"

void	numrep(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (((ft_atoi(argv[i]) == ft_atoi(argv[j])) && i != j)
				|| ft_atoi(argv[j]) > INT_MAX || ft_atoi(argv[j]) < INT_MIN
				|| (ft_strlen(argv[i]) == 2
					&& ft_strncmp(argv[i], "-0", 2) == 0))
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	freematrix(char **args)
{
	int	k;

	k = 0;
	while (args[k] != NULL)
		k++;
	while (k >= 0)
	{
		free(args[k]);
		k--;
	}
	free(args);
}

char	**getargs(char **argv)
{
	int		i;
	char	**args;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_strchr(argv[i], ' ') != NULL)
		{
			args = ft_split(argv[i], ' ');
			return (args);
		}
		i++;
	}
	return (argv);
}

void	argscheck(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (j == 0 && (argv[i][0] == '-' || argv[i][0] == '+'))
				j++;
			if (ft_isdigit((int)argv[i][j]) == 0)
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}
