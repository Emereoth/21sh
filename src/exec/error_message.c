/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:20:22 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:20:24 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*error_message(int ret, char *cmd)
{
	if (!cmd)
		return (NULL);
	if (ret == 127)
	{
		ft_putstr_fd("21sh: command not found: ", 2);
		ft_putendl_fd(cmd, 2);
	}
	else if (ret == 126 || ret == 1)
	{
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": Permission denied.", 2);
	}
	return (NULL);
}
