/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:06:53 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:06:54 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

/*
** recupere le troncon de chaine copie grace a 2 valeur, ensuite place ce
** troncon dasn la chaine puis affiche la chaine
*/

void			copy(t_cursor *cur, t_hist **hist)
{
	int			i;
	int			line;
	int			col;
	int			len;

	(void)hist;
	if (cur->beg_select != -1 && cur->end_select != -1)
	{
		i = cur->cur_col - 3 + cur->max_col * (cur->cur_line - 1);
		if (cur->beg_select > cur->end_select)
			ft_swap(&cur->beg_select, &cur->end_select);
		len = cur->end_select - cur->beg_select + 1;
		cur->str_cpy = ft_strsub(cur->line, cur->beg_select, len);
		cur->beg_select = -1;
		cur->end_select = -1;
		go_pos(cur, 1, 3);
		putstr_cmd(cur, 0);
		set_pos(cur, i, &line, &col);
		go_pos(cur, line, col);
		set_marge(cur);
	}
}

/*
** recupere le troncon de chaine couper grace a 2 valeur, deplace le reste
** de la chaine vers la droite puis affiche la chaine
*/

void			cut(t_cursor *cur, t_hist **hist)
{
	int			i;
	int			line;
	int			col;
	int			len;

	(void)hist;
	(void)i;
	if (cur->beg_select != -1 && cur->end_select != -1)
	{
		i = cur->cur_col - 3 + cur->max_col * (cur->cur_line - 1);
		if (cur->beg_select > cur->end_select)
			ft_swap(&cur->beg_select, &cur->end_select);
		len = cur->end_select - cur->beg_select + 1;
		cur->str_cpy = ft_strsub(cur->line, cur->beg_select, len);
		move_str(&cur->line, cur->end_select + 1, -len, cur->buff_size);
		set_pos(cur, cur->beg_select, &line, &col);
		cur->beg_select = -1;
		cur->end_select = -1;
		go_pos(cur, 1, 3);
		putstr_cmd(cur, 0);
		tputs(tgetstr("ce", 0), 1, my_putchar);
		go_pos(cur, line, col);
		set_marge(cur);
	}
}
