/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx_draw_line_to_img.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:39:38 by jguyet            #+#    #+#             */
/*   Updated: 2016/08/21 00:39:39 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

#include <stdlib.h>
#include <stdio.h>

static void		s_print_line(t_libx_line *line, int dir[4], int ls[2])
{
	int		num;
	int		i;

	num = ls[0] >> 1;
	i = 0;
	while (i < ls[0])
	{
		libx_put_pixel_to_img(line->img, line->x1, line->y1, line->color);
		num += ls[1];
		if (num >= ls[0])
		{
			num -= ls[0];
			line->x1 += dir[0];
			line->y1 += dir[1];
		}
		else
		{
			line->x1 += dir[2];
			line->y1 += dir[3];
		}
		++i;
	}
}

static int		*s_set_long_short(int ls[2], int dir[4], int w, int h)
{
	ls[0] = (w < 0) ? w * -1 : w;
	ls[1] = (h < 0) ? h * -1 : h;
	if (ls[0] <= ls[1])
	{
		ls[0] = (h < 0) ? h * -1 : h;
		ls[1] = (w < 0) ? w * -1 : w;
		if (h < 0)
			dir[3] = -1;
		if (h > 0)
			dir[3] = 1;
		dir[2] = 0;
	}
	return (ls);
}

static void		s_set_direction(int dir[4], int w, int h)
{
	dir[0] = 0;
	dir[1] = 0;
	dir[2] = 0;
	dir[3] = 0;
	if (w < 0)
		dir[0] = -1;
	if (w > 0)
		dir[0] = 1;
	if (h < 0)
		dir[1] = -1;
	if (h > 0)
		dir[1] = 1;
	if (w < 0)
		dir[2] = -1;
	if (w > 0)
		dir[2] = 1;
}

void			libx_draw_line_to_img(t_libx_line *line)
{
	int		w;
	int		h;
	int		dir[4];
	int		ls[2];

	if (line == NULL)
		return ;
	w = line->x2 - line->x1;
	h = line->y2 - line->y1;
	s_set_direction(dir, w, h);
	s_set_long_short(ls, dir, w, h);
	s_print_line(line, dir, ls);
	free(line);
}
