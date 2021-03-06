/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 06:50:27 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/05 08:46:34 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENV_H
# define FT_ENV_H

# include "piece_list.h"

typedef struct		s_env
{
	t_piece_list	*pieces;
	char			**tab;
	int				tab_dimensions;
}					t_env;

#endif
