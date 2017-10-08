/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_mult.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 20:34:06 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/08 20:34:07 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

static void		mult_translation(t_transform *t)
{
	t_matrix4f	*tmp;

	if (t->translation != NULL)
	{
		tmp = matrix4f_mul(t->matrix, t->translation);
		destruct_matrix4f(t->matrix);
		t->matrix = tmp;
	}
}

static void		mult_rotation(t_transform *t)
{
	t_matrix4f	*tmp;

	if (t->rotation != NULL)
	{
		tmp = matrix4f_mul(t->matrix, t->rotation);
		destruct_matrix4f(t->matrix);
		t->matrix = tmp;
	}
}

static void		mult_scale(t_transform *t)
{
	t_matrix4f	*tmp;

	if (t->scale != NULL)
	{
		tmp = matrix4f_mul(t->matrix, t->scale);
		destruct_matrix4f(t->matrix);
		t->matrix = tmp;
	}
}

t_transform		*build_transform(t_transform *t)
{
	t->projection = init_perspective(t->fov, t->aspect_ratio, t->near, t->far);
	if (t->vpos != NULL)
		t->translation = init_translation(t->vpos->x, t->vpos->y, t->vpos->z);
	if (t->vrot != NULL)
		t->rotation = init_rotation(t->vrot->x, t->vrot->y, t->vrot->z);
	if (t->vscale != NULL)
		t->scale = init_scale(t->vscale->x, t->vscale->y, t->vscale->z);
	t->matrix = copy_matrix4f(t->projection);
	mult_rotation(t);
	mult_scale(t);
	mult_translation(t);
	if (t->projection != NULL)
		destruct_matrix4f(t->projection);
	if (t->translation != NULL)
		destruct_matrix4f(t->translation);
	if (t->scale != NULL)
		destruct_matrix4f(t->scale);
	if (t->rotation != NULL)
		destruct_matrix4f(t->rotation);
	return (t);
}
