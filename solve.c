/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:36:42 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/09 12:00:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include "error_quit.h"
#include "piece_list.h"
#include "print_tab.h"
#include "can_place.h"
#include "piece.h"
#include "env.h"

void		reset(t_env *env, int size)
{
	int				x;
	int				y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			env->tab[y][x] = '.';
			x++;
		}
		y++;
	}
}

void		put_in_tab(t_env *env, t_piece *piece, int x, int y)
{
	int				dx;
	int				dy;

	dy = 0;
	while (dy < piece->height)
	{
		dx = 0;
		while (dx < piece->width)
		{
			env->tab[y + dy][x + dx] = '#';
			dx++;
		}
		dy++;
	}
}

int			place_piece(t_piece *piece, t_env *env, int test_size)
{
	int				x;
	int				y;

	y = 0;
	while (y <= test_size - piece->height)
	{
		x = 0;
		while (x <= test_size - piece->width)
		{
			if (can_place(env, piece, x, y))
			{
				put_in_tab(env, piece, x, y);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int			place_pieces(t_env *env)
{
	t_piece_list	*list;
	int				test_size;

	test_size = env->tab_dimensions;
	while (test_size > 0)
	{
		list = env->pieces;
		while (list)
		{
			if (!place_piece(list->piece, env, test_size))
				return (test_size + 1);
			list = list->next;
		}
		reset(env, test_size);
		test_size--;
	}
	return (-1);
}

void		solve(t_env *env)
{
	t_piece_list	*list;
	int				total_width;
	int				size;
	int				y;

	total_width = 0;
	list = env->pieces;
	while (list)
	{
		total_width += list->piece->height > list->piece->width
			? list->piece->height : list->piece->width;
		list = list->next;
	}
	if ((env->tab = malloc(sizeof(*(env->tab)) * total_width)) == NULL)
		error_quit("error");
	y = -1;
	while (++y < total_width)
		if ((env->tab[y] = malloc(sizeof(**(env->tab)) * total_width)) == NULL)
			error_quit("error");
	reset(env, total_width);
	env->tab_dimensions = total_width;
	size = place_pieces(env);
	reset(env, total_width);
	print_tab(env, size);
}
