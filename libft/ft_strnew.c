/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:36:04 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:36:06 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*n;

	if ((n = malloc(sizeof(*n) * (size + 1))) == NULL)
		return (NULL);
	ft_bzero(n, size + 1);
	return (n);
}
