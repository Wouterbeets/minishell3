/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 16:00:11 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/07 17:08:23 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		find(char *str, char **arr)
{
	int		i;

	i = 0;
	while (arr[i] != '\0' && !ft_strstr(arr[i] ,str))
		i++;
	return (i);
}

int		ft_get_command(t_ex *ex_info, char **input, t_lists *lsts)
{
	int		ret;
	char	**arr;
	char	*tmp;

	ret = get_input(lsts, input);
	tmp = *input;
	*input = ft_strtrim(*input);
	free(tmp);
	arr = ft_strsplit(*input, ' ');
	ex_info->name_ex = arr[0];
	ex_info->argv = arr;
	return (1);
}

int		ft_ex_command(t_ex *ex_info)
{
	pid_t	pid;
	int		ret;

	pid = fork();
	if (pid == 0 && ft_strcmp(ex_info->name_ex, "exit") != 0)
	{
		ft_execute(ex_info);
		ft_putstr("file is not an executable\n");
		exit (0);
	}
	if (pid > 0)
		wait(&ret);
	return (1);
}

int	ft_execute(t_ex *ex_info)
{
	char		**paths;
	char		*tmp;
	int			i;

	i = -1;
	paths = ft_get_paths(ex_info->env);
	while (paths[++i] != '\0')
	{
		tmp = ft_strjoin(paths[i], ex_info->name_ex);
		execve(tmp, ex_info->argv, ex_info->env);
		free(tmp);
	}
	execve(ex_info->name_ex, ex_info->argv, ex_info->env);
	return (0);
}

int		main(int argc, char **argv, char **env)
{
	t_ex		ex_info;
	char		*input;
	t_lists		lsts;

	(void)argc;
	(void)argv;
	init(&lsts, &ex_info, env, &input);
	while (ft_strcmp(input, "exit") != 0)
	{
		put_shellbase(env);
		ft_get_command(&ex_info, &input, &lsts);
		if (input[0] != '\0')
		{
			if (ft_strcmp(ex_info.name_ex, "cd") == 0)
				change_dir(&ex_info);
			else if ((ft_strcmp(ex_info.name_ex, "setenv") == 0) ||
				(ft_strcmp(ex_info.name_ex, "unsetenv") == 0))
				change_env(&ex_info, env);
			else
				ft_ex_command(&ex_info);
		}
		free(ex_info.name_ex);
	}
	return (0);
}
