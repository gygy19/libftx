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

t_matrix4f *inverse_4x4(t_matrix4f *m)
{
    t_matrix4f  *result;
    float       det;

    result = new_matrix4f();
    /* Compute adjoint: */
    // 0  1  2  3
    // 4  5  6  7
    // 8  9  10 11
    // 12 13 14 15
    result->matrix[0][0] =
        + m->matrix[1][1] * m->matrix[2][2] * m->matrix[3][3]
        - m->matrix[1][1] * m->matrix[2][3] * m->matrix[3][2]
        - m->matrix[2][1] * m->matrix[1][2] * m->matrix[3][3]
        + m->matrix[2][1] * m->matrix[1][3] * m->matrix[3][2]
        + m->matrix[3][1] * m->matrix[1][2] * m->matrix[2][3]
        - m->matrix[3][1] * m->matrix[1][3] * m->matrix[2][2];

    result->matrix[0][1] =
        - m->matrix[0][1] * m->matrix[2][2] * m->matrix[3][3]
        + m->matrix[0][1] * m->matrix[2][3] * m->matrix[3][2]
        + m->matrix[2][1] * m->matrix[0][2] * m->matrix[3][3]
        - m->matrix[2][1] * m->matrix[0][3] * m->matrix[3][2]
        - m->matrix[3][1] * m->matrix[0][2] * m->matrix[2][3]
        + m->matrix[3][1] * m->matrix[0][3] * m->matrix[2][2];

    result->matrix[0][2] =
        + m->matrix[0][1] * m->matrix[1][2] * m->matrix[3][3]
        - m->matrix[0][1] * m->matrix[1][3] * m->matrix[3][2]
        - m->matrix[1][1] * m->matrix[0][2] * m->matrix[3][3]
        + m->matrix[1][1] * m->matrix[0][3] * m->matrix[3][2]
        + m->matrix[3][1] * m->matrix[0][2] * m->matrix[1][3]
        - m->matrix[3][1] * m->matrix[0][3] * m->matrix[1][2];

    result->matrix[0][3] =
        - m->matrix[0][1] * m->matrix[1][2] * m->matrix[2][3]
        + m->matrix[0][1] * m->matrix[1][3] * m->matrix[2][2]
        + m->matrix[1][1] * m->matrix[0][2] * m->matrix[2][3]
        - m->matrix[1][1] * m->matrix[0][3] * m->matrix[2][2]
        - m->matrix[2][1] * m->matrix[0][2] * m->matrix[1][3]
        + m->matrix[2][1] * m->matrix[0][3] * m->matrix[1][2];

    result->matrix[1][0] =
        - m->matrix[1][0] * m->matrix[2][2] * m->matrix[3][3]
        + m->matrix[1][0] * m->matrix[2][3] * m->matrix[3][2]
        + m->matrix[2][0] * m->matrix[1][2] * m->matrix[3][3]
        - m->matrix[2][0] * m->matrix[1][3] * m->matrix[3][2]
        - m->matrix[3][0] * m->matrix[1][2] * m->matrix[2][3]
        + m->matrix[3][0] * m->matrix[1][3] * m->matrix[2][2];

    result->matrix[1][1] =
        + m->matrix[0][0] * m->matrix[2][2] * m->matrix[3][3]
        - m->matrix[0][0] * m->matrix[2][3] * m->matrix[3][2]
        - m->matrix[2][0] * m->matrix[0][2] * m->matrix[3][3]
        + m->matrix[2][0] * m->matrix[0][3] * m->matrix[3][2]
        + m->matrix[3][0] * m->matrix[0][2] * m->matrix[2][3]
        - m->matrix[3][0] * m->matrix[0][3] * m->matrix[2][2];

    result->matrix[1][2] =
        - m->matrix[0][0] * m->matrix[1][2] * m->matrix[3][3]
        + m->matrix[0][0] * m->matrix[1][3] * m->matrix[3][2]
        + m->matrix[1][0] * m->matrix[0][2] * m->matrix[3][3]
        - m->matrix[1][0] * m->matrix[0][3] * m->matrix[3][2]
        - m->matrix[3][0] * m->matrix[0][2] * m->matrix[1][3]
        + m->matrix[3][0] * m->matrix[0][3] * m->matrix[1][2];

    result->matrix[1][3] =
        + m->matrix[0][0] * m->matrix[1][2] * m->matrix[2][3]
        - m->matrix[0][0] * m->matrix[1][3] * m->matrix[2][2]
        - m->matrix[1][0] * m->matrix[0][2] * m->matrix[2][3]
        + m->matrix[1][0] * m->matrix[0][3] * m->matrix[2][2]
        + m->matrix[2][0] * m->matrix[0][2] * m->matrix[1][3]
        - m->matrix[2][0] * m->matrix[0][3] * m->matrix[1][2];

    result->matrix[2][0] =
        + m->matrix[1][0] * m->matrix[2][1] * m->matrix[3][3]
        - m->matrix[1][0] * m->matrix[2][3] * m->matrix[3][1]
        - m->matrix[2][0] * m->matrix[1][1] * m->matrix[3][3]
        + m->matrix[2][0] * m->matrix[1][3] * m->matrix[3][1]
        + m->matrix[3][0] * m->matrix[1][1] * m->matrix[2][3]
        - m->matrix[3][0] * m->matrix[1][3] * m->matrix[2][1];

    result->matrix[2][1] =
        - m->matrix[0][0] * m->matrix[2][1] * m->matrix[3][3]
        + m->matrix[0][0] * m->matrix[2][3] * m->matrix[3][1]
        + m->matrix[2][0] * m->matrix[0][1] * m->matrix[3][3]
        - m->matrix[2][0] * m->matrix[0][3] * m->matrix[3][1]
        - m->matrix[3][0] * m->matrix[0][1] * m->matrix[2][3]
        + m->matrix[3][0] * m->matrix[0][3] * m->matrix[2][1];

    result->matrix[2][2] =
        + m->matrix[0][0] * m->matrix[1][1] * m->matrix[3][3]
        - m->matrix[0][0] * m->matrix[1][3] * m->matrix[3][1]
        - m->matrix[1][0] * m->matrix[0][1] * m->matrix[3][3]
        + m->matrix[1][0] * m->matrix[0][3] * m->matrix[3][1]
        + m->matrix[3][0] * m->matrix[0][1] * m->matrix[1][3]
        - m->matrix[3][0] * m->matrix[0][3] * m->matrix[1][1];

    result->matrix[2][3] =
        - m->matrix[0][0] * m->matrix[1][1] * m->matrix[2][3]
        + m->matrix[0][0] * m->matrix[1][3] * m->matrix[2][1]
        + m->matrix[1][0] * m->matrix[0][1] * m->matrix[2][3]
        - m->matrix[1][0] * m->matrix[0][3] * m->matrix[2][1]
        - m->matrix[2][0] * m->matrix[0][1] * m->matrix[1][3]
        + m->matrix[2][0] * m->matrix[0][3] * m->matrix[1][1];

    result->matrix[3][0] =
        - m->matrix[1][0] * m->matrix[2][1] * m->matrix[3][2]
        + m->matrix[1][0] * m->matrix[2][2] * m->matrix[3][1]
        + m->matrix[2][0] * m->matrix[1][1] * m->matrix[3][2]
        - m->matrix[2][0] * m->matrix[1][2] * m->matrix[3][1]
        - m->matrix[3][0] * m->matrix[1][1] * m->matrix[2][2]
        + m->matrix[3][0] * m->matrix[1][2] * m->matrix[2][1];

    result->matrix[3][1] =
        + m->matrix[0][0] * m->matrix[2][1] * m->matrix[3][2]
        - m->matrix[0][0] * m->matrix[2][2] * m->matrix[3][1]
        - m->matrix[2][0] * m->matrix[0][1] * m->matrix[3][2]
        + m->matrix[2][0] * m->matrix[0][2] * m->matrix[3][1]
        + m->matrix[3][0] * m->matrix[0][1] * m->matrix[2][2]
        - m->matrix[3][0] * m->matrix[0][2] * m->matrix[2][1];

    result->matrix[3][2] =
        - m->matrix[0][0] * m->matrix[1][1] * m->matrix[3][2]
        + m->matrix[0][0] * m->matrix[1][2] * m->matrix[3][1]
        + m->matrix[1][0] * m->matrix[0][1] * m->matrix[3][2]
        - m->matrix[1][0] * m->matrix[0][2] * m->matrix[3][1]
        - m->matrix[3][0] * m->matrix[0][1] * m->matrix[1][2]
        + m->matrix[3][0] * m->matrix[0][2] * m->matrix[1][1];

    result->matrix[3][3] =
        + m->matrix[0][0] * m->matrix[1][1] * m->matrix[2][2]
        - m->matrix[0][0] * m->matrix[1][2] * m->matrix[2][1]
        - m->matrix[1][0] * m->matrix[0][1] * m->matrix[2][2]
        + m->matrix[1][0] * m->matrix[0][2] * m->matrix[2][1]
        + m->matrix[2][0] * m->matrix[0][1] * m->matrix[1][2]
        - m->matrix[2][0] * m->matrix[0][2] * m->matrix[1][1];


    /* Compute determinant: */

    det = + m->matrix[0][0] * result->matrix[0][0] + m->matrix[0][1] * result->matrix[1][0] + m->matrix[0][2] * result->matrix[2][0] + m->matrix[0][3] * result->matrix[3][0];

    /* Multiply adjoint with reciprocal of determinant: */

    det = 1.0f / det;

    result->matrix[0][0] *= det;
    result->matrix[0][1] *= det;
    result->matrix[0][2] *= det;
    result->matrix[0][3] *= det;
    result->matrix[1][0] *= det;
    result->matrix[1][1] *= det;
    result->matrix[1][2] *= det;
    result->matrix[1][3] *= det;
    result->matrix[2][0] *= det;
    result->matrix[2][1] *= det;
    result->matrix[2][2] *= det;
    result->matrix[2][3] *= det;
    result->matrix[3][0] *= det;
    result->matrix[3][1] *= det;
    result->matrix[3][2] *= det;
    result->matrix[3][3] *= det;

    destruct_matrix4f(m);
    return (result);
}
