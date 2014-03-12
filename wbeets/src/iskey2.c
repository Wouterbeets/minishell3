/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iskey2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 14:07:48 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/10 13:33:02 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		is_rtn(char *buf)
{
	return (buf[0] == 10);
}

int		is_esc(char *buf)
{
	return (buf[0] == 27 && buf[1] == 0);
}

int		is_cntrl_z(char *buf)
{
	return (buf[0] == -62);
}