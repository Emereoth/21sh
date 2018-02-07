/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:10:38 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:11:24 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit_line.h"

static void			underline(char *arg)
{
	ft_putstr("\033[4;37m");
	ft_putstr(arg);
	ft_putstr("\033[0m");
}

static void			highlight(char *arg)
{
	ft_putstr("\033[7;37m");
	ft_putstr(arg);
	ft_putstr("\033[0m");
}

static void			underline_highlight(char *arg)
{
	ft_putstr("\033[7;4;37m");
	ft_putstr(arg);
	ft_putstr("\033[0m");
}

void				style_print(t_arg *arg)
{
	if (arg->name)
	{
		if (arg->selected == 1 && arg->current == 0)
			highlight(arg->name);
		else if (arg->selected == 0 && arg->current == 1)
			underline(arg->name);
		else if (arg->selected == 1 && arg->current == 1)
			underline_highlight(arg->name);
		else
			ft_putstr(arg->name);
	}
}
