/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:36:32 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:36:33 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*x;
	size_t	i;

	if (!(x = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = start;
	while (i < start + len)
	{
		x[i - start] = s[i];
		i++;
	}
	x[i - start] = '\0';
	return (x);
}
