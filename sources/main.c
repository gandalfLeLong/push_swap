/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:39:22 by cmathot           #+#    #+#             */
/*   Updated: 2024/02/14 15:32:36 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && av[1][0] == 0))
		return (1);
	ft_initialize_list(&a, ac, av);
	sorting_algorithm(&a, &b);
	ft_lstclear(&a);
	return (0);
}
