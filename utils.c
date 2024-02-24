/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:59:13 by cbernot           #+#    #+#             */
/*   Updated: 2024/02/24 22:41:46 by cbernot          ###   ########.fr       */
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	if (n == 0)
		return (0);
	i = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (n - 1 > 0 && us1[i] != '\0' && us2[i] != '\0' && us1[i] == us2[i])
	{
		i++;
		n--;
	}
	return (us1[i] - us2[i]);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	// if (ft_strlen(s1) != ft_strlen(s2))
	// 	return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
