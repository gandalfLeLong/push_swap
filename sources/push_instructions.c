/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:46:04 by cmathot           #+#    #+#             */
/*   Updated: 2023/12/19 18:49:58 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_list **dst, t_list **src)
{
	t_list	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (!*dst)
	{
		*dst = tmp;
		(*dst)->next = NULL;
	}
	else
	{
		tmp->next = *dst;
		(*dst)->prev = tmp;
		*dst = tmp;
	}
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_list **b, t_list **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
