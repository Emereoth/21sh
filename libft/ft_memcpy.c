/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:32:55 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:32:56 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*y;
	char	*z;

	i = 0;
	y = (char*)dst;
	z = (char*)src;
	if (n == 0)
		return (y);
	while (i <= n)
	{
		y[i] = z[i];
		i++;
	}
	return (y);
}
