/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:50:54 by qpupier           #+#    #+#             */
/*   Updated: 2024/02/24 16:16:50 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static char	*ft_realloc(char *datas, int old_size, int new_size)
{
	char	*new;
	int		i;

	new = malloc(sizeof(char) * new_size);
	if (!new)
		return (NULL);
	if (!datas)
		return (new);
	i = -1;
	while (++i < old_size)
		new[i] = datas[i];
	free(datas);
	return (new);
}

static void	copy(char *buf, char *datas, int begin, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		datas[begin + i] = buf[i];
	free(buf);
}

static char	*get_input(void)
{
	int		size;
	int		old_size;
	int		size_read;
	int		count;
	char	*datas;
	char	*buf;

	size = 16;
	old_size = 0;
	size_read = size - old_size;
	count = size_read;
	datas = NULL;
	while (count == size_read)
	{
		if (datas)
		{
			old_size = size;
			size *= 2;
			size_read = size - old_size;
		}
		// printf("[%d](%d)\n", size, size_read);
		datas = ft_realloc(datas, old_size, size);
		if (!datas)
			return (NULL);
		buf = malloc(sizeof(char) * size_read);
		if (!buf)
			return (NULL);
		count = read(0, buf, size_read);
		// printf("\033[33m%s\n\033[0m", buf);
		copy(buf, datas, size - size_read, count);
	}
	// printf("\n[%d]\n\033[31m%s\n", size, datas);
	return (datas);
}

static unsigned int	get_nb_elems(char *input)
{
	int	i;
	unsigned int	nb;

	i = -1;
	nb = 0;
	while (input[++i])
		if (input[i] == '\n')
		{
			nb++;
			if (input[i + 1] && input[i + 1] == '\n')
				return (nb * 0.5);
		}
	return (nb * 0.5);
}

static unsigned int	get_map_size(unsigned int nb)
{
	unsigned int	i;

	i = 1;
	while (i <= nb)
		i *= 2;
	return (i);
}

static unsigned int	hash(char **input, unsigned int size)
{
	unsigned int	result;

	result = 0;
	while (**input && **input != '\n')
	{
		// printf("%c", **input);
		result += **input;
		(*input)++;
	}
	if (**input)
		**input = '\0';
	(*input)++;
	// printf("%d %% %d = %d\n", result, size, result % size);
	return (result % size);
}

int	main(void)
{
	char	*input;
	unsigned int	nb;
	unsigned int	map_size;
	int	i;
	int index;
	t_cell	*map;
	char	*key;

	input = get_input();
	if (!input)
		return (EXIT_FAILURE);
	nb = get_nb_elems(input);
	map_size = get_map_size(nb);
	// printf("%d -> %d\n", nb, map_size);
	map = malloc(sizeof(t_cell) * map_size);
	if (!map)
		return (EXIT_FAILURE);
	i = -1;
	while (++i < (int)nb)
	{
		key = input;
		index = hash(&input, map_size);
		// printf("\033[34m%s\033[0m\n", input);
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
	input++;
	while (*input)
	{
		index = hash(&input, map_size);
		printf("%s\n", map[index].value);
	}
	return (EXIT_SUCCESS);
}
