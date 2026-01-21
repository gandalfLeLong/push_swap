/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmathot <cmathot@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:25:49 by cmathot           #+#    #+#             */
/*   Updated: 2024/02/29 12:46:52 by cmathot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_initialize_list(t_list **lst, int ac, char **av)
{
	int		i;
	char	**split;
	t_list	*new;

	split = ft_parsing(ac, av);
	i = 0;
	while (split[i])
	{
		new = ft_lst_new(*lst, split[i]);
		if (!new)
		{
			write(2, "Error\n", 6);
			ft_lstclear(lst);
			ft_free_tab(split);
			exit(1);
		}
		ft_lst_add_back(lst, new);
		i++;
	}
	ft_free_tab(split);
	ft_no_duplicates(lst);
}

char	**ft_parsing(int ac, char **av)
{
	char	*buffer;
	char	**tab;

	if (ft_numbers_only(ac, av))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	buffer = ft_arg_join(ac, av);
	if (!buffer)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	tab = ft_split(buffer, ' ');
	free(buffer);
	if (!tab)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (tab);
}

char	*ft_arg_join(int ac, char **av)
{
	int		i;
	char	*buffer;

	i = 1;
	buffer = NULL;
	while (i < ac)
	{
		buffer = ft_strjoin(buffer, av[i]);
		buffer = ft_strjoin(buffer, " ");
		i++;
	}
	return (buffer);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	ft_numbers_only(int ac, char **av)
{
	int	i;
	int	j;
	int	flag_num;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			flag_num = 0;
			if (av[i][j] < '0' || av[i][j] > '9') 
			{
				if (av[i][j] != ' ' && av[i][j] != '-')
					return (1);
			}
			else
				flag_num = 1;
			j++;
		}
		if (flag_num == 0)
			return (1);
		i++;
	}
	return (0);
}
