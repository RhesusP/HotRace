/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:50:54 by qpupier           #+#    #+#             */
/*   Updated: 2024/02/25 23:23:31 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static void	init_map(t_cell *map, unsigned int size)
{
	int	i;

	i = -1;
	while (++i < (int)size)
		map[i] = (t_cell){(t_pair){"", 0}, (t_pair){"", 0}};
}

int	free_and_return(t_pair **input, unsigned int position, int ret)
{
	unsigned int	i;

	i = 0;
	while (i < position)
		free((*input)[i++].str);
	free(*input);
	return (ret);
}

int	main(int argc, char **argv)
{
	t_pair			*input;
	unsigned int	map_size;
	t_cell			*map;
	unsigned int	position;

	(void)argv;
	if (argc != 1)
		return (EXIT_FAILURE);
	input = reading(&position);
	if (!input)
		return (EXIT_FAILURE);
	map_size = get_map_size(position >> 1) + 1;
	map = malloc(sizeof(t_cell) * map_size);
	if (!map)
		return (free_and_return(&input, position, EXIT_FAILURE));
	init_map(map, map_size);
	insert(input, map, position, map_size);
	search(map, map_size);
	free(map);
	return (free_and_return(&input, position, EXIT_SUCCESS));
}
