/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:02:46 by acottier          #+#    #+#             */
/*   Updated: 2017/04/05 11:19:09 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"
#include "lex_par_ast.h"
#include "shell.h"
#include "env.h"
#include "hashtab.h"
#include "split.h"
#include <stdio.h>
#include "errno.h"

t_shell		*g_shell;

void			loop(void)
{
	char		*line;
	t_node		*tree;

	tree = NULL;
	while (1 && !(line = NULL))
	{
		g_shell->exec = 0;
		prompt();
		if (edit_line(&line, &(g_shell->hist), 0) == -1)
			get_next_line(0, &line);
		line = ft_quote(line);
		if (line != NULL)
			tree = mktree(parser(lexer(&line, line, 0)));
		else
			exit(0);
		g_shell->exec = 1;
		while ((tree = walkthrough(tree)))
			tree->ret_cmd = prep_exec(tree, g_shell->env);
	}
}

int				main(int ac, char **av)
{
	extern char	**environ;

	(void)ac;
	(void)av;
	init_mainprocess();
	g_shell->env = init_env(environ);
	g_shell->table = ft_init_hash_table();
	loop();
	ft_strstrfree(g_shell->env);
	return (0);
}
