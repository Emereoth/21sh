/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:36:29 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:36:30 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strstrlen(char **c)
{
	size_t i;

	i = 0;
	if (!c)
		return (i);
	while (c[i] != NULL)
		i++;
	return (i);
}
