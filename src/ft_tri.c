/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:55:02 by agouin            #+#    #+#             */
/*   Updated: 2025/05/27 15:55:04 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_Noeud	*fonction_3(t_Noeud *a_debut, int i)
{
	unsigned int	grand;

	if (i == 1)
		return (a_debut);
	if (i == 2)
	{
		if (a_debut->index > a_debut->next->index)
			ft_swap_a(&a_debut);
		return (a_debut);
	}
	grand = ft_grand(a_debut);
	if (a_debut->index == grand)
		ft_rotate_a(&a_debut);
	else if (a_debut->next->index == grand)
		ft_reverse_rotate_a(&a_debut);
	if (a_debut->index > a_debut->next->index)
		ft_swap_a(&a_debut);
	return (a_debut);
}

t_Noeud	*fonction_5(t_Noeud *a_debut, t_Noeud *b_debut, int i)
{
	t_Noeud	*temp;

	temp = a_debut;
	if (test_index(a_debut) == 0)
		return (a_debut);
	while (i > 0)
	{
		if (a_debut->index == 0 || a_debut->index == 1)
			ft_push_b(&b_debut, &a_debut);
		else
			ft_rotate_a(&a_debut);
		i--;
	}
	i = 4;
	a_debut = fonction_3(a_debut, i);
	ft_push_a(&a_debut, &b_debut);
	ft_push_a(&a_debut, &b_debut);
	if (a_debut->index > a_debut->next->index)
		ft_swap_a(&a_debut);
	return (a_debut);
}

int	test_index(t_Noeud *a_debut)
{
	t_Noeud	*temp;

	temp = a_debut;
	if (a_debut == NULL)
		return (0);
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->index > temp->next->index)
			return (1);
		temp = temp->next;
	}
	return (0);
}

t_Noeud	*fonction_radix(t_Noeud *a_debut, t_Noeud *b_debut, int i)
{
	int	j;
	int	k;
	int	l;

	j = 0;
	l = i;
	while (test_index(a_debut) == 1 && a_debut != NULL)
	{
		i = l;
		k = 0;
		while (i > 0)
		{
			k = (a_debut->index >> j) & 1;
			if (k == 1)
				ft_rotate_a(&a_debut);
			else if (k == 0)
				ft_push_b(&b_debut, &a_debut);
			i--;
		}
		while (b_debut != NULL)
			ft_push_a(&a_debut, &b_debut);
		j++;
	}
	return (a_debut);
}

t_Noeud	*ft_fonction_tri(t_Noeud *a_debut, t_Noeud *b_debut)
{
	int	i;

	i = ft_count_noeud(a_debut);
	if (i <= 3)
		a_debut = fonction_3(a_debut, i);
	else if (i <= 5)
		a_debut = fonction_5(a_debut, b_debut, i);
	else if (i > 5)
		a_debut = fonction_radix(a_debut, b_debut, i);
	return (a_debut);
}
