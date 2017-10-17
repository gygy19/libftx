/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 19:12:58 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/07 19:13:01 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

int         color_by_y(t_vector3f *v)
{
	if (v == NULL)
		return (0x000000);
	if (v->y < 0)
		return (0xff0000);
	return (0xffffff);
}

void        render(t_fdf *fdf)
{
	int y;
	int x;
	t_libx_line	*line;

	y = 0;
	while (y < (fdf->size.y - 1))
	{
		x = 1;
		while (x < fdf->size.x)
		{
			/*if (fdf->grid[y][x])
			{
				libx_put_pixel_to_img(fdf->img, fdf->grid[y][x]->x, fdf->grid[y][x]->y, color_by_z(fdf->sgrid[y][x]));
			}*/
			if (fdf->grid[y][x - 1] && fdf->grid[y][x])
			{
				line = libx_new_line(fdf->img, fdf->grid[y][x - 1], fdf->grid[y][x], color_by_y(fdf->sgrid[y][x]));
				libx_draw_line_to_img(line);
			}
			if (fdf->grid[y][x] && fdf->grid[y + 1][x])
			{
				line = libx_new_line(fdf->img, fdf->grid[y][x], fdf->grid[y + 1][x], color_by_y(fdf->sgrid[y][x]));
				libx_draw_line_to_img(line);
			}
			x++;
		}
		y++;
	}
}

void        update_vectors(t_fdf *fdf)
{
	t_transform *transform;
	int y;
	int x;

	transform = new_transform();
	transform->fov = 60.0f;
	set_transform_window_size(transform, fdf->window_size.x, fdf->window_size.y);
	transform->near = 0.01f;
	transform->far = 1000.0f;
	transform->view->vpos = &fdf->camera.pos;
	transform->view->vrot = &fdf->camera.rot;

	transform->view->eye = &fdf->camera.pos;
	transform->view->center = &fdf->camera.a;

	transform->model->vpos = new_vector3f(0,0,0);
	transform->model->vrot = new_vector3f(0,0,0);
	transform->model->vscale = &fdf->camera.scale;
	build_transform(transform);

	y = 0;
	while (y < fdf->size.y)
	{
		x = 0;
		while (x < fdf->size.x)
		{
			if (fdf->grid[y][x])
			{
				//fdf->grid[y][x]->x -= fdf->size.x / 2;
				//fdf->grid[y][x]->y -= fdf->size.y / 2;
				//fdf->grid[y][x] = apply_matrix4f_to_vertex4f(worldcamera, fdf->grid[y][x]);
				

				//fdf->grid[y][x] = apply_matrix4f_to_vertex4f(transform->matrix, fdf->grid[y][x]);//apply_transform(transform, fdf->grid[y][x]);
				
				t_matrix4f *model = matrix4f_translate(fdf->grid[y][x]);

				model = transform_rotatef(model, fdf->camera.rot.y, new_vector3f(0,1,0));

				t_matrix4f *mvp = matrix4f_mul(model, transform->mv);

				fdf->grid[y][x] = apply_matrix4f_to_vertex4f(mvp, fdf->grid[y][x]);

				destruct_matrix4f(mvp);
				destruct_matrix4f(model);
				//fdf->grid[y][x] = n;//= apply_matrix4f_to_vertex4f(transform->mv, fdf->grid[y][x]);
				//fdf->grid[y][x]->x += 200;
				//fdf->grid[y][x]->y += 100;
				//printf("v->x(%f) v->y(%f) v->z(%f)\n", fdf->grid[y][x]->x, fdf->grid[y][x]->y, fdf->grid[y][x]->z);
				//fdf->grid[y][x]->x += (fdf->window_size.x / 2) - ((fdf->size.x / 2) * fdf->camera.scale.x);
				//fdf->grid[y][x]->y += (fdf->window_size.y / 2) - ((fdf->size.y / 2) * fdf->camera.scale.x);
				//printf(" to v->x(%f) v->y(%f) v->z(%f)\n", fdf->grid[y][x]->x, fdf->grid[y][x]->y, fdf->grid[y][x]->z);
			}
			x++;
		}
		y++;
	}
	//destruct_transform(transform);
}
