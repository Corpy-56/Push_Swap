/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:59:57 by agouin            #+#    #+#             */
/*   Updated: 2025/05/15 19:00:15 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_swap(t_Noeud **a_debut)
{
	t_Noeud	*temp;
	t_Noeud	*p_actuel;

	if (a_debut == NULL)
		return (0);
	temp = *a_debut;
	p_actuel = temp->next;
	temp->next = p_actuel->next;
	p_actuel->next = temp;
	*a_debut = p_actuel;
	return (0);
}

void	*ft_swap_a(t_Noeud **a_debut)
{
	ft_swap(a_debut);
	write(1, "sa\n", 3);
	return (0);
}

void	*ft_swap_b(t_Noeud **b_debut)
{
	ft_swap(b_debut);
	write(1, "sb\n", 3);
	return (0);
}

// void	ft_swap_a_b(t_Noeud *a_debut, Noeud *b_debut)
// {
// 	ft_swap(a_debut);
// 	ft_swap(b_debut);
// 	write(1, "ss\n", 3);
// }