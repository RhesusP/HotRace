/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:59:13 by cbernot           #+#    #+#             */
/*   Updated: 2024/02/25 23:27:13 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_pair	*ft_realloc(t_pair *datas, unsigned int old_size, unsigned int new_size)
{
	t_pair			*new;
	unsigned int	i;

	new = malloc(sizeof(t_pair) * new_size);
	if (!new)
	{
		free(datas);
		return (NULL);
	}
	if (!datas)
		return (new);
	i = 0;
	while (i < old_size)
	{
		new[i] = datas[i];
		i++;
	}
	free(datas);
	return (new);
}

void	copy(char *buf, char *datas, unsigned int begin, unsigned int count)
{
	unsigned int	i;

	i = 0;
	while (i < count)
	{
		datas[begin + i] = buf[i];
		i++;
	}
	free(buf);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

t_pair	*ft_free_str(char **str, t_pair *ret)
{
	free(*str);
	return (ret);
}

char	*ft_strndup(const char *s1, unsigned int n)
{
	char			*res;
	unsigned int	i;

	res = malloc(sizeof(char) * (n + 1));
	if (!res)
		return (res);
	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
