/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 07:17:59 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/03 11:12:06 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	valid_sharps(char *data)
{
	int		links;
	int		i;

	links = 0;
	i = 0;
	while (data[i])
	{
		if (data[i] == '#')
		{
			if (i % 5 > 0 && data[i - 1] == '#')
				links++;
			if (i % 5 < 3 && data[i + 1] == '#')
				links++;
			if (i / 5 > 0 && data[i - 5] == '#')
				links++;
			if (i / 5 < 3 && data[i + 5] == '#')
				links++;
		}
		i++;
	}
	return (links >= 6);
}

int			is_valid_piece(char *data)
{
	int		sharp_count;
	int		i;

	sharp_count = 0;
	i = 0;
	while (data[i])
	{
		if (data[i] == '#')
			sharp_count++;
		if (i == 4 || i == 9 || i == 14 || i == 19)
		{
			if (data[i] != '\n')
				return (0);
		}
		else if (data[i] != '.' && data[i] != '#')
			return (0);
		i++;
	}
	return (sharp_count == 4 && valid_sharps(data));
}
