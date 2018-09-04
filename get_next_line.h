/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <beborch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 18:15:38 by beborch           #+#    #+#             */
/*   Updated: 2018/09/04 03:29:30 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE (64)

# include "libft/libft.h"
# include <unistd.h>
# include <string.h>

typedef struct	s_gnl
{
	char		buff[BUFF_SIZE];
	char		*str;
	char		*tmp;
	int			ret;
	int			ended;
	int			put_in;
	int			i;
	int			j;
	int			k;
}				t_gnl;

int				get_next_line(const int fd, char **line);

#endif
