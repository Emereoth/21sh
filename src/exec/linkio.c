/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkio.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:20:55 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:20:56 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int			link_sl(t_detail *node, int i)
{
	dup2(node->fd_file[i], node->fd_std[i]);
	close(node->fd_file[i]);
	return (0);
}

static int			link_dbl(t_detail *node, int i)
{
	dup2(node->pfd[0], node->fd_std[i]);
	close(node->pfd[0]);
	return (0);
}

static int			link_sr(t_detail *node, int i)
{
	dup2(node->fd_file[i], node->fd_std[i]);
	close(node->fd_file[i]);
	return (0);
}

static int			link_dbr(t_detail *node, int i)
{
	dup2(node->fd_file[i], node->fd_std[i]);
	close(node->fd_file[i]);
	return (0);
}

int					linkio(t_detail *node)
{
	size_t			i;
	size_t			len;
	static int		(*link[4])(t_detail *ndoe, int i) =
	{link_dbr, link_sr, link_sl, link_dbl};

	i = 0;
	len = ft_strstrlen(node->redir_str);
	while (i < len)
	{
		if (node->redir[i] != -1)
			link[node->redir[i]](node, i);
		i++;
	}
	return (0);
}
