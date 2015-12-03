/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 07:01:41 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/03 07:02:47 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIECE_LIST_H
# define FT_PIECE_LIST_H

# include "piece.h"

typedef struct				s_piece_list
{
	t_piece					*piece;
	struct s_piece_list		*next;
}							t_piece_list;

#endif
