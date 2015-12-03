/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:32:12 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/03 11:34:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

void	error_quit(char *error_message)
{
	ft_putstr("Error happened: ");
	ft_putendl(error_message);
	exit(-1);
}
