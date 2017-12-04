/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 12:58:51 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/12/03 12:58:52 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print(char **mass)
{
	int line;
	int col;

	col = 0;
	line = 0;
	while (mass[col][line] != ',')
	{
		while (mass[col][line] != ',')
		{
			ft_putchar(mass[col][line]);
			line++;
		}
		ft_putchar('\n');
		line = 0;
		col++;
	}
}
