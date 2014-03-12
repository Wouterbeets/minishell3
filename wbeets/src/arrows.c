/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 15:40:22 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/07 14:33:23 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_llst	*up(t_llst *hist, struct winsize *winsize)
{
	if (hist->prev)
	{
		clst_del(hist->input);
		hist->input = clst_cpy(hist->prev->input);
		if (hist->next == NULL)
		{
			hist->next = llstnew(clstnew(BASE));
			hist->next->prev = hist->prev;
			hist->prev->next = hist->next;
			hist->prev = hist->prev->prev;
		}
		else
		{
			hist->next = hist->next->prev;
			hist->prev = hist->prev->prev;
		}
		hist->is = 1;
	}
	start_line(hist, winsize);
	printlist(hist->input);
	return (hist);
}

t_llst	*down(t_llst *hist, struct winsize *winsize)
{
	if (hist->next)
	{
		if (hist->is)
			clst_del(hist->input);
		if (hist->next->prev->prev == NULL)
		{
			hist->input = clst_cpy(hist->next->input);
			hist->prev = hist->next->prev;
			hist->next = hist->next->next;
		}
		else if (hist->prev->next->next)
		{
			hist->input = clst_cpy(hist->next->input);
			hist->next = hist->next->next;
			hist->prev = hist->prev->next;
		}
	}
	start_line(hist, winsize);
	printlist(hist->input);
	return (hist);
}

t_llst	*left(t_llst *hist)
{
	t_clst *tmp;

	tmp = hist->input->prev;
	if (tmp)
	{
		hist->input = hist->input->prev;
		tputs(tgetstr("le", NULL), 1, tputs_putchar);
	}
	return (hist);
}

t_llst	*right(t_llst *hist)
{
	if (hist->input->next)
	{
		hist->input = hist->input->next;
		tputs(tgetstr("nd", NULL), 1, tputs_putchar);
	}
	return (hist);
}
