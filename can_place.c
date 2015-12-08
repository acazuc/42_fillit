/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_place.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 09:15:59 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/05 10:43:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "piece.h"
#include "env.h"

int		can_place(t_env *env, t_piece *piece, int x, int y)
{
	int		test_x;
	int		test_y;

	test_y = 0;
	while (test_y < piece->height)
	{
		test_x = 0;
		while (test_x < piece->width)
		{
			if (piece->data[test_y][test_x] != '.')
				if (env->tab[y + test_y][x + test_x] != '.')
					return (0);
			test_x++;
		}
		test_y++;
	}
	return (1);
}
