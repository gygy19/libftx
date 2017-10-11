/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 13:38:48 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/09 13:38:50 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <fcntl.h>
#include <unistd.h>

char	*load_file(char *filename)
{
	int		fd;
	int		ret;
	char	buffer[100];
	char	*result;

	if ((fd = open(filename, O_RDWR)) < 3)
		return (NULL);
	if (!(result = ft_strnew(0)))
		return (NULL);
	while ((ret = read(fd, buffer, 99)) > 0)
	{
		buffer[ret] = '\0';
		result = ft_dstrjoin(result, buffer, 1);
	}
	close(fd);
	return (result);
}
