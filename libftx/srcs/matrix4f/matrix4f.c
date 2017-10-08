/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 16:50:44 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/07 17:20:57 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

#include <stdlib.h>
#include <math.h>

t_matrix4f		*new_matrix4f(void)
{
	int			x;
	int			y;
	t_matrix4f	*m;

	if (!(m = (t_matrix4f*)malloc(sizeof(struct s_matrix4f))))
		return (NULL);
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			m->matrix[x][y] = 0;
			y++;
		}
		x++;
	}
	return (m);
}

t_matrix4f		*copy_matrix4f(t_matrix4f *origin)
{
	t_matrix4f	*dst;
	int			x;
	int			y;

	if (!(dst = new_matrix4f()))
		return (NULL);
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			dst->matrix[x][y] = origin->matrix[x][y];
			y++;
		}
		x++;
	}
	return (dst);
}

void			destruct_matrix4f(t_matrix4f *m)
{
	free(m);
}

t_matrix4f		*matrix4f_identity(void)
{
	t_matrix4f	*i;

	i = new_matrix4f();
	i->matrix[0][0] = 1;
	i->matrix[1][1] = 1;
	i->matrix[2][2] = 1;
	i->matrix[3][3] = 1;
	return (i);
}

t_matrix4f		*matrix4f_mul(t_matrix4f *m, t_matrix4f *m2)
{
	t_matrix4f	*res;
	int			x;
	int			y;

	res = new_matrix4f();
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			res->matrix[x][y] = m->matrix[x][0] * m2->matrix[0][y] +
								m->matrix[x][1] * m2->matrix[1][y] +
								m->matrix[x][2] * m2->matrix[2][y] +
								m->matrix[x][3] * m2->matrix[3][y];
			y++;
		}
		x++;
	}
	return (res);
}
/*
t_matrix4f		*init_screen_space(float width, float height)
{
	t_matrix4f	*m;

	m = new_matrix4f();
	m->matrix[0][0] = width / 2.0f;
	m->matrix[0][1] = 0;
	m->matrix[0][2] = 0;
	m->matrix[0][3] = (width / 2.0f) - 0.5f;
	m->matrix[1][0] = 0;
	m->matrix[1][1] = -(height / 2.0f);
	m->matrix[1][2] = 0;
	m->matrix[1][3] = (height / 2.0f) - 0.5f;
	m->matrix[2][0] = 0;
	m->matrix[2][1] = 0;
	m->matrix[2][2] = 1;
	m->matrix[2][3] = 0;
	m->matrix[3][0] = 0;
	m->matrix[3][1] = 0;
	m->matrix[3][2] = 0;
	m->matrix[3][3] = 1;
	return (m);
}

t_matrix4f		*build_transform(float width, float height, t_vector3f *campos, t_vector3f *camrot, t_vector3f *scale)
{
	t_matrix4f	*projection;
	t_matrix4f	*translation;
	t_matrix4f	*rotation;
	t_matrix4f	*mscale;
	t_matrix4f	*transform;

	projection = init_perspective(70.0f, width / height, 0.1f, 1000.0f);
	translation = init_translation(campos->x, campos->y, campos->z);
	rotation = init_rotation(camrot->x, camrot->y, camrot->z);
	mscale = init_scale(scale->x, scale->y, scale->z);
	transform = matrix4f_mul(matrix4f_mul(projection, matrix4f_mul(translation, rotation)), mscale);
	return (transform);
}*/

t_vector3f  *apply_matrix4f_to_vertex(t_matrix4f *m, t_vector3f *v)
{
    t_vector3f *dst;

    dst = new_vector3f(0,0,0);
	dst->x = v->x*m->matrix[0][0] + v->y*m->matrix[0][1]\
		+ v->z*m->matrix[0][2] + m->matrix[0][3];
	dst->y = v->x*m->matrix[1][0] + v->y*m->matrix[1][1]\
		+ v->z*m->matrix[1][2] + m->matrix[1][3];
	dst->z = v->x*m->matrix[2][0] + v->y*m->matrix[2][1]\
		+ v->z*m->matrix[2][2] + m->matrix[2][3];
    return (dst);
}
