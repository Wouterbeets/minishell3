/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 16:21:53 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/07 14:34:56 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_llst	*llstnew(t_clst *clst)
{
	t_llst	*newlist;

	newlist = (t_llst *)malloc(sizeof(t_llst));
	if (newlist == NULL)
		return (NULL);
	if (clst == NULL)
		newlist->input = NULL;
	else
		newlist->input = clst;
	newlist->next = NULL;
	newlist->prev = NULL;
	return (newlist);
}

void	llstaddend(t_llst **alst, t_llst *new)
{
	t_llst	*tmp;

	tmp = *alst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	new->next = NULL;
}

t_llst	*llst_start(t_llst *hist)
{
	while (hist->prev)
		hist = hist->prev;
	return (hist);
}

void	llst_del_elem(t_llst **start, t_llst *hist)
{
	(void)start;
	hist->prev->next = hist->next;
	hist->next->prev = hist->prev;
	free(hist->input);
	free(hist);
}
