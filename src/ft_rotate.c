/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:04:07 by agouin            #+#    #+#             */
/*   Updated: 2025/05/20 16:04:08 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	*rotate(t_Noeud **a_debut)
{
	t_Noeud	*temp;
	t_Noeud	*p_actuel;

	if (*a_debut == NULL)
		return (0);
	temp = *a_debut;
	p_actuel = *a_debut;
	*a_debut = p_actuel->next;
	while (p_actuel->next != NULL && p_actuel)
		p_actuel = p_actuel->next;
	p_actuel->next = temp;
	temp->next = NULL;
	return (0);
}

void	*ft_rotate_a(t_Noeud **a_debut)
{
	rotate(a_debut);
	write(1, "ra\n", 3);
	return (0);
}
