/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:49:31 by agouin            #+#    #+#             */
/*   Updated: 2025/05/15 14:58:25 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (1);
}

int	print_error_int_max(char *argv, int i, int j)
{
	char	*test;
	int		k;

	test = 0;
	k = 0;
	j = ft_atoi(argv);
	test = ft_itoa(j);
	if (argv[0] == '+')
			i++;
	while (argv[i] == '0' && argv[i] != '\0')
		i++;
	while (argv[i] != '\0')
	{
		if (argv[i] != test[k])
		{
			free(test);
			return (1);
		}
		i++;
		k++;
	}
	free(test);
	return (0);
}

int	print_error_number(char *argv)
{
	int	j;

	j = 0;
	if ((argv[j] == '-' || argv[j] == '+') && argv[j + 1] != '\0')
		j++;
	else if (!(argv[j] >= '0' && argv[j] <= '9'))
		return (1);
	while (argv[j] != '\0' && argv[j] >= '0' && argv[j] <= '9')
		j++;
	if (argv[j] != '\0')
		return (1);
	return (0);
}

int	print_error_doublon(int argc, char **argv, int k, int j)
{
	int	i;

	i = 0;
	k = 1;
	if (argc == 2)
		k = 0;
	while (argv[i] != NULL)
		i++;
	while (k < i)
	{
		j = k + 1;
		while (j < i)
		{
			if (ft_atoi(argv[k]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		k++;
	}
	return (0);
}

int	check_error(char **argv, int argc)
{
	int	i;
	int	total;
	int	test;

	i = 0;
	total = 0;
	test = 0;
	if (argc > 2)
		i++;
	while (argv[i] != NULL)
	{
		if ((print_error_number(argv[i]) == 1
				|| (print_error_int_max(argv[i], total, test) == 1))
			|| (print_error_doublon(argc, argv, test, total) == 1))
			return (ft_free2(argc, argv));
		i++;
	}
	if (argc == 2)
		ft_free1(argv);
	return (0);
}
