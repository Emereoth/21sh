/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:20:31 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:20:35 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lex_par_ast.h"

int				exec_check(t_node *node)
{
	char	*sep;
	t_node	*last;

	sep = node->str;
	last = (node->prev ? node->prev->left : node);
	if (ft_strcmp(sep, "&&") == 0)
		return (last->ret_cmd == 0 ? 1 : 0);
	if (ft_strcmp(sep, "||") == 0)
		return (last->ret_cmd == 0 ? 0 : 1);
	return (1);
}
