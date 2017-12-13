/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beborch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 23:18:25 by beborch           #+#    #+#             */
/*   Updated: 2017/12/13 01:29:43 by beborch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

int		main(int argc, char *argv[])
{
	int file;
	int ret;
	char buff[200];

	file = open (argv[1], O_RDONLY);
	ret = read(file, buff, 200);
	ft_putstr(buff);
	return (0);
}
