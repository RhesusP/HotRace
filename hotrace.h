/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:09:38 by qpupier           #+#    #+#             */
/*   Updated: 2024/02/24 17:10:27 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stdio.h>//TO DELETE
# include <unistd.h>
# include <stdlib.h>

typedef struct s_cell
{
	char			*key;
	char			*value;
	unsigned int	value_len;
}	t_cell;

char			*ft_realloc(char *datas, int old_size, int new_size);
void			copy(char *buf, char *datas, int begin, int count);

char			*search(t_cell *map, int map_size, char *input, int nb_elmt);
int				handle_collisions(t_cell *hash_map, int hash_size, int index);
unsigned int	hash(char **input, unsigned int size);
unsigned int	get_map_size(unsigned int nb);
unsigned int	get_nb_elems(char *input);

#endif