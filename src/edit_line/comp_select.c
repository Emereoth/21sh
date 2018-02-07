/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:08:12 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:10:52 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

/*
** fonction pour selectioner un element pendant la completion
*/

void			space(t_info *info)
{
	t_arg		*tmp;

	tmp = info->arg;
	while (tmp->current != 1)
		tmp = tmp->next;
	if (tmp->selected == 0)
		tmp->selected = 1;
	else
		tmp->selected = 0;
	s_right(info);
}
