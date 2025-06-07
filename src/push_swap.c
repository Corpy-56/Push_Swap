
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:55:15 by agouin            #+#    #+#             */
/*   Updated: 2025/05/15 18:55:16 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_Noeud	*clear_noeud(t_Noeud *a_debut)
{
	t_Noeud	*test;

	if (a_debut == NULL)
		return (NULL);
	test = a_debut->next;
	free(a_debut);
	return (clear_noeud(test));
}

int	main(int argc, char **argv)
{
	t_Noeud	*a;
	t_Noeud	*b;
	char	**temp;

	temp = NULL;
	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	if (argc == 2)
	{
		temp = ft_split(argv[1], ' ');
		if (temp == NULL)
			return (0);
	}
	else
		temp = argv;
	if (check_error(temp, argc) == 6)
		return (0);
	a = ft_initialization(argc, argv, a);
	ft_index(a);
	a = ft_fonction_tri(a, b);
	a = clear_noeud(a);
	b = clear_noeud(b);
	return (0);
}
