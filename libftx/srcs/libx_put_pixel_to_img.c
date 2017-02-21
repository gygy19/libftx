/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx_put_pixel_to_img.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:38:10 by jguyet            #+#    #+#             */
/*   Updated: 2016/08/21 00:38:51 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

void		libx_put_pixel_to_img(t_libx_img *img, int x, int y, int c)
{
	char	*ptr_color;

	if (img == NULL || x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	ptr_color = img->addr + (x * (img->bits_per_pixel >> 3)
			+ y * img->size_line);
	ptr_color[0] = (c >> 0x00) & 0xFF;
	ptr_color[1] = (c >> 0x08) & 0xFF;
	ptr_color[2] = (c >> 0x10) & 0xFF;
}
