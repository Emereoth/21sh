/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:10:12 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:11:22 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

void			paste(t_cursor *cursor, t_hist **hist)
{
	int			i;
	int			size;
	int			j;
	int			line;
	int			col;

	(void)hist;
	j = 0;
	size = ft_strlen(cursor->str_cpy);
	i = cursor->cur_col - 3 + cursor->max_col * (cursor->cur_line - 1);
	if ((int)ft_strlen(cursor->line) + size >= cursor->buff_size)
		extend_str(cursor);
	move_str(&cursor->line, i, size, cursor->buff_size);
	while (j < size)
	{
		cursor->line[i] = cursor->str_cpy[j];
		i++;
		j++;
	}
	set_pos(cursor, i, &line, &col);
	putstr_cmd(cursor, i - size);
	go_pos(cursor, line, col);
	set_marge(cursor);
}
