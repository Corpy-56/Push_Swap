/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:57:25 by agouin            #+#    #+#             */
/*   Updated: 2025/05/27 15:57:26 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_count_noeud(t_Noeud *a_debut)
{
	int		i;
	t_Noeud	*temp;

	i = 0;
	temp = a_debut;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	ft_index(t_Noeud *a_debut)
{
	t_Noeud			*p_actuel;
	t_Noeud			*temp;
	t_Noeud			*test;
	unsigned int	i;

	test = a_debut;
	while (test != NULL)
	{
		i = 0;
		temp = test;
		p_actuel = a_debut;
		while (p_actuel != NULL)
		{
			if (temp->nbr > p_actuel->nbr)
				i++;
			p_actuel = p_actuel->next;
		}
		temp->index = i;
		test = test->next;
	}
}

int	ft_grand(t_Noeud *a_debut)
{
	unsigned int	grand;
	t_Noeud			*temp;

	temp = a_debut;
	grand = a_debut->index;
	while (temp->next != NULL)
	{
		if (grand < temp->next->index)
			grand = temp->next->index;
		temp = temp->next;
	}
	return (grand);
}
