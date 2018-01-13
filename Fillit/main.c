/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:53:07 by osavytsk          #+#    #+#             */
/*   Updated: 2017/11/17 16:53:07 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	t_list		*new;
	char		**final;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit target_file\n");
		return (0);
	}
	new = ft_getmap(argv);
	if (!new)
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_clean(&new);
	final = ft_solve(new);
	if (!final)
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_print(final);
}
