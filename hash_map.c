/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:05:58 by cbernot           #+#    #+#             */
/*   Updated: 2024/02/24 17:12:23 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

unsigned int	hash(char **input, unsigned int size)
{
	unsigned int	result;

	result = 0;
	while (**input && **input != '\n')
	{
		result += **input;
		(*input)++;
	}
	if (**input)
		**input = '\0';
	(*input)++;
	return (result % size);
}

int	handle_collisions(t_cell *hash_map, int hash_size, int index)
{
	int	offset;
	int	i;

	i = 0;
	offset = 1;
	while (hash_map[(index + offset) % hash_size].key)
	{
		offset = 1 << i;
		i++;
	}
	return ((index + offset) % hash_size);
}

char	*search(t_cell *map, int map_size, char *input, int nb_elmt)
{
	int		i;
	char	*key;
	int		index;

	i = -1;
	while (++i < nb_elmt)
	{
		key = input;
		index = hash(&input, map_size);
		if (map[index].key) //TODO comparer les deux cles
			index = handle_collisions(map, map_size, index);
		map[index].key = key;
		map[index].value = input;
		map[index].value_len = 0;
		while (*input && *input != '\n')
		{
			input++;
			map[index].value_len++;
		}
		if (*input)
			*input = '\0';
		input++;
	}
	return (input);
}

unsigned int	get_nb_elems(char *input)
{
	int				i;
	unsigned int	nb;

	i = -1;
	nb = 0;
	while (input[++i])
	{
		if (input[i] == '\n')
		{
			nb++;
			if (input[i + 1] && input[i + 1] == '\n')
				return (nb >> 1);
		}
	}
	return (nb >> 1);
}

unsigned int	get_map_size(unsigned int nb)
{
	unsigned int	i;

	i = 1;
	while (i <= nb)
		i *= 2;
	return (i);
}
