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

t_matrix4f		*init_view_orientation(t_vector3f *side, t_vector3f *up, t_vector3f *forward)
{
	t_matrix4f	*m;

	m = new_matrix4f();
	m->matrix[0][0] = side->x;
	m->matrix[0][1] = up->x;
	m->matrix[0][2] = -forward->x;
	m->matrix[0][3] = 0;
	m->matrix[1][0] = side->y;
	m->matrix[1][1] = up->y;
	m->matrix[1][2] = -forward->y;
	m->matrix[1][3] = 0;
	m->matrix[2][0] = side->z;
	m->matrix[2][1] = up->z;
	m->matrix[2][2] = -forward->z;
	m->matrix[2][3] = 0;
	m->matrix[3][0] = 0;
	m->matrix[3][1] = 0;
	m->matrix[3][2] = 0;
	m->matrix[3][3] = 1;
	return (m);
}