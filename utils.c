/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:59:13 by cbernot           #+#    #+#             */
/*   Updated: 2024/02/24 17:22:48 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*ft_realloc(char *datas, int old_size, int new_size)
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
