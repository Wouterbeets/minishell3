/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 18:56:36 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/07 14:44:20 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_tab(char **arr)
{
	int		i;

	i = 0;
	while (arr[i] != '\0')
		ft_putendl(arr[i++]);
}

void	printlist(t_clst *lst)
{
	t_clst *tmp;

	tmp = lst;
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		ft_putstr(tmp->c);
		tmp = tmp->next;
	}
}

int		tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

