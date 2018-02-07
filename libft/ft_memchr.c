/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:32:50 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:32:52 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*x;

	x = (unsigned char*)s;
	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			if (x[i] == (unsigned char)c)
				return ((void*)&x[i]);
			i++;
		}
	}
	return (NULL);
}
