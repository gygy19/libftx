/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx_new_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:39:16 by jguyet            #+#    #+#             */
/*   Updated: 2016/08/21 00:39:18 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

#include <mlx.h>
#include <stdlib.h>

t_libx_img	*libx_new_img(void *mlx, int width, int height)
{
	t_libx_img	*img;

	if ((img = (t_libx_img *)malloc(sizeof(t_libx_img))) == NULL)
		return (NULL);
	img->width = width;
	img->height = height;
	img->img_ptr = mlx_new_image(mlx, width, height);
	if (img->img_ptr == NULL)
	{
		free(img);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->img_ptr,
			&(img->bits_per_pixel), &(img->size_line), &(img->endian));
	return (img);
}
