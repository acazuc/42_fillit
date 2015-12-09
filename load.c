/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 06:50:08 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/09 09:09:10 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "error_quit.h"
#include "add_piece.h"
#include "env.h"

void		check_pieces_number(t_env *env)
{
	t_piece_list	*list;
	int				count;

	list = env->pieces;
	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	if (count > 26)
		error_quit("Maximum of 26 pieces");
}

void		load(t_env *env, char *file)
{
	char			*buffer;
	int				prev_readed;
	int				readed;
	int				fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		error_quit("Failed to open file");
	if (!(buffer = malloc(sizeof(*buffer) * 21)))
		error_quit("Failed to malloc read buffer");
	while ((readed = read(fd, buffer, 21)))
	{
		buffer[20] = '\0';
		if (readed == -1)
			error_quit("Error while loading file");
		if (readed < 20)
			error_quit("Invalid file");
		else
			add_piece(env, buffer);
		prev_readed = readed;
	}
	free(buffer);
	if (readed == 0 && prev_readed != 20)
		error_quit("Invalid EOF");
}
