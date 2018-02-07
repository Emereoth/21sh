/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:35:59 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:36:00 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t j;

	j = 0;
	while (j < n && src[j] != '\0')
	{
		dst[j] = src[j];
		j++;
	}
	while (j < n)
	{
		dst[j] = '\0';
		j++;
	}
	return (dst);
}
