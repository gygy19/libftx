/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_translation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 21:17:20 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/08 21:17:22 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

/* MATRIX TRANSLATION
** 1 0 0 x
** 0 1 0 y
** 0 0 1 z
** 0 0 0 1
*/
t_matrix4f		*init_translation(float x, float y, float z)
{
	t_matrix4f	*m;

	m = new_matrix4f();
	m->matrix[0][0] = 1;
	m->matrix[0][1] = 0;
	m->matrix[0][2] = 0;
	m->matrix[0][3] = x;
	m->matrix[1][0] = 0;
	m->matrix[1][1] = 1;
	m->matrix[1][2] = 0;
	m->matrix[1][3] = y;
	m->matrix[2][0] = 0;
	m->matrix[2][1] = 0;
	m->matrix[2][2] = 1;
	m->matrix[2][3] = z;
	m->matrix[3][0] = 0;
	m->matrix[3][1] = 0;
	m->matrix[3][2] = 0;
	m->matrix[3][3] = 1;
	return (m);
}

t_matrix4f		*transform_translation(t_matrix4f *matrix, t_vector3f *pos)
{
	t_matrix4f *translation;
	t_matrix4f *dst;
	
	translation = init_translation(pos->x, pos->y, pos->x);
	dst = matrix4f_mul(translation, matrix);
	destruct_matrix4f(translation);
	destruct_matrix4f(matrix);
	destruct_vector3f(pos);
	return (dst);
} 
