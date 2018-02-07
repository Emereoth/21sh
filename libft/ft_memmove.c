/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:33:01 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:33:03 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmpdst;
	const unsigned char	*tmpsrc;

	tmpsrc = src;
	tmpdst = dst;
	if (len)
	{
		if (dst > src)
		{
			tmpdst += len;
			tmpsrc += len;
			while (len--)
				*--tmpdst = *--tmpsrc;
		}
		else
		{
			while (len--)
				*tmpdst++ = *tmpsrc++;
		}
	}
	return (dst);
}
