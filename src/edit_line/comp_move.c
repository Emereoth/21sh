/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:08:08 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:10:50 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

/*
** deplace a droite la position initiale pendant la completion
*/

void				s_right(t_info *info)
{
	while (info->arg->current != 1)
		info->arg = info->arg->next;
	info->arg->current = 0;
	info->arg->next->current = 1;
	while (info->arg->start != 1)
		info->arg = info->arg->next;
}

/*
** deplace a gauche la position initiale pendant la completion
*/

void				s_left(t_info *info)
{
	while (info->arg->current != 1)
		info->arg = info->arg->next;
	info->arg->current = 0;
	info->arg->prev->current = 1;
	while (info->arg->start != 1)
		info->arg = info->arg->next;
}
