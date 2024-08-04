#include "../pushswap.h"

void	numrep(char **argv, int argc)
{
	int i;
	int	j;

	i = 1;
	while(i<argc)
	{
		j = 1;
		while(j < argc)
		{
			if(ft_atoi(argv[i]) == ft_atoi(argv[j]) && i != j)
			{
				perror("Error\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void argscheck(char **argv, int argc)
{
	int i;
	int j;

	i = 1;
	if (argc < 3)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if(j == 0 && (argv[i][0] == '-' || argv[i][0] == '+'))
				j++;
			if(ft_isdigit((int)argv[i][j]) == 0)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}