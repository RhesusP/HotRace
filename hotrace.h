/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:09:38 by qpupier           #+#    #+#             */
/*   Updated: 2024/02/24 18:06:20 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stdio.h> // TODO TO DELETE
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_cell
{
	char			*key;
	char			*value;
	unsigned int	value_len;
}	t_cell;

// GNL part
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_free_stash(char **stash, int create_line);

char			*ft_realloc(char *datas, int old_size, int new_size);
void			copy(char *buf, char *datas, int begin, int count);
void			ft_putstr_endl(char *s, int len);

char			*search(t_cell *map, int map_size, char *input, int nb_elmt);
int				handle_collisions(t_cell *hash_map, int hash_size, int index);
unsigned int	hash(char **input, unsigned int size);
unsigned int	get_map_size(unsigned int nb);
unsigned int	get_nb_elems(char *input);

#endif