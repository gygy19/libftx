/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_perspective.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 21:17:36 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/08 21:17:38 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

#include <math.h>

t_matrix4f	*init_perspective(float fov, float aspect_ratio,\
			float near, float far)
{
	float		z_range;
	t_matrix4f	*m;

	z_range = near - far;
	fov = (float)tan(ft_radians(fov / 2.0f));
	m = new_matrix4f();
	m->matrix[0][0] = 1.0f / (fov * aspect_ratio);
	m->matrix[1][1] = 1.0f / fov;
	m->matrix[2][2] = (-near - far) / z_range;
	m->matrix[2][3] = 2 * far * near / z_range;
	m->matrix[3][2] = 1;
	return (m);
}
