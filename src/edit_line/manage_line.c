/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:09:53 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:11:19 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

void		extend_str(t_cursor *cur)
{
	char	tmp[ft_strlen(cur->line)];

	cur->buff_size *= 2;
	ft_strcpy(tmp, cur->line);
	free(cur->line);
	cur->line = ft_strnew(cur->buff_size);
	ft_strcpy(cur->line, tmp);
}

void		move_str(char **line, int i, int way, int max)
{
	int		limit;
	char	tmp[max];
	int		j;

	j = 0;
	ft_bzero(tmp, max);
	ft_strcpy(tmp, &(*line)[i]);
	if (way < 0)
		limit = max;
	else
		limit = ft_strlen(*line);
	while (i < limit)
	{
		(*line)[i + way] = tmp[j];
		i++;
		j++;
	}
}
