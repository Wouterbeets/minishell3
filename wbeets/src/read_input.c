/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 10:46:30 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/07 18:08:14 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	start_line(t_llst *hist, struct winsize *winsize)
{
	int		lstlen;
	int		to_up;

	lstlen = clst_len(clst_start(hist->input));
	to_up = (lstlen / winsize->ws_col) + 1;

	if (winsize->ws_col <= lstlen)
	{
		while (--to_up)
		{
			tputs(tgetstr("sc", NULL), 1, tputs_putchar);
			tputs(tgetstr("ll", NULL), 1, tputs_putchar);
			tputs(tgetstr("sf", NULL), 1, tputs_putchar);
			tputs(tgetstr("rc", NULL), 1, tputs_putchar);
			tputs(tgetstr("up", NULL), 1, tputs_putchar);
		}
		tputs(tgetstr("cr", NULL), 1, tputs_putchar);
		tputs(tgetstr("sc", NULL), 1, tputs_putchar);
	}
	tputs(tgetstr("rc", NULL), 1, tputs_putchar);
	tputs(tgetstr("cd", NULL), 1, tputs_putchar);
	tputs(tgetstr("rc", NULL), 1, tputs_putchar);
}

t_llst	*rtn(t_llst *hist)
{
	t_llst	*tmp;

	if (hist->is)
	{
		tmp = llst_start(hist);
		llstaddend(&tmp, hist);
		while (hist->next != NULL)
			hist = hist->next;
		llst_del_elem(&tmp, hist->prev);
		hist->is = 0;
	}
	llstaddend(&hist, llstnew(clstnew(BASE)));
	tputs(tgetstr("do", NULL), 1, tputs_putchar);
	tputs(tgetstr("cr", NULL), 1, tputs_putchar);
	list_to_str(hist);
	return (hist);
}

t_llst	*read_input(char *c, t_llst *hist)
{
	int		ret;
	struct winsize	winsize;

	get_winsize(&winsize);
	if ((ret = is_arrow(c)))
	{
		if (ret == 1)
			hist = up(hist, &winsize);
		if (ret == 2)
			hist = down(hist, &winsize);
		if (ret == 3)
			hist = right(hist);
		if (ret == 4)
			hist = left(hist);
		return (hist);
	}
	else if (is_rtn(c))
		return ((hist = rtn(hist)));
	else if (is_bspace(c))
	{
		hist->input = clst_del_elem(hist->input);
		return (hist);
	}
	hist->input = clstaddmid(hist->input, clstnew(c));
	start_line(hist, &winsize);
	printlist(hist->input);
	return (hist);
}

void	list_to_str(t_llst *hist)
{
	int		len;
	int		i;
	t_clst	*tmp;

	tmp = clst_start(hist->input);
	len = clst_len(tmp);
	i = 0;
	hist->str = ft_strnew(len + 1 * sizeof(char));
	while (tmp)
	{
		hist->str[i++] = *tmp->c;
		tmp = tmp->next;
	}
}
