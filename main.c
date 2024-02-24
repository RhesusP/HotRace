/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:50:54 by qpupier           #+#    #+#             */
/*   Updated: 2024/02/24 23:26:20 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static t_pair	*get_input(unsigned int *position)
{
	unsigned int	size;
	t_pair	*datas;
	t_pair	pair;

	size = 1;
	*position = 0;
	datas = NULL;
	datas = malloc(sizeof(t_pair) * size);
	if (!datas)
		return (NULL);
	while (1)
	{
		pair = get_next_line(0);
		if (pair.str)
			pair.str[pair.len - 1] = '\0';
		if (pair.len == 1)
			return (datas);
		if (*position >= size)
		{
			datas = ft_realloc(datas, size, size * 2);
			if (!datas)
				return (NULL);
			size *= 2;
		}
		datas[(*position)++] = pair;
	}
	return (datas);
}

static void	search(t_cell *map, int map_size)
{
	t_pair	pair;
	int		index;

	(void)map;

	pair = get_next_line(0);
	while (pair.len > 1)
	{
		index = hash(&pair, map_size, 0);
		if (map[index].key.len != 0)
		{
			if (ft_strcmp(map[index].key.str, pair.str))
				index = handle_collisions(map, map_size, index);
		}
		if (map[index].key.len != 0)
            ft_putstr_endl(map[index].value.str, map[index].value.len);
        else
        {
			write(STDOUT_FILENO, pair.str, pair.len - 1);
            write(STDOUT_FILENO, ": Not found.\n", 13);
        }
		free(pair.str);
		pair = get_next_line(0);
	}
}

static void	insert(t_pair *input, t_cell *map, int elems, int map_size)
{
	int	i;
	int	index;

	i = 0;
	while (i < elems)
	{
		index = hash(input, map_size, i);
		if (map[index].key.len)
			index = handle_collisions(map, map_size, index);
		// printf("%d -> %d\n", i, index);
		map[index].key = input[i++];
		map[index].value = input[i++];
	}
}

static void	init_map(t_cell *map, unsigned int size)
{
	int	i;

	i = -1;
	while (++i < (int)size)
		map[i] = (t_cell){(t_pair){"", 0}, (t_pair){"", 0}};
}

int	main(void)
{
	t_pair			*input;
	unsigned int	nb;
	unsigned int	map_size;
	t_cell			*map;
	unsigned int	position;

	input = get_input(&position);
	if (!input)
		return (EXIT_FAILURE);
	nb = position / 2;
	map_size = get_map_size(nb) + 1;
	map = malloc(sizeof(t_cell) * map_size);
	if (!map)
	{
		free(input);
		return (EXIT_FAILURE);
	}
	// printf("%d\n", map_size);
	init_map(map, map_size);
	insert(input, map, position, map_size);
	// int i = -1;
	// while (++i < (int)map_size)
	// 	printf("[%d] %s | %s\n", i, map[i].key.str, map[i].value.str);

	search(map, map_size);

	// input = search(map, map_size, input, nb);
	// while (*input)
	// {
	// 	index = hash(&input, map_size);
	// 	ft_putstr_endl(map[index].value, map[index].value_len);
	// }

	
	free(input);
	free(map);

	return (EXIT_SUCCESS);
}
