/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:42:57 by cmathot           #+#    #+#             */
/*   Updated: 2024/02/21 13:56:55 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

/*------------LES INCLUDES------------------*/

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*------------STRUCTURES---------------------*/

typedef struct s_list
{
	int				nbr;
	int				cost;
	int				up_mid;
	int				cheapest;
	size_t			pos;

	struct s_list	*target;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

/*------------DECLA DES FONCTIONS------------*/

//parsing.c
int		ft_numbers_only(int ac, char **av);
void	ft_initialize_list(t_list **lst, int ac, char **av);
void	ft_free_tab(char **tab);
char	*ft_arg_join(int ac, char **av);
char	**ft_parsing(int ac, char **av);

//list_utils.c
void	ft_no_duplicates(t_list **lst);
void	ft_lst_add_back(t_list **head, t_list *new_node);
void	ft_lstclear(t_list **head);
t_list	*ft_lst_new(t_list *lst, char *str);
t_list	*ft_lst_last(t_list *lst);

//list_utils_2.c
int		list_is_not_sorted(t_list *lst);
size_t	ft_lstsize(t_list *lst);
t_list	*find_biggest_node(t_list *lst);
t_list	*find_smallest_node(t_list *lst);

//swap_instructions.c
void	swap(t_list **lst);
void	sa(t_list **lst);
void	sb(t_list **lst);
void	ss(t_list **lst_1, t_list **lst_2);

//push_instructions.c
void	push(t_list **dst, t_list **src);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);

//rotate_instructions.c
void	rotate(t_list **lst);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);

//reverse_rotate_instructions.c
void	reverse_rotate(t_list **lst);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

//sorting_algorithm
void	sorting_algorithm(t_list **a, t_list **b);
void	minisort(t_list **lst);
void	bigsort(t_list **a, t_list **b);
void	rotate_lists(t_list **a, t_list **b);
void	finish_rotation(t_list **a, t_list **b);

//sorting_algorithm_2
void	initialize_nodes(t_list *a, t_list *b);
void	set_positions(t_list *a, t_list *b);
void	set_median(t_list *a, t_list *b);
void	set_target(t_list *a, t_list *b);
void	set_cost(t_list *a, t_list *b);

//sorting_algorithm_3
void	set_cheapest(t_list *b);
t_list	*find_cheapest(t_list *b);
#endif
