/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:09:38 by qpupier           #+#    #+#             */
/*   Updated: 2024/02/24 16:13:49 by qpupier          ###   ########lyon.fr   */
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
}t_cell;

#endif