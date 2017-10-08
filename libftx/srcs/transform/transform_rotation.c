/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 21:14:13 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/08 21:14:15 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

#include <math.h>

static void		rotate_x(t_matrix4f *m, float x)
{
	m->matrix[0][0] = 1;
	m->matrix[1][1] = (float)cos(x);
	m->matrix[1][2] = -(float)sin(x);
	m->matrix[2][1] = (float)sin(x);
	m->matrix[2][2] = (float)cos(x);
	m->matrix[3][3] = 1;
}

static void		rotate_y(t_matrix4f *m, float y)
{
	m->matrix[0][0] = (float)cos(y);
	m->matrix[0][2] = -(float)sin(y);
	m->matrix[1][1] = 1;
	m->matrix[2][0] = (float)sin(y);
	m->matrix[2][2] = (float)cos(y);
	m->matrix[3][3] = 1;
}

static void		rotate_z(t_matrix4f *m, float z)
{
	m->matrix[0][0] = (float)cos(z);
	m->matrix[0][1] = -(float)sin(z);
	m->matrix[1][0] = (float)sin(z);
	m->matrix[1][1] = (float)cos(z);
	m->matrix[2][2] = 1;
	m->matrix[3][3] = 1;
}

t_matrix4f		*init_rotation(float x, float y, float z)
{
	t_matrix4f	*rx;
	t_matrix4f	*ry;
	t_matrix4f	*rz;
	t_matrix4f	*m;

	rx = new_matrix4f();
	ry = new_matrix4f();
	rz = new_matrix4f();
	rotate_x(rx, x);
	rotate_y(ry, y);
	rotate_z(rz, z);
	m = matrix4f_mul(rz, matrix4f_mul(ry, rx));
	destruct_matrix4f(rx);
	destruct_matrix4f(ry);
	destruct_matrix4f(rz);
	return (m);
}
