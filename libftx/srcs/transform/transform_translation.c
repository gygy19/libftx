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
