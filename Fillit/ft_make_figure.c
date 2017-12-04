/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_figure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 12:58:24 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/12/03 12:58:25 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	int		ft_check_places(t_list *list, char **map, int col, int line)
{
	int count;
	int dif_x;
	int dif_y;

	count = 0;
	dif_x = list->x[0] - 0;
	dif_y = list->y[0] - 0;
	if (dif_x > line || dif_y > col)
		return (0);
	while (count < SIZE)
	{
		if (map[list->y[count] + col - dif_y]
			[list->x[count] + line - dif_x] != '.')
			return (0);
		count++;
	}
	return (1);
}

static	void	ft_fill_mapp(t_list *list, char **map, int col, int line)
{
	int count;
	int dif_x;
	int dif_y;

	count = 0;
	dif_x = list->x[0] - 0;
	dif_y = list->y[0] - 0;
	while (count < SIZE)
	{
		(map[list->y[count] + col - dif_y]
			[list->x[count] + line - dif_x]) = list->let;
		count++;
	}
}

static	int		ft_try_figure(t_list *list, char **map, t_mass *nasa)
{
	nasa->col = list->y_coord;
	nasa->line = list->x_coord;
	while (map[nasa->col][nasa->line] != ',')
	{
		while (map[nasa->col][nasa->line] != ',')
		{
			if (map[nasa->col][nasa->line] == '.')
				if (ft_check_places(list, map, nasa->col, nasa->line))
				{
					ft_fill_mapp(list, map, nasa->col, nasa->line);
					list->x_coord = nasa->line;
					list->y_coord = nasa->col;
					return (1);
				}
			nasa->line++;
		}
		list->size = nasa->line;
		nasa->col++;
		nasa->line = 0;
	}
	list->x_coord = 0;
	list->y_coord = 0;
	return (0);
}

static	void	ft_clean_map(char ***mass, t_list *list)
{
	char	**map;
	int		col;
	int		line;

	map = *mass;
	col = 0;
	line = 0;
	while (map[col][line] != ',')
	{
		while (map[col][line] != ',')
		{
			if (map[col][line] == list->let - 1)
				map[col][line] = '.';
			line++;
		}
		col++;
		line = 0;
	}
}

int				ft_make_figure(t_list *list, char ***mass)
{
	t_mass	*nasa;

	nasa = (t_mass *)malloc(sizeof(t_mass));
	if (ft_try_figure(list, *mass, nasa))
		return (1);
	else
	{
		ft_clean_map(mass, list);
		if (list->prev == NULL)
			return (0);
		if (list->prev)
		{
			list->prev->x_coord++;
			if (list->prev->x_coord == list->size)
			{
				list->prev->x_coord = 0;
				list->prev->y_coord++;
			}
		}
	}
	return (-1);
}
