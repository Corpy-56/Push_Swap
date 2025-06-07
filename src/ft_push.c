/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:02:45 by agouin            #+#    #+#             */
/*   Updated: 2025/05/20 16:02:47 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_push(t_Noeud **a_debut, t_Noeud **b_debut)
{
	t_Noeud	*temp;

	if (*b_debut == NULL)
		return (NULL);
	temp = *b_debut;
	*b_debut = temp->next;
	if (*a_debut == NULL)
		temp->next = NULL;
	else
		temp->next = *a_debut;
	*a_debut = temp;
	return (0);
}

void	ft_push_a(t_Noeud **a_debut, t_Noeud **b_debut)
{
	ft_push(a_debut, b_debut);
	write(1, "pa\n", 3);
}

void	ft_push_b(t_Noeud **b_debut, t_Noeud **a_debut)
{
	ft_push(b_debut, a_debut);
	write(1, "pb\n", 3);
}
