/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 17:14:51 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/04 10:21:09 by wbeets           ###   ########.fr       */
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

typedef struct	s_ex
{
	char	**argv;
	char	**env;
	char	*name_ex;
	char	*oldpwd;
}				t_ex;

int	ft_get_command(t_ex *ex_info, char **input);
int		ft_ex_command(t_ex *ex_info);
int	ft_execute(t_ex *ex_info);
char	**ft_get_paths(char **tab);
int		ft_count_c(char *str, char c);
void	change_dir(t_ex *ex_info);
void	put_shellbase(char **env);
int		tablen(char **tab);
char	**copy_tab_i(char **env, int extra);
void	freetab(char **tab);
void	set_env(t_ex *ex_info);
void	change_env(t_ex *ex_info);
void	unset_env(t_ex *ex_info);
void	print_tab(char **tab);
int		find(char *str, char **tab);


#endif /* HEADER_H */
