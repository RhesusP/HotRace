/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:05:58 by cbernot           #+#    #+#             */
/*   Updated: 2024/02/25 22:55:15 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

unsigned int	hash(t_pair pair, unsigned int size)
{
	unsigned int	hash;
	unsigned int	i;

	hash = 5381;
	i = 0;
	while (i < pair.len)
		hash = ((hash << 5) + hash) + pair.str[i++];
	return (hash % size);
}

unsigned int	dif(t_pair a, t_pair b)
{
	if (a.len != b.len)
		return (1);
	return (ft_strcmp(a.str, b.str));
}

int	handle_collisions_search(t_cell *hash_map, unsigned int hash_size, \
		unsigned int index, t_pair key)
{
	unsigned int	offset;
	unsigned int	i;

	i = 0;
	offset = 1;
	while (dif(hash_map[(index + offset) % hash_size].key, key))
	{
		if (!hash_map[(index + offset) % hash_size].key.len)
			return (-1);
		offset = 1 << i;
		i++;
	}
	return ((index + offset) % hash_size);
}

unsigned int	handle_collisions(t_cell *hash_map, unsigned int hash_size, \
		unsigned int index)
{
	unsigned int	offset;
	unsigned int	i;

	i = 0;
	offset = 1;
	while (hash_map[(index + offset) % hash_size].key.len)
	{
		offset = 1 << i;
		i++;
	}
	return ((index + offset) % hash_size);
}

unsigned int	get_map_size(unsigned int nb)
{
	unsigned int	i;

	i = 1;
	while (i <= nb)
		i = i << 1;
	return (i);
}
