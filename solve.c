/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:36:42 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/04 11:16:58 by qjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error_quit.h"
#include "piece_list.h"
#include "piece.h"
#include "env.h"

int			can_place(t_env *env, t_piece *piece, int x, int y)
{
	int 			test_x;
	int				test_y;

	test_y = 0;
	while (test_y < piece->height)
	{
		test_x = 0;
		while (test_x < piece->width)
		{
			if (piece->data[test_y][test_x] == '#')
				if (env->tab[y + test_y][x + test_x] != '.')
					return (0);
			test_x++;
		}
		test_y++;
	}
	return (1);
}

int			place_piece(t_piece *piece, t_env *env, int test_size)
{
	int				x;
	int				y;

	y = 0;
	while (y < test_size - piece->height)
	{
		x = 0;
		while (x < test_size - piece->width)
		{
			if (can_place(env, piece, x, y))
				return (1);
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
		test_size--;
	}
	return (-1);
}

void		solve(t_env *env)
{
	t_piece_list	*list;
	t_piece 		*piece;
	int				total_width;
	int				y;

	total_width = 0;
	list = list->env;
	while (list)
	{
		total_width = total_width + piece->width;
		list = list->next;
	}
	if ((tab = malloc(sizeof(*tab) * total_width)) == NULL)
		error_quit("Failed to malloc tab");
	y = 0;
	while (y < total_width)
	{
		if ((tab[y] = malloc(sizeof(**tab) * total_width)) == NULL)
			error_quit("Failed to malloc tab");
		y++;
	}
	env->tab_dimension = total_width;
	print_tab(place_piece(list, env));
}
