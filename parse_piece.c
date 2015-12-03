/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 08:56:08 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/03 10:52:00 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "piece.h"

static int		get_min_x(char *data)
{
	int		min_x;
	int		i;

	min_x = -1;
	i = -1;
	while (data[++i])
	{
		if (data[i] == '#')
		{
			if (min_x == -1 || i % 5 < min_x)
				min_x = i % 5;
		}
	}
	return (min_x);
}

static int		get_min_y(char *data)
{
	int		min_y;
	int		i;

	min_y = -1;
	i = -1;
	while (data[++i])
	{
		if (data[i] == '#')
		{
			if (min_y == -1 || i / 5 < min_y)
				min_y = i / 5;
		}
	}
	return (min_y);
}

static void		get_data(t_piece *piece, char *data)
{
	int		min_x;
	int		min_y;
	int		x;
	int		y;

	min_x = get_min_x(data);
	min_y = get_min_y(data);
	x = 0;
	while (x < piece->width)
	{
		y = 0;
		while (y < piece->height)
		{
			piece->data[y][x] = data[(min_y + y) * 5 + min_x + x];
			y++;
		}
		x++;
	}
}

static void		get_dimensions(t_piece *piece, char *data)
{
	int		min_x;
	int		max_x;
	int		min_y;
	int		max_y;
	int		i;

	min_x = -1;
	max_x = -1;
	min_y = -1;
	max_y = -1;
	i = -1;
	while (data[++i])
		if (data[i] == '#')
		{
			if (min_x == -1 || i % 5 < min_x)
				min_x = i % 5;
			if (max_x == -1 || i % 5 > max_x)
				max_x = i % 5;
			if (min_y == -1 || i / 5 < min_y)
				min_y = i / 5;
			if (max_y == -1 || i / 5 > max_y)
				max_y = i / 5;
		}
	piece->width = max_x - min_x + 1;
	piece->height = max_y - min_y + 1;
}

t_piece			*parse_piece(char *data)
{
	t_piece		*piece;
	int			y;

	if (!(piece = malloc(sizeof(*piece))))
		return (NULL);
	get_dimensions(piece, data);
	if (!(piece->data = malloc(sizeof(*(piece->data)) * piece->height)))
		return (NULL);
	y = 0;
	while (y < piece->height)
	{
		if (!(piece->data[y] = malloc(sizeof(**(piece->data)) * piece->width)))
			return (NULL);
		y++;
	}
	get_data(piece, data);
	return (piece);
}
