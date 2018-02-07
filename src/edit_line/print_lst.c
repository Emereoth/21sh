/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:10:17 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:11:23 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

static void		alligne(int len, int size)
{
	int			i;

	i = 0;
	while ((i + size) < len)
	{
		ft_putchar(' ');
		i++;
	}
}

void			print_lst(t_info *info)
{
	int			line;
	int			column;
	t_arg		*tmp;

	line = 0;
	tmp = info->arg;
	while (line < info->line)
	{
		column = 1;
		style_print(tmp);
		alligne(info->len, (int)ft_strlen(tmp->name));
		tmp = tmp->next;
		while (tmp && tmp->start != 1 && column < info->column)
		{
			style_print(tmp);
			alligne(info->len, (int)ft_strlen(tmp->name));
			column++;
			tmp = tmp->next;
		}
		ft_putchar('\n');
		line++;
	}
}
