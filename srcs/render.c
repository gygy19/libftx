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

t_vector3f  *vector3d_to_2d(t_vector3f *v)
{
    float       xc;
    float       yc;

    xc = 0;
    yc = 0;

    if (v->x != 0 && v->z != 0)
        xc = v->x / v->z;
    else
        xc = v->x;
    if (v->y != 0 && v->z != 0)
        yc = v->y / v->z;
    else
        yc = v->y;
    return (new_vector3f(xc + 400,yc + 400,0));
}

void        render(t_fdf *fdf)
{
    int y;
    int x;

    y = 0;
    while (y < (fdf->size.y - 1))
    {
        x = 1;
        while (x < fdf->size.x)
        {
            t_libx_line	*line = libx_new_line(fdf->img, fdf->grid[y][x - 1], fdf->grid[y][x], 0xffffff);
            libx_draw_line_to_img(line);

            line = libx_new_line(fdf->img, fdf->grid[y][x], fdf->grid[y + 1][x], 0xffffff);
            libx_draw_line_to_img(line);
            x++;
        }
        y++;
    }
}

/*
t_vector3f  *operatormult(t_vector3f *v, t_matrix4f *m)
{
    t_vector3f *dst;

    dst = new_vector3f(0,0,0);
    dst->x = v->x*m->matrix[0][0] + v->y*m->matrix[0][1] + v->z*m->matrix[0][2] + m->matrix[0][3];
    dst->y = v->x*m->matrix[1][0] + v->y*m->matrix[1][1] + v->z*m->matrix[1][2] + m->matrix[1][3];
    dst->z = v->x*m->matrix[2][0] + v->y*m->matrix[2][1] + v->z*m->matrix[2][2] + m->matrix[2][3];
    //dst->w = v->x*m->matrix[3] + v->y*m->matrix[7] + v->z*m->matrix[11];
    return (dst);
}

void        setupmatrix(t_matrix *m, float fov, float aspectratio, float near, float far)
{
    float f = 1.0f / tan(fov * 0.5f);
    m->matrix[0] = f * aspectratio;
    m->matrix[5] = f;
    m->matrix[10] = (far + near) / (far - near);
    m->matrix[11] = 1.0f;
    m->matrix[14] = (2.0f * near * far) / (near - far);
    m->matrix[15] = 0.0f;
}

void rotateVector3f(t_vector3f *v, double degrees)
{
    double result[2];

    result[0] = v->x * cos(degrees) - v->y * sin(degrees);
    result[1] = v->x * sin(degrees) + v->y * cos(degrees);

    v->x = result[0];
    v->y = result[1];
}*/

void        update_vectors(t_fdf *fdf)
{
    t_transform *transform;
    int y;
    int x;

	transform = new_transform();
	transform->fov = 70.0f;
	set_transform_window_size(transform, fdf->window_size.x, fdf->window_size.y);
	transform->near = 0.01f;
	transform->far = 1000.0f;
	transform->vpos = &fdf->camera.pos;
	transform->vrot = &fdf->camera.rot;
	transform->vscale = &fdf->camera.scale;
	build_transform(transform);
    //matrix = build_transform(fdf->window_size.x, fdf->window_size.y, &fdf->camera.pos, &fdf->camera.rot, &fdf->camera.scale);
    y = 0;
    while (y < fdf->size.y)
    {
        x = 0;
        while (x < fdf->size.x)
        {
			fdf->grid[y][x] = apply_transform(transform, fdf->grid[y][x]);
            //fdf->grid[y][x] = operatormult(fdf->grid[y][x], matrix);
            printf("v->x(%f) v->y(%f) v->z(%f)", fdf->grid[y][x]->x, fdf->grid[y][x]->y, fdf->grid[y][x]->z);
            //fdf->grid[y][x] = operatormult(fdf->grid[y][x], screen);
            fdf->grid[y][x]->x += (fdf->window_size.x / 2) - ((fdf->size.x / 2) * fdf->camera.scale.x);
            fdf->grid[y][x]->y += (fdf->window_size.y / 2) - ((fdf->size.y / 2) * fdf->camera.scale.x);
            printf(" to v->x(%f) v->y(%f) v->z(%f)\n", fdf->grid[y][x]->x, fdf->grid[y][x]->y, fdf->grid[y][x]->z);
            x++;
        }
        y++;
	}
	destruct_transform(transform);
}
