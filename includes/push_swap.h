
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:55:05 by agouin            #+#    #+#             */
/*   Updated: 2025/05/15 18:55:06 by agouin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct Noeud
{
	int				nbr;
	unsigned int	index;
	struct Noeud	*next;
}t_Noeud;

char	**ft_split(char const *s, char c);
int		check_error(char **argv, int argc);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
t_Noeud	*ft_initialization(int argc, char **argv, t_Noeud *a_debut);
void	ft_free1(char **temp);
int		ft_free2(int argc, char **temp);

//fonction swap

void	*ft_swap_a(t_Noeud **a_debut);
void	*ft_swap_b(t_Noeud **b_debut);
void	ft_swap_a_b(t_Noeud *a_debut, t_Noeud *b_debut);

// fonction rotate

void	*ft_rotate_a(t_Noeud **a_debut);
void	*ft_rotate_b(t_Noeud **b_debut);
void	ft_rotate_a_b(t_Noeud *a_debut, t_Noeud *b_debut);

// fonction push

void	ft_push_a(t_Noeud **a_debut, t_Noeud **b_debut);
void	ft_push_b(t_Noeud **b_debut, t_Noeud **a_debut);

// fonction reverse_rotate

void	*ft_reverse_rotate_a(t_Noeud **a_debut);
void	*ft_reverse_rotate_b(t_Noeud **b_debut);
void	ft_reverse_rotate_a_b(t_Noeud *a_debut, t_Noeud *b_debut);

// fonction tri

int		ft_grand(t_Noeud *a_debut);
void	ft_index(t_Noeud *a_debut);
int		ft_count_noeud(t_Noeud *a_debut);
t_Noeud	*ft_fonction_tri(t_Noeud *a_debut, t_Noeud *b_debut);
t_Noeud	*fonction_radix(t_Noeud *a_debut, t_Noeud *b_debut, int i);
int		test_index(t_Noeud *a_debut);
t_Noeud	*fonction_5(t_Noeud *a_debut, t_Noeud *b_debut, int i);
t_Noeud	*fonction_3(t_Noeud *a_debut, int i);
t_Noeud	*clear_noeud(t_Noeud *a_debut);

#endif
