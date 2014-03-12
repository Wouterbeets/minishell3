/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 14:04:18 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/07 17:54:23 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	clst_del(t_clst *elem)
{
	t_clst	*tmp;

	tmp = clst_start(elem);
	while (tmp)
	{
		elem = tmp->next;
		free(tmp->c);
		free(tmp);
		tmp = elem;
	}
}

t_clst	*clst_start(t_clst *elem)
{
	while (elem->prev)
		elem = elem->prev;
	return (elem);
}

int		clst_len(t_clst *lst)
{
	t_clst	*tmp;
	int		i;

	i = 0;
	tmp = clst_start(lst);
	while (tmp)
	{
		i += ft_strlen(tmp->c);
		tmp = tmp->next;
	}
	return (i);
}

t_clst	*clst_del_elem(t_clst *input)
{
	t_clst	*prev_node;
	t_clst	*next_node;

	prev_node = input->prev;
	next_node = input->next;
	if (input->prev && input->next)
	{
		next_node->prev = input->prev;
		prev_node->next = input->next;
		free(input->c);
		free(input);
		input = NULL;
		return (prev_node);
	}
	else if (prev_node)
	{
		prev_node->next = NULL;
		free(input->c);
		free(input);
		return (prev_node);
	}
	return (input);
}
