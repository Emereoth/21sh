/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:20:15 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:20:18 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"
#include "shell.h"
#include "edit_line.h"
#include "errno.h"

t_shell		*g_shell;

static void	reset_cursor(void)
{
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	ft_bzero(g_shell->cursor->line, ft_strlen(g_shell->cursor->line));
	ft_bzero(g_shell->av, ft_strlen(g_shell->av));
	g_shell->quote[0] = 0;
	g_shell->quote[1] = 0;
	g_shell->heredoc = 0;
	g_shell->cursor->l_marge = 3;
	g_shell->cursor->cur_line = 1;
	g_shell->cursor->nb_line = 1;
	g_shell->cursor->r_marge = 3;
	g_shell->cursor->cur_col = 3;
	g_shell->cursor->max_col = win.ws_col;
	g_shell->cursor->beg_select = -1;
	g_shell->cursor->end_select = -1;
	g_shell->cursor->str_cpy = NULL;
}

void		sig(int i)
{
	char			c;

	(void)i;
	c = 27;
	if (g_shell->exec)
		return ;
	ft_putchar('\n');
	if (g_shell->comp)
	{
		while (g_shell->info->line-- > 0)
			ft_putchar('\n');
		go_pos(g_shell->cursor, 0, 0);
		prompt();
		g_shell->comp = 0;
		ioctl(0, TIOCSTI, &c);
		return ;
	}
	if (g_shell->heredoc)
	{
		g_shell->heredoc = 0;
		ioctl(0, TIOCSTI, &c);
	}
	else
		prompt();
	reset_cursor();
}

t_shell		*init_mainprocess(void)
{
	g_shell = NULL;
	signal(SIGINT, sig);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	if (!(g_shell = (t_shell*)malloc(sizeof(t_shell))))
		return (NULL);
	g_shell->hist = NULL;
	g_shell->table = NULL;
	g_shell->comp = 0;
	ft_bzero(g_shell->quote, sizeof(int) * 2);
	if (tcgetattr(1, &(g_shell->dfl_term)) == -1)
		ft_putendl("error");
	return (g_shell);
}
