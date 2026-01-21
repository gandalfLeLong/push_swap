/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_instructions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:39:40 by cmathot           #+#    #+#             */
/*   Updated: 2023/12/19 16:56:07 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	reverse_rotate(t_list **lst)
{
	t_list	*last;

	if (!lst || !*lst || ft_lstsize(*lst) < 2)
		return ;
	last = ft_lst_last(*lst);
	last->prev->next = NULL;
	(*lst)->prev = last;
	last->next = *lst;
	last->prev = NULL;
	*lst = last;
}

void	rra(t_list **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
