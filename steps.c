/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:49:25 by qpupier           #+#    #+#             */
/*   Updated: 2024/02/25 23:27:10 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_pair	*reading(unsigned int *position)
{
	unsigned int	size;
	t_pair			*datas;
	t_pair			pair;

	size = ALLOC_SIZE;
	*position = 0;
	datas = malloc(sizeof(t_pair) * size);
	if (!datas)
		return (NULL);
	while (1)
	{
		pair = gnl_std_input();
		if (pair.len < 1)
			return (ft_free_str(&pair.str, datas));
		if (*position >= size)
		{
			datas = ft_realloc(datas, size, size << 1);
			if (!datas)
				return (ft_free_str(&pair.str, NULL));
			size = size << 1;
		}
		datas[(*position)++] = pair;
	}
	return (datas);
}

void	insert(t_pair *input, t_cell *map, unsigned int elems, \
		unsigned int map_size)
{
	unsigned int	i;
	unsigned int	index;

	i = 0;
	while (i < elems)
	{
		index = hash(input[i], map_size);
		if (map[index].key.len)
			index = handle_collisions(map, map_size, index);
		map[index].key = input[i++];
		if (i < elems)
			map[index].value = input[i++];
		else
			map[index].value = (t_pair){"", 0};
	}
}

static inline void	print_error(t_pair key)
{
	write(STDOUT_FILENO, key.str, key.len);
	write(STDOUT_FILENO, ": Not found.\n", 14);
}

static inline void	print_value(t_pair value)
{
	write(STDOUT_FILENO, value.str, value.len);
	write(STDOUT_FILENO, "\n", 2);
}

void	search(t_cell *map, unsigned int map_size)
{
	t_pair	pair;
	int		index;

	while (1)
	{
		pair = gnl_std_input();
		if (pair.len < 1)
			return ;
		index = hash(pair, map_size);
		if (!map[index].key.len)
			print_error(pair);
		else if (dif(map[index].key, pair))
		{
			index = handle_collisions_search(map, map_size, index, pair);
			if (index == -1)
				print_error(pair);
			else
				print_value(map[index].value);
		}
		else
			print_value(map[index].value);
		free(pair.str);
	}
}
