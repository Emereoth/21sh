/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 18:32:32 by lvalenti          #+#    #+#             */
/*   Updated: 2017/04/03 18:32:33 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <signal.h>
# include "exec.h"
# include "edit_line.h"
# include "hashtab.h"

typedef struct		s_shell
{
	struct termios	cur_term;
	struct termios	dfl_term;
	t_cursor		*cursor;
	t_info			*info;
	char			**env;
	char			*av;
	int				quote[2];
	int				heredoc;
	int				comp;
	int				exec;
	t_hist			*hist;
	t_binary		**table;
}					t_shell;

extern t_shell		*g_shell;

t_shell				*init_mainprocess(void);
char				*toexec(char *argv);

#endif
