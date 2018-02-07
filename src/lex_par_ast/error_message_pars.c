/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_pars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:23:58 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:23:59 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lex_par_ast.h"

t_detail		*cmd_pars_error(t_detail *cursor, int err)
{
	if (err == 1 || err == 2)
	{
		ft_putstr_fd("Parse error near '", 2);
		ft_putstr_fd(cursor->argv[0], 2);
		ft_putendl_fd("'", 2);
	}
	if (err == 3)
		ft_putendl_fd("Ambiguous output redirect.", 2);
	if (err == 4)
		ft_putendl_fd("Missing name for redirect.", 2);
	if (err == 5)
		ft_putendl_fd("Invalid null command.", 2);
	if (err == 2)
		return (cursor->next);
	if (err == 6)
		ft_putendl_fd("Parse error near '|'", 2);
	return (cursor);
}

t_lex			*sep_pars_error(t_lex *cursor, int err)
{
	if (err == 0)
		ft_putendl("Invalid null command.");
	if (err == 1)
	{
		ft_putstr_fd("Parse error near '", 2);
		ft_putstr_fd(cursor->str, 2);
		ft_putendl_fd("'", 2);
	}
	return (cursor);
}
