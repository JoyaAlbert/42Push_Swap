/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 10:02:52 by ajoya-pi          #+#    #+#             */
/*   Updated: 2024/08/08 10:02:54 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				error_and_ext();
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

void	checkfirstarg(char **argv, int argc)
{
	int	i;
	int	c;
	int	z;

	z = ft_strlen(argv[1]) - 1;
	c = 0;
	i = 0;
	while (z > 0 && (argv[1][z] == ' ' || argv[1][z] == 't'))
		z--;
	while (argv[1][i] != '\0' && (argv[1][i] == ' ' || argv[1][i] == 't'))
		i++;
	while (argv[1][i] != '\0' && i < z)
	{
		if (argv[1][i] == ' ' || argv[1][i] == '\t')
			c++;
		i++;
	}
	if (c >= 1)
		error_and_ext();
	else
		separated_inputs(argv, argc);
}

void	argscheck(char **argv)
{
	int	i;
	int	j;
	int	z;

	i = 1;
	while (argv[i] != NULL)
	{
		z = ft_strlen(argv[i]) - 1;
		while (z > 0 && (argv[i][z] == ' ' || argv[i][z] == 't'))
			z--;
		j = 0;
		while (argv[i][j] != '\0' && (argv[i][j] == ' ' || argv[i][j] == 't'))
			j++;
		while (argv[i][j] != '\0')
		{
			if (j == 0 && (argv[i][0] == '-' || argv[i][0] == '+'))
				j++;
			if (ft_isdigit((int)argv[i][j]) == 0 && j <= z)
				error_and_ext();
			j++;
		}
		i++;
	}
}
