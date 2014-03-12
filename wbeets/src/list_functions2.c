/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 13:43:29 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/06 13:48:42 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	clstadd(t_clst **alst, t_clst *new)
{
	t_clst	*tmp;

	tmp = *alst;
	new->next = *alst;
	tmp->prev = new;
	*alst = new;
}

t_clst	*clstaddmid(t_clst *alst, t_clst *new)
{
	t_clst	*tmp;

	tmp = alst;
	new->next = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	return (new);
}

void	clstaddend(t_clst **alst, t_clst *new)
{
	t_clst	*tmp;

	tmp = *alst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

t_clst	*clstnew(char *str)
{
	t_clst	*newlist;

	newlist = (t_clst *)malloc(sizeof(t_clst));
	if (newlist == NULL)
		return (NULL);
	if (str == NULL)
		newlist->c = NULL;
	else
		newlist->c = ft_strdup(str);
	newlist->next = NULL;
	newlist->prev = NULL;
	return (newlist);
}

t_clst	*clst_cpy(t_clst *lst)
{
	t_clst	*tmp;
	t_clst	*start;

	tmp = clstnew(ft_strdup(lst->c));
	start = tmp;
	while (lst->next)
	{
		tmp->next = clstnew(ft_strdup(lst->next->c));
		tmp->next->prev = tmp;
		tmp = tmp->next;
		lst = lst->next;
	}
	tmp->next = NULL;
	tmp = start;
	while (lst->prev)
	{
		tmp->prev = clstnew(ft_strdup(lst->prev->c));
		tmp->prev->next = tmp;
		tmp = tmp->prev;
		lst = lst->prev;
	}
	tmp->prev = NULL;
	return (start);
}

