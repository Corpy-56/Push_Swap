/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:03:35 by agouin            #+#    #+#             */
/*   Updated: 2025/05/20 16:03:37 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_free1(char **temp)
{
	int	i;

	i = 0;
	while (temp[i] != NULL)
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

int	ft_free2(int argc, char **temp)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (temp[i] != NULL)
		{
			free(temp[i]);
			i++;
		}
		free(temp);
	}
	return (write(1, "Error\n", 6));
}

t_Noeud	*new(char **temp, t_Noeud *p_actuel, t_Noeud *fin, t_Noeud *a_debut)
{
	int	i;

	i = 0;
	while (temp[i] != NULL)
	{
		p_actuel = malloc(sizeof(t_Noeud));
		if (p_actuel == NULL)
			return (NULL);
		p_actuel->nbr = ft_atoi(temp[i]);
		p_actuel->index = i;
		p_actuel->next = NULL;
		if (a_debut == NULL)
		{
			a_debut = p_actuel;
			fin = p_actuel;
		}
		else
		{
			fin->next = p_actuel;
			fin = p_actuel;
		}
		i++;
	}
	return (a_debut);
}

t_Noeud	*ft_initialization(int argc, char **argv, t_Noeud *a_debut)
{
	t_Noeud	*p_actuel;
	t_Noeud	*fin;
	char	**temp;

	p_actuel = NULL;
	fin = NULL;
	temp = NULL;
	if (argc == 2)
	{
		temp = ft_split(argv[1], ' ');
		if (temp == NULL)
			return (0);
	}
	else
		temp = &argv[1];
	if (temp[0] != NULL)
		a_debut = new(temp, p_actuel, fin, a_debut);
	p_actuel = a_debut;
	if (argc == 2 && temp != NULL)
		ft_free1(temp);
	return (a_debut);
}
