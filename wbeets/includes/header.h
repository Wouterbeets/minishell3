/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 17:14:51 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/07 17:28:36 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <termios.h>
# include <termcap.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <term.h>
# include <curses.h>
# include <fcntl.h>
# include <sys/uio.h>
# define BASE " "

typedef struct		s_clst
{
	char			*c;
	struct s_clst	*prev;
	struct s_clst	*next;
}					t_clst;

typedef struct		s_llst
{
	t_clst			*input;
	struct s_llst	*prev;
	struct s_llst	*next;
	int				is;
	char			*str;
}					t_llst;

typedef struct		s_slst
{
	char			*str;
	struct s_slst	*prev;
	struct s_slst	*next;
}					t_slst;

typedef struct		s_tree
{
	char			*cmd;
	int				opc;
	struct s_tree	*prev;
	struct s_tree	*right;
	struct s_tree	*left;
}					t_tree;

typedef struct	s_lists
{
	t_clst	*input;
	t_llst	*hist;
}				t_lists;

typedef struct	s_ex
{
	char	**argv;
	char	**env;
	char	*name_ex;
	char	*oldpwd;
}				t_ex;

/*main.c*/

void	get_winsize(struct winsize *ws);
void	printlist(t_clst *lst);
t_llst	*read_input(char *c, t_llst *hist);
int		ft_check_env(char **env);
void	start_line(t_llst *hist, struct winsize *winsize);
int		get_input(t_lists *lsts, char **input);
void	init(t_lists *lsts, t_ex *ex_info, char **env, char **input);
void	list_to_str(t_llst *hist);


/* is key*/
int		is_arrow(char *buf);
int		is_space(char *buf);
int		is_bspace(char *buf);
int		is_del(char *buf);
int		is_rtn(char *buf);
int		is_esc(char *buf);
int		is_cntrl_z(char *buf);
int		is_cntrl_c(char *buf);

/*arrows*/
t_llst	*up(t_llst *hist, struct winsize *winsize);
t_llst	*down(t_llst *hist, struct winsize *winsize);
t_llst	*left(t_llst *hist);
t_llst	*right(t_llst *hist);

/*list functions*/
void	clstadd(t_clst **alst, t_clst *new);
void	clstaddend(t_clst **alst, t_clst *new);
t_clst	*clstnew(char *str);
t_clst	*clstaddmid(t_clst *alst, t_clst *new);
t_llst	*llstnew(t_clst *clst);
void	llstaddend(t_llst **alst, t_llst *new);
t_clst	*clst_cpy(t_clst *lst);
int		tputs_putchar(int c);
t_llst	*llst_start(t_llst *hist);
void	llst_del_elem(t_llst **start, t_llst *hist);
void	clst_del(t_clst *elem);
t_clst	*clst_del_elem(t_clst *input);
t_clst	*clst_start(t_clst *elem);
int		clst_len(t_clst *lst);


int		ft_ex_command(t_ex *ex_info);
int		ft_get_command(t_ex *ex_info, char **input, t_lists *lsts);
int	ft_execute(t_ex *ex_info);
char	**ft_get_paths(char **arr);
int		ft_count_c(char *str, char c);
void	change_dir(t_ex *ex_info);
void	put_shellbase(char **env);
int		tablen(char **arr);
char	**copy_tab_i(char **env, int extra);
void	freetab(char **arr);
void	set_env(t_ex *ex_info);
void	unset_env(t_ex *ex_info);
void	change_env(t_ex *ex_info, char **env);
void	print_tab(char **arr);
int		find(char *str, char **arr);


#endif /* HEADER_H */
