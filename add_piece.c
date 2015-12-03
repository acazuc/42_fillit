/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 07:05:09 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/03 11:35:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "is_valid_piece.h"
#include "parse_piece.h"
#include "error_quit.h"
#include "piece_list.h"
#include "piece.h"
#include "env.h"

void	add_piece(t_env *env, char *data)
{
	t_piece_list	*list;
	t_piece_list	*new;
	t_piece			*piece;

	if (!is_valid_piece(data))
		error_quit("Invalid piece");
	if (!(piece = parse_piece(data)))
		error_quit("Error while parsing piece");
	if (!(new = malloc(sizeof(*new))))
		error_quit("Failed to malloc new list");
	new->next = NULL;
	new->piece = piece;
	list = env->pieces;
	if (!list)
		env->pieces = new;
	else
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
}
