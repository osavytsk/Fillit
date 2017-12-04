/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 12:54:17 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/12/03 12:54:19 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	void	ft_free_mem(t_list *list)
{
	int		index;

	index = 0;
	free(list->str);
	while (list->include[index])
	{
		free(list->include[index]);
		index++;
	}
}

void			ft_clean(t_list **list)
{
	t_list *clean;

	clean = *list;
	while (clean)
	{
		ft_free_mem(clean);
		free(clean->include);
		clean = clean->next;
	}
}
