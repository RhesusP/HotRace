/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:09:38 by qpupier           #+#    #+#             */
/*   Updated: 2024/02/25 23:22:00 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 64
# define ALLOC_SIZE 1

typedef struct s_pair
{
	char			*str;
	unsigned int	len;
}	t_pair;

typedef struct s_cell
{
	t_pair	key;
	t_pair	value;
}	t_cell;

void			copy(char *buf, char *datas, unsigned int begin, \
		unsigned int count);
void			ft_putstr_endl(char *s, unsigned int len);
void			insert(t_pair *input, t_cell *map, unsigned int elems, \
		unsigned int map_size);
void			search(t_cell *map, unsigned int map_size);
t_pair			*ft_free_str(char **str, t_pair *ret);
t_pair			*ft_realloc(t_pair *datas, unsigned int old_size, \
		unsigned int new_size);
t_pair			*reading(unsigned int *position);
char			*ft_strndup(const char *s1, unsigned int n);
t_pair			gnl_std_input(void);
unsigned int	dif(t_pair a, t_pair b);
unsigned int	get_map_size(unsigned int nb);
unsigned int	handle_collisions(t_cell *hash_map, unsigned int hash_size, \
		unsigned int index);
unsigned int	hash(t_pair pair, unsigned int size);
int				ft_strcmp(const char *s1, const char *s2);
int				handle_collisions_search(t_cell *hash_map, \
		unsigned int hash_size, unsigned int index, t_pair key);

#endif