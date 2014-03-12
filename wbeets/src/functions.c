/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 16:00:11 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/07 18:18:13 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**ft_get_paths(char **arr)
{
	char	**tmp;
	char	**paths;
	int		i;
	int		j;
	char	*pwd;

	tmp = ft_strsplit(arr[0] + 5 , ':');
	i = ft_count_c(arr[0], ':') + 1;
	paths = (char**)malloc((i + 2) * sizeof(char *));
	j = 0;
	while (tmp[j] != '\0')
	{
		paths[j] = ft_strjoin(tmp[j], "/");
		free(tmp[j]);
		j++;
	}
	pwd = NULL;
	pwd = getcwd(pwd, 4096);
	paths[j] = ft_strjoin(pwd, "/");
	free(pwd);
	free(tmp);
	return (paths);
}

void	change_env(t_ex *ex_info, char **env)
{
	if (ft_strcmp(ex_info->name_ex, "setenv") == 0)
		set_env(ex_info);
	else if (ft_strcmp(ex_info->name_ex, "unsetenv") == 0)
		unset_env(ex_info);
	env = ex_info->env;
}

int		ft_count_c(char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}

void	change_dir(t_ex *ex_info)
{
	char	*path;
	int		ret;

	path = NULL;
	path = getcwd(path, 4096);
	if ((!(ex_info->argv[1])) || ft_strcmp(ex_info->argv[1], "~") == 0)
		ret = chdir(ex_info->env[find("HOME", ex_info->env)] + 5);
	else if (ft_strcmp(ex_info->argv[1], "-") == 0)
			ret = chdir(ex_info->oldpwd);
	else
		ret = chdir(ex_info->argv[1]);
	if (ret == -1)
		ft_putstr("not a directory\n");
	free(ex_info->oldpwd);
	ex_info->oldpwd = path;
}

void	put_shellbase(char **env)
{
	char	*path;

	(void)env;
	path = NULL;
	path = getcwd(path, 4096);
	ft_putstr(path + 43);
	free(path);
	ft_putstr("$>");
}
