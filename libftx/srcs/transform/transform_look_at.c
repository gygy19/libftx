/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_look_at.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 21:14:13 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/08 21:14:15 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

#include <math.h>

t_matrix4f    	*transform_look_at(t_vector3f *eye3d, t_vector3f *center3d, t_vector3f *up3d)
{
    t_vector3f *forward;
    t_vector3f *side;
    t_vector3f *up;
    t_matrix4f *matrix;

    matrix = new_matrix4f();
    forward = new_vector3f(center3d->x - eye3d->x, center3d->y - eye3d->y, center3d->z - eye3d->z);
    forward = v3f_normalize(forward);

    side = v3f_mul(forward, up3d);
    side = v3f_normalize(side);

    up = v3f_mul(side, forward);

    matrix->matrix[0][0] = side->x;
    matrix->matrix[1][0] = side->y;
    matrix->matrix[2][0] = side->z;
    matrix->matrix[3][0] = 0;

    matrix->matrix[0][1] = up->x;
    matrix->matrix[1][1] = up->y;
    matrix->matrix[2][1] = up->z;
    matrix->matrix[3][1] = 0;

    matrix->matrix[0][2] = -forward->x;
    matrix->matrix[1][2] = -forward->y;
    matrix->matrix[2][2] = -forward->z;
    matrix->matrix[3][2] = 0;

    matrix->matrix[0][3] = 0;
    matrix->matrix[1][3] = 0;
    matrix->matrix[2][3] = 0;
    matrix->matrix[3][3] = 1;


    matrix = transform_translation(matrix, new_vector3f(-eye3d->x, -eye3d->y, -eye3d->z));
    return (matrix);
}