/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_place.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 09:19:36 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/05 11:09:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAN_PLACE_H
# define FT_CAN_PLACE_H

# include "piece.h"
# include "env.h"

int	can_place(t_env *env, t_piece *piece, int x, int y);

#endif
