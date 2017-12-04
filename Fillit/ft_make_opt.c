/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 12:58:38 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/12/03 12:58:38 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	void	ft_check_optimal_y(t_list *list, int check)
{
	int		coord;
	int		min;

	min = check;
	coord = 0;
	while (coord < SIZE)
	{
		if (list->y[coord] < min)
			min = list->x[coord];
		coord++;
	}
	coord = 0;
	if (min > 0)
	{
		while (coord < SIZE)
		{
			list->y[coord] = list->y[coord] - min;
			coord++;
		}
	}
}

static	void	ft_check_optimal_x(t_list *list, int check)
{
	int		coord;
	int		min;

	min = check;
	coord = 0;
	while (coord < SIZE)
	{
		if (list->x[coord] < min)
			min = list->x[coord];
		coord++;
	}
	coord = 0;
	if (min > 0)
	{
		while (coord < SIZE)
		{
			list->x[coord] = list->x[coord] - min;
			coord++;
		}
	}
}

void			ft_make_optimal(t_list *list)
{
	int		x;
	int		y;

	x = list->x[0];
	y = list->y[0];
	ft_check_optimal_x(list, x);
	ft_check_optimal_y(list, y);
}
