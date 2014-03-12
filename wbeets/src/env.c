/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 14:21:30 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/07 14:44:20 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		tablen(char **arr)
{
	int		i;

	i = 0;
	while (arr[i] != '\0')
		i++;
	return (i);
}

char	**copy_tab_i(char **env, int extra)
{
	int		i;
	char **arr;

	arr = (char **)malloc((tablen(env) + 1 + extra) * sizeof(char *));
	i = 0;
	while (env[i] != '\0')
	{
		arr[i] = ft_strdup(env[i]);
		i++;
	}
	arr[i + extra] = NULL;
	return (arr);
}

void	freetab(char **arr)
{
	int		i;

	i = 0;
	while (arr[i] != '\0')
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	set_env(t_ex *ex_info)
{
	char	**arr;

	if (!(ex_info->argv[1]))
		return ;
	arr = copy_tab_i(ex_info->env, 1);
	arr[tablen(ex_info->env)] = ft_strdup(ex_info->argv[1]);
	freetab(ex_info->env);
	ex_info->env = arr;
}

void	unset_env(t_ex *ex_info)
{
	int		i;

	i = 0;
	if (!(ex_info->argv[1]))
		return ;
	while (ft_strstr(ex_info->env[i], ex_info->argv[1]) == NULL)
	{
		i++;
		if (ex_info->env[i] == NULL)
			return ;
	}
	free(ex_info->env[i]);
	while (ex_info->env[i] != '\0')
	{
		ex_info->env[i] = ex_info->env[i + 1];
		i++;
	}
}
