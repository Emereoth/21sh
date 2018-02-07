/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:19:30 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:19:33 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "exec.h"
#include "libft.h"

int		builtin(t_detail *node)
{
	int					i;
	static t_builtin	tab[7] = {
		{"cd", &ft_cd},
		{"setenv", &ft_setenv},
		{"unsetenv", &ft_unsetenv},
		{"hashtab", &ft_hashtab},
		{"env", &ft_env},
		{"echo", &ft_echo},
		{"exit", &ft_exit}
	};

	i = 0;
	while (i < 7 && node->argv)
	{
		if (ft_strcmp(node->argv[0], tab[i].name) == 0)
		{
			linkio(node);
			return (tab[i].fbuiltin(node->argv));
		}
		i++;
	}
	return (-1);
}
