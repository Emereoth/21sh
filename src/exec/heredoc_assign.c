/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_assign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:20:51 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:20:53 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lex_par_ast.h"
#include "exec.h"

void	heredoc_assign(t_node *tree)
{
	if (tree)
	{
		heredoc_assign(tree->left);
		if (tree->lst)
			if (select_redir(tree))
				tree->ret_cmd = 1;
		heredoc_assign(tree->right);
	}
}
