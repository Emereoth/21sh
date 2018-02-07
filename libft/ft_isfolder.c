/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfolder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:31:29 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:31:32 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isfolder(char *path)
{
	struct stat file;

	if ((stat(path, &file)) == -1)
		return (-1);
	if (S_ISREG(file.st_mode) == 1)
		return (0);
	return (1);
}
