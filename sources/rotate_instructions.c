/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:45:02 by cmathot           #+#    #+#             */
/*   Updated: 2023/12/19 16:44:01 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*last;

	if (!lst || !*lst || ft_lstsize(*lst) < 2)
		return ;
	tmp = *lst;
	last = ft_lst_last(*lst);
	*lst = (*lst)->next;
	(*lst)->prev = NULL;
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
}

void	ra(t_list **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
