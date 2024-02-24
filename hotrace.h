/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:09:38 by qpupier           #+#    #+#             */
/*   Updated: 2024/02/24 20:37:14 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stdio.h> // TODO TO DELETE
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

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


// GNL part
t_pair	get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_pair	ft_free_stash(char **stash, int create_line);

t_pair			*ft_realloc(t_pair *datas, int old_size, int new_size);
void			copy(char *buf, char *datas, int begin, int count);
void			ft_putstr_endl(char *s, int len);

char			*search(t_cell *map, int map_size, char *input, int nb_elmt);
int				handle_collisions(t_cell *hash_map, int hash_size, int index);
unsigned int	hash(t_pair *input, unsigned int size, unsigned short int pos);
unsigned int	get_map_size(unsigned int nb);
// unsigned int	get_nb_elems(char *input);

t_pair	create_pair(char *str, unsigned int len);

#endif