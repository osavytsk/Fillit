/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:10:57 by osavytsk          #+#    #+#             */
/*   Updated: 2017/11/17 15:10:57 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HEADER_H
# define _HEADER_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define MAXSIZE 72
# define SIZE 4

typedef struct		s_mass
{
	int				col;
	int				line;
}					t_mass;

void				ft_make_optimal(t_list *list);
t_list				*ft_getmap(char **argv);
int					ft_check_sharps(t_list *list);
char				**ft_solve(t_list *list);
int					ft_make_figure(t_list *map, char ***mass);
void				ft_print(char **mass);
void				ft_clean(t_list **list);
void				ft_find_prev(t_list *new, t_list **list);
int					ft_check_norm(t_list *list);
int					ft_allocate_mem(t_list **list, int count);
void				ft_if_find_sharp(t_list *list, char *c);
int					ft_makelist(t_list *list, char c);

#endif
