/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:50:54 by qpupier           #+#    #+#             */
/*   Updated: 2024/02/24 19:04:17 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

// static char	*get_input(void)
// {
// 	int		size;
// 	int		old_size;
// 	int		size_read;
// 	int		count;
// 	char	*datas;
// 	char	*buf;

// 	size = 16;
// 	old_size = 0;
// 	size_read = size - old_size;
// 	count = size_read;
// 	datas = NULL;
// 	while (count == size_read)
// 	{
// 		if (datas)
// 		{
// 			old_size = size;
// 			size = size << 1;
// 			size_read = size - old_size;
// 		}
// 		datas = ft_realloc(datas, old_size, size);
// 		if (!datas)
// 			return (NULL);
// 		buf = malloc(sizeof(char) * size_read);
// 		if (!buf)
// 			return (NULL);
// 		count = read(0, buf, size_read);
// 		copy(buf, datas, size - size_read, count);
// 	}
// 	return (datas);
// }

int	main(void)
{
	// char *input;
	t_pair pair;

	pair = get_next_line(STDIN_FILENO);
	printf("%s\n%u\n", pair.str, pair.len);

	// input = get_next_line(STDIN_FILENO);
	// printf("%s\n", input);

	// char			*input;
	// unsigned int	nb;
	// unsigned int	map_size;
	// int				index;
	// t_cell			*map;



	// input = get_input();
	// if (!input)
	// 	return (EXIT_FAILURE);
	// nb = get_nb_elems(input);
	// map_size = get_map_size(nb) + 1;
	// map = malloc(sizeof(t_cell) * map_size);
	// if (!map)
	// {
	// 	free(input);
	// 	return (EXIT_FAILURE);
	// }
	// input = search(map, map_size, input, nb);
	// input++;
	// while (*input)
	// {
	// 	index = hash(&input, map_size);
	// 	ft_putstr_endl(map[index].value, map[index].value_len);
	// }
	// // free(input);
	// free(map);
	return (EXIT_SUCCESS);
}
