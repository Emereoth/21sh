/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:09:36 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:11:17 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

static int			alpha_is_present(char *line)
{
	while (*line)
	{
		if (*line > 32)
			return (1);
		line++;
	}
	return (0);
}

static void			init_hist(t_hist **hist, char **line)
{
	if ((*hist = (t_hist *)malloc(sizeof(t_hist))))
	{
		(*hist)->cmd = ft_strdup(*line);
		(*hist)->next = NULL;
		(*hist)->prev = NULL;
	}
}

static void			add_node(t_hist **hist, char **line)
{
	t_hist		*new;

	if ((new = (t_hist *)malloc(sizeof(t_hist))))
	{
		new->cmd = ft_strdup(*line);
		new->next = NULL;
		while ((*hist)->next)
			*hist = (*hist)->next;
		new->prev = *hist;
		(*hist)->next = new;
		*hist = new;
	}
}

void				create_hist(t_hist **hist, char **line)
{
	if (hist && line && alpha_is_present(*line))
	{
		if (*hist == NULL)
			init_hist(hist, line);
		else
			add_node(hist, line);
	}
}
