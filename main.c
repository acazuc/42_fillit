/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 06:48:46 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/09 11:59:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error_quit.h"
#include "solve.h"
#include "load.h"

int		main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
		error_quit("error");
	if (!(env = malloc(sizeof(*env))))
		error_quit("error");
	env->pieces = NULL;
	load(env, av[1]);
	solve(env);
}
