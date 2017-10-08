/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 18:57:18 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/08 18:57:19 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

#include <stdlib.h>

t_transform	*new_transform(void)
{
	t_transform	*t;

	if (!(t = (t_transform*)malloc(sizeof(struct s_transform))))
		return (NULL);
	t->fov = 70.0f;
	t->aspect_ratio = 0;
	t->near = 0.1f;
	t->far = 1000.0f;
	t->projection = NULL;
	t->translation = NULL;
	t->rotation = NULL;
	t->scale = NULL;
	t->vpos = NULL;
	t->vrot = NULL;
	t->vscale = NULL;
	return (t);
}

void		destruct_transform(t_transform *t)
{
	if (t->matrix != NULL)
		destruct_matrix4f(t->matrix);
	free(t);
}

void		set_transform_window_size(t_transform *t, float width,\
			float height)
{
	t->aspect_ratio = width / height;
}

t_vector3f	*apply_transform(t_transform *t, t_vector3f *v)
{
	return (apply_matrix4f_to_vertex(t->matrix, v));
}
