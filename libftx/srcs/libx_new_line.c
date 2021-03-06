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

t_libx_line			*libx_new_line(t_libx_img *img, t_vector3f *v1,
	t_vector3f *v2, int color)
{
	t_libx_line	*line;

	if ((line = (t_libx_line*)malloc(sizeof(t_libx_line))) == NULL)
		return (NULL);
	line->img = img;
	line->x1 = v1->x;
	line->y1 = v1->y;
	line->x2 = v2->x;
	line->y2 = v2->y;
	line->color = color;
	return (line);
}
