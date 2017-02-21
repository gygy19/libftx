/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx_new_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 01:12:40 by jguyet            #+#    #+#             */
/*   Updated: 2016/08/21 01:17:06 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

#include <stdlib.h>

t_libx_line			*libx_new_line(t_libx_img *img, int *datax,
		int *datay, int color)
{
	t_libx_line	*line;

	if ((line = (t_libx_line*)malloc(sizeof(t_libx_line))) == NULL)
		return (NULL);
	line->img = img;
	line->x1 = datax[0];
	line->y1 = datay[0];
	line->x2 = datax[1];
	line->y2 = datay[1];
	line->color = color;
	return (line);
}
