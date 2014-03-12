/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 14:16:59 by wbeets            #+#    #+#             */
/*   Updated: 2014/02/04 14:17:59 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_check_env(char **env)
{
	if (*env != NULL)
		return (1);
	ft_putstr("Enviorment is empty, please set enviroment and relaunch.\n");
	return (0);
}
