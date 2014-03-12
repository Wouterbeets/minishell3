/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 13:38:58 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/07 17:07:06 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init(t_lists *lsts, t_ex *ex_info, char **env, char **input)
{
	lsts->input = clstnew(BASE);
	lsts->hist = llstnew(lsts->input);
	ex_info->env = copy_tab_i(env, 0);
	*input = "";
	ex_info->oldpwd = NULL;
	ex_info->oldpwd = getcwd(ex_info->oldpwd, 4096);
}

void		get_winsize(struct winsize *ws)
{
	ioctl(1, TIOCGWINSZ, ws);
}

int		set_stage(struct termios *term)
{
	char	buffer[2048];

	if (tgetent(buffer, getenv("TERM")) < 1)
		return (0);
	tcgetattr(0, term);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, 0, term);
	tputs(tgetstr("sc", NULL), 1, tputs_putchar);
	return (1);
}

int		get_input(t_lists *lsts, char **input)
{
	struct termios	term;
	char			c[4];

	set_stage(&term);
	lsts->hist->str = NULL;
	while (lsts->hist->next)
		lsts->hist = lsts->hist->next;
	printlist(lsts->hist->input);
	while (42)
	{
		c[0] = 0;
		c[1] = 0;
		c[2] = 0;
		read(0 , &c, 4);
		lsts->hist = read_input(c, lsts->hist);
		if (lsts->hist->str)
		{
			*input = lsts->hist->str;
			return (1);
		}
	}
	return (0);
}

