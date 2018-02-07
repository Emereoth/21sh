/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:09:16 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:11:13 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

/*
** recupere le chemin au mooment de la completion
*/

char			**find_files(t_cursor *cursor, t_info *info, int i)
{
	int			j;

	j = i;
	while (j > 0 && cursor->line[j - 1] != ' ')
		j--;
	info->dir = ft_strsub(cursor->line, j, i - j);
	select_dir(info);
	return (NULL);
}
