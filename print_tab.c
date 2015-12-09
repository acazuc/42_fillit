/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 09:15:00 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/09 12:00:10 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "can_place.h"
#include "error_quit.h"
#include "piece.h"
#include "env.h"
#include "dot.h"

void	place(t_env *env, t_piece *piece, t_dot *dot, char character)
{
	int				dx;
	int				dy;

	dy = 0;
	while (dy < piece->height)
	{
		dx = 0;
		while (dx < piece->width)
		{
			if (piece->data[dy][dx] == '#')
				env->tab[dy + dot->y][dx + dot->x] = character;
			dx++;
		}
		dy++;
	}
}

void	put_piece(t_piece *piece, t_env *env, int size, char character)
{
	t_dot			*dot;
	int				x;
	int				y;

	if (!(dot = malloc(sizeof(*dot))))
		error_quit("error");
	y = 0;
	while (y <= size - piece->height)
	{
		x = 0;
		while (x <= size - piece->width)
		{
			if (can_place(env, piece, x, y))
			{
				dot->x = x;
				dot->y = y;
				place(env, piece, dot, character);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	print_tab(t_env *env, int size)
{
	t_piece_list	*list;
	char			character;
	int				x;
	int				y;

	list = env->pieces;
	character = 'A';
	while (list)
	{
		put_piece(list->piece, env, size, character);
		character++;
		list = list->next;
	}
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_putchar(env->tab[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
