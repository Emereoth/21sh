/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_detail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:20:48 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:20:50 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	free_detail(t_detail *node)
{
	t_detail	*tmp;

	while (node)
	{
		if (node->redir_str)
			ft_strstrfree(node->redir_str);
		if (node->argv)
			ft_strstrfree(node->argv);
		if (node->redir)
			free(node->redir);
		if (node->fd_std)
			free(node->fd_std);
		if (node->fd_file)
			free(node->fd_file);
		tmp = node->next;
		free(node);
		node = tmp;
	}
}
