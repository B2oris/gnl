/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <beborch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 17:58:51 by beborch           #+#    #+#             */
/*   Updated: 2018/09/04 04:12:40 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*get_line(t_gnl *gnl, char *buff)
{
	char *tmp;

	gnl->i = 0;
	while ((buff[gnl->i] != '\n') && (buff[gnl->i] != '\0'))
		gnl->i++;
	gnl->str = (char*)malloc(sizeof(*gnl->str) * (gnl->i + 1));
	ft_strncpy(gnl->str, buff, gnl->i);
	gnl->str[gnl->i] = '\0';
	gnl->j = gnl->i;
	if (buff[gnl->i] == '\n')
		gnl->i++;
	tmp = ft_strsub(buff, gnl->i, (ft_strlen(buff) - gnl->j));
	free (buff);
	return (tmp);
}

static int		get_ret(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (i > 0)
		return (1);
	return (0);
}

static char	*ft_strjoin_del(char const *s1, char const *s2, int j)
{
	int		i;
	char	*str;

	if (!(s1) || !(s2))
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)ft_memalloc(sizeof(*str) * (i + 1))))
		return (NULL);
	str = ft_strcat(str, (char *)s1);
	str = ft_strcat(str, (char *)s2);
	str[i] = '\0';
	if (j == 1 || j == 3)
		free((void*)s1);
	if (j == 2 || j == 3)
		free((void*)s2);
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static char	*tmp[5000];
	t_gnl		gnl;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!tmp[fd])
		tmp[fd] = ft_strnew(0);
	while ((gnl.ret = read(fd, gnl.buff, BUFF_SIZE)) > 0)
	{
		if (gnl.ret != 0)
			gnl.buff[gnl.ret] = '\0';
		tmp[fd] = ft_strjoin_del(tmp[fd], gnl.buff, 1);
	}
	if (gnl.ret == -1)
		return (-1);
	gnl.ret = get_ret(tmp[fd]);
	if (tmp[fd][0] == '\0')
		return (0);
	tmp[fd] = get_line(&gnl, tmp[fd]);
	*line = gnl.str;
	return (gnl.ret);
}
