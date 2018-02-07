/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:32:44 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:32:46 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*x;
	char	*y;
	size_t	i;

	i = 0;
	x = malloc(size);
	y = (char*)x;
	if (size == 0)
		return (NULL);
	if (x == NULL)
		return (NULL);
	while (i < size)
	{
		y[i] = (char)0;
		i++;
	}
	return (x);
}
