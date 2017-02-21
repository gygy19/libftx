/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:27:38 by jguyet            #+#    #+#             */
/*   Updated: 2016/08/21 00:37:38 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTX_H
# define LIBFTX_H
# include <unistd.h>
/*
**STRUCT libx
*/
typedef struct	s_libx_img
{
	void		*img_ptr;
	int			width;
	int			height;
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_libx_img;

typedef struct	s_libx_line
{
	t_libx_img	*img;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			color;
}				t_libx_line;

t_libx_img		*libx_new_img(void *mlx, int width, int height);

t_libx_line		*libx_new_line(t_libx_img *img, int *datax, int *datay, int color);

void			libx_draw_line_to_img(t_libx_line *line);

void			libx_put_pixel_to_img(t_libx_img *img, int x, int y, int color);


#endif
