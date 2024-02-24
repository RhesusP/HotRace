/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:59:13 by cbernot           #+#    #+#             */
/*   Updated: 2024/02/24 20:05:06 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_pair	*ft_realloc(t_pair *datas, int old_size, int new_size)
{
	t_pair	*new;
	int		i;

	new = malloc(sizeof(t_pair) * new_size);
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

void	copy(char *buf, char *datas, int begin, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		datas[begin + i] = buf[i];
	free(buf);
}

void	ft_putstr_endl(char *s, int len)
{
	if (!s)
		return ;
	write(STDOUT_FILENO, s, len);
	write(STDOUT_FILENO, "\n", 1);
}