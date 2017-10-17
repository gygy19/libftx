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

/*
static void		mult_translation(t_transform *t)
{
	t_matrix4f	*tmp;

	if (t->translation != NULL)
	{
		tmp = matrix4f_mul(t->matrix, t->translation);
		destruct_matrix4f(t->matrix);
		t->matrix = tmp;
	}
}*/

/*
static void		mult_rotation(t_transform *t)
{
	t_matrix4f	*tmp;

	if (t->rotation != NULL)
	{
		tmp = matrix4f_mul(t->model, t->rotation);
		destruct_matrix4f(t->model);
		t->model = tmp;
	}
}

static void		mult_scale(t_transform *t)
{
	t_matrix4f	*tmp;

	if (t->scale != NULL)
	{
		tmp = matrix4f_mul(t->model, t->scale);
		destruct_matrix4f(t->model);
		t->model = tmp;
	
	}
}
*/

void			build_model(t_model *model)
{
	model->matrix = new_matrix4f();
	model->matrix = transform_rotatef(NULL, model->vrot->x, new_vector3f(1,0,0));
	model->matrix = transform_rotatef(model->matrix, model->vrot->y, new_vector3f(0,1,0));
	model->matrix = transform_rotatef(model->matrix, model->vrot->z, new_vector3f(0,0,1));
	model->matrix = transform_translation(model->matrix, new_vector3f(model->vpos->x, model->vpos->y, model->vpos->z));
	//t_matrix4f	*tmp;

	//odel->translation = init_translation(model->vpos->x, model->vpos->y, model->vpos->z);
	//model->rotation = init_rotation(model->vrot->x, model->vrot->y, model->vrot->z);
	//model->scale = init_scale(model->vscale->x, model->vscale->y, model->vscale->z);

	// model->translation * model->rotation * model->scale
	//model->matrix = copy_matrix4f(model->translation);
	
	/*tmp = matrix4f_mul(model->matrix, model->rotation);
	destruct_matrix4f(model->matrix);
	model->matrix = tmp;

	tmp = matrix4f_mul(model->matrix, model->scale);
	destruct_matrix4f(model->matrix);
	model->matrix = tmp;*/
}

void			build_view(t_view *view)
{
	view->matrix = new_matrix4f();
	view->matrix = transform_rotatef(NULL, view->vrot->x, new_vector3f(1,0,0));
	view->matrix = transform_rotatef(view->matrix, view->vrot->y, new_vector3f(0,1,0));
	view->matrix = transform_rotatef(view->matrix, view->vrot->z, new_vector3f(0,0,1));
	view->matrix = transform_translation(view->matrix, new_vector3f(-view->vpos->x, -view->vpos->y, -view->vpos->z));
	//view->matrix = transform_scale_fixed(view->matrix, new_vector3f(1,1,1), new_vector3f(0, 0, 0));
}

t_transform		*build_transform(t_transform *t)
{
	//t_matrix4f	*tmp;
	//t_matrix4f	*view;

	t->projection = init_perspective(70.0f, t->aspect_ratio, 0.1f, 1000.0f);

	//build_model(t->model);
	//build_view(t->view);

	t->view->matrix = transform_fps_view(t->view->eye, ft_radians(t->view->center->x), ft_radians(t->view->center->y));

	//look = transform_look_at(new_vector3f(t->view->eye->x, t->view->eye->y, t->view->eye->z), new_vector3f(t->view->center->x, t->view->center->y, t->view->center->z), new_vector3f(t->view->up->x, t->view->up->y, t->view->up->z));//matrix4f_mul(t->model->matrix, t->view->matrix);
	
	t->mv = matrix4f_mul(t->projection, t->view->matrix);
	//t->mv = transform_rotatef(t->mv, t->view->vrot->y, new_vector3f(0,1,0));
	//t->mv = transform_rotatef(t->mv, t->view->vrot->x, new_vector3f(1,0,0));
	//t->mv = transform_translation(t->mv, new_vector3f(500,900,0));

	//t->matrix = copy_matrix4f(t->projection);
	//t->matrix = matrix4f_mul(t->projection, t->mv);
	
	//destruct_matrix4f(t->projection);

	/*build_model(t->model);
	build_view(t->view);

	t->matrix = copy_matrix4f(t->view->matrix);//matrix4f_mul(t->model->matrix, t->view->matrix);//A TEST DANS L"AUTRE SENS
	
	tmp = matrix4f_mul(t->projection, t->matrix);
	destruct_matrix4f(t->matrix);
	t->matrix = tmp;*/
	return (t);
}
