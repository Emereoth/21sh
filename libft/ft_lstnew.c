/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:32:38 by acottier          #+#    #+#             */
/*   Updated: 2017/04/04 11:32:39 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*new_content;

	if (!(new = (t_list*)malloc(sizeof(*new))))
		return (NULL);
	if (!(content))
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(new_content = malloc(content_size)))
		{
			free(new);
			return (NULL);
		}
		new->content = ft_memcpy(new_content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
