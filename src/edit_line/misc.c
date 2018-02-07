/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:09:56 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:11:19 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

int				my_putchar(int c)
{
	return (write(1, &c, 1));
}

void			set_marge(t_cursor *cursor)
{
	if (cursor->cur_line == 1)
		cursor->l_marge = 3;
	else
		cursor->l_marge = 0;
	if (cursor->cur_line < cursor->nb_line)
		cursor->r_marge = cursor->max_col;
	else
		cursor->r_marge = ft_strlen(cursor->line) % cursor->max_col + 3;
}

void			set_pos(t_cursor *cursor, int i, int *line, int *col)
{
	if (i < cursor->max_col - 3)
	{
		*line = 1;
		*col = i + 3;
	}
	else
	{
		*line = ((i - cursor->max_col + 3) / cursor->max_col) + 2;
		*col = i - (cursor->max_col * (*line - 1)) + 3;
	}
}
