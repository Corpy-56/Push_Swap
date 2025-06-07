/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:04:17 by agouin            #+#    #+#             */
/*   Updated: 2025/05/20 16:04:23 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*reverse_rotate(t_Noeud **a_debut)
{
	t_Noeud	*p_actuel;
	t_Noeud	*temp;

	if (*a_debut == NULL)
		return (0);
	p_actuel = *a_debut;
	temp = *a_debut;
	while (p_actuel->next != NULL)
		p_actuel = p_actuel->next;
	p_actuel->next = *a_debut;
	*a_debut = p_actuel;
	while (temp->next != p_actuel)
		temp = temp->next;
	temp->next = NULL;
	return (0);
}

void	*ft_reverse_rotate_a(t_Noeud **a_debut)
{
	reverse_rotate(a_debut);
	write(1, "rra\n", 4);
	return (0);
}

// t_Noeud	*ft_reverse_rotate_b(t_Noeud **b_debut)
// {
// 	t_Noeud	*temp;

// 	temp = reverse_rotate(b_debut);
// 	write(1, "rrb\n", 4);
// 	return (temp);
// }

// void	ft_reverse_rotate_a_b(t_Noeud *a_debut, t_Noeud *b_debut)
// {
// 	reverse_rotate(a_debut);
// 	reverse_rotate(b_debut);
// 	write(1, "rrr\n", 4);
// }