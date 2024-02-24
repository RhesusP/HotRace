/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:04:20 by cbernot           #+#    #+#             */
/*   Updated: 2024/02/24 19:08:57 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static t_pair	ft_copy_to_stash(char *stash, char *buf)
{
	char	*temp;
	// char	*res;
	t_pair	res;

	res = (t_pair){0, 0};
	if (!stash && buf)
	{
		res.str = ft_strdup(buf);
		if (!res.str)
			return (ft_free_stash(&res.str, 0));
		return (res);
	}
	temp = ft_strdup(stash);
	if (!temp)
	{
		ft_free_stash(&stash, 0);
		return (ft_free_stash(&temp, 0));
	}
	ft_free_stash(&stash, 0);
	res.str = ft_strjoin(temp, buf);
	if (!res.str)
		ft_free_stash(&res.str, 0);
	ft_free_stash(&temp, 0);
	return (res);
}

static int	ft_have_nl(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static t_pair ft_extract_line(char *stash)
{
	// char	*line;
	t_pair res;
	size_t	i;
	size_t	j;

	i = 0;
	if (!stash)
		return (ft_free_stash(&stash, 0));
	while (stash[i] != '\n')
		i++;
	res.str = malloc(sizeof(char) * (i + 2));
	if (!res.str)
		return (ft_free_stash(&res.str, 0));
	j = 0;
	while (j < i + 1)
	{
		res.str[j] = stash[j];
		j++;
	}
	res.str[j] = '\0';
	return (res);
}

static t_pair	ft_recreate_stash(char *stash)
{
	size_t	i;
	t_pair	res;

	i = 0;
	if (!stash)
		return ((t_pair){0, 0});
	while (stash[i] != '\n')
		i++;
	if (stash[i + 1] == '\0')
		return (ft_free_stash(&stash, 0));
	res.str = ft_substr(stash, i + 1, ft_strlen(stash));
	if (!res.str)
	{
		ft_free_stash(&stash, 0);
		return ((t_pair){0, 0});
	}
	ft_free_stash(&stash, 0);
	return (res);
}

t_pair	get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	long		ret;
	static t_pair	pair = {0, 0};
	int sum;
	char		*line;

	sum = 0;
	line = 0;
	ret = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free_stash(&pair.str, 0));
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		sum += ret;
		if ((ret <= 0 && !pair.str) || ret == -1)
			return (ft_free_stash(&pair.str, 0));
		buf[ret] = '\0';
		pair.str = ft_copy_to_stash(pair.str, buf).str;
		if (ft_have_nl(pair.str))
		{
			line = ft_extract_line(pair.str).str;
			if (!line)
				return (ft_free_stash(&pair.str, 0));
			return (pair = ft_recreate_stash(pair.str), (t_pair){line, sum});
		}
	}
	return (ft_free_stash(&(pair.str), 1));
}
