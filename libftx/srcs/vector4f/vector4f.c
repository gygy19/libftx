/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 16:45:08 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/07 17:17:39 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

#include <stdlib.h>
#include <math.h>

t_vector4f		*new_vector4f(float x, float y, float z, float w)
{
	t_vector4f	*v;

	if (!(v = (t_vector4f*)malloc(sizeof(struct s_vector4f))))
		return (NULL);
	v->x = x;
	v->y = y;
	v->z = z;
	v->w = w;
	return (v);
}

void			destruct_vector4f(t_vector4f *v)
{
	free(v);
}

float			v4f_sqrt(t_vector4f *v)
{
	return (v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
}

float			v4f_magnitude(t_vector4f *v)
{
	return ((float)sqrt(v4f_sqrt(v)));
}

t_vector4f		*v4f_normalize(t_vector4f *v)
{
	float	mag;

	mag = v4f_magnitude(v);
	v->x /= mag;
	v->y /= mag;
	v->z /= mag;
	v->w /= mag;
	return (v);
}
