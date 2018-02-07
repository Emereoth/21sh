/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:19:24 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:19:27 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "shell.h"
#include "env.h"

t_shell		*g_shell;

int		ft_exit(char **argv)
{
	int i;

	if (ft_strstrlen(argv) > 2)
	{
		ft_putendl("exit: too many arguments");
		return (1);
	}
	if (ft_strstrlen(argv) == 1)
	{
		ft_free_hash_tab();
		tcsetattr(1, TCSADRAIN, &(g_shell->dfl_term));
		if (g_shell)
			free_shell(&g_shell);
		exit(0);
	}
	if (!(i = ft_atoi(argv[1])))
	{
		ft_putendl("exit: Expression Syntax.");
		return (1);
	}
	ft_free_hash_tab();
	tcsetattr(1, TCSADRAIN, &(g_shell->dfl_term));
	if (g_shell)
		free_shell(&g_shell);
	exit(i);
}
