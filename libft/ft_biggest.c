/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_biggest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:30:40 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:30:42 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_biggest(int i, int j)
{
	if (i > j)
		return (i);
	else
		return (j);
}