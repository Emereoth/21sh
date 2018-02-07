/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:09:50 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:11:18 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"
#include "shell.h"
#include "env.h"
#include <errno.h>

t_shell	*g_shell;

static void			init_cursor(t_cursor **cursor)
{
	struct winsize	win;

	errno = 0;
	ioctl(0, TIOCGWINSZ, &win);
	if ((*cursor = (t_cursor *)malloc(sizeof(t_cursor))))
	{
		(*cursor)->buff_size = 50;
		(*cursor)->line = ft_strnew((*cursor)->buff_size);
		(*cursor)->l_marge = 3;
		(*cursor)->cur_line = 1;
		(*cursor)->nb_line = 1;
		(*cursor)->r_marge = 3;
		(*cursor)->cur_col = 3;
		(*cursor)->max_col = win.ws_col;
		(*cursor)->beg_select = -1;
		(*cursor)->end_select = -1;
		(*cursor)->str_cpy = NULL;
	}
}

int					init_term(t_cursor **cur)
{
	char			*name;
	struct termios	cur_term;

	errno = 0;
	init_cursor(cur);
	g_shell->cursor = *cur;
	if ((name = getenvline("TERM")) == NULL)
		return (1);
	if ((tgetent(NULL, name) == ERR))
	{
		free(name);
		return (1);
	}
	free(name);
	if (tcgetattr(0, &((*cur)->term)) == -1)
		return (1);
	cur_term = (*cur)->term;
	cur_term.c_lflag &= ~(ICANON | ECHO);
	cur_term.c_cc[VMIN] = 1;
	cur_term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &cur_term))
		return (1);
	return (0);
}

int					term_dfl(t_cursor *cur)
{
	if (tcgetattr(0, &(cur->term)) == -1)
		return (-1);
	cur->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &cur->term) == -1)
		return (-1);
	tputs(tgetstr("ve", 0), 1, my_putchar);
	return (0);
}
