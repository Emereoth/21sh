/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arg_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:09:27 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:11:14 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

static void		free_node(t_arg *node)
{
	if (node && node->name)
	{
		free(node->name);
		node->name = NULL;
	}
	if (node)
	{
		free(node);
		node = NULL;
	}
}

void			free_arg_list(t_arg *cur)
{
	t_arg		*begin;
	t_arg		*tmp;

	if (!cur->name)
		return ;
	begin = cur;
	cur = cur->next;
	while (cur && cur != begin)
	{
		tmp = cur->next;
		free_node(cur);
		cur = tmp;
	}
	free_node(cur);
	cur = NULL;
}
