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

/*     MATRIX
** 1    0       0    0
** 0  cos(x)   sin(x) 0
** 0  -sin(x)  cos(x) 0
** 0    0       0    1
*/
t_matrix4f *eulerAngleX(const float anglex)
{
    t_matrix4f  *m;

    m = new_matrix4f();
    //1    0       0    0
    m->matrix[0][0] = 1;
    m->matrix[0][1] = 0;
    m->matrix[0][2] = 0;
    m->matrix[0][3] = 0;
    //0  cos(x) sin(x) 0
    m->matrix[1][0] = 0;
    m->matrix[1][1] = (float)cos(anglex);
    m->matrix[1][2] = -(float)sin(anglex);
    m->matrix[1][3] = 0;
    //0  -sin(x)  cos(x) 0
    m->matrix[2][0] = 0;
    m->matrix[2][1] = -(float)sin(anglex);
    m->matrix[2][2] = (float)cos(anglex);
    m->matrix[2][3] = 0;
    //0    0       0    1
    m->matrix[3][0] = 0;
    m->matrix[3][1] = 0;
    m->matrix[3][2] = 0;
    m->matrix[3][3] = 1;
    return (m);
}

/*     MATRIX
** cos(y)   0  -sin(y) 0
**   0      1    0     0
** sin(y)   0  cos(y)  0
**   0      0    0     1
*/
t_matrix4f *eulerAngleY(const float angley)
{
    t_matrix4f  *m;

    m = new_matrix4f();
    //cos(y)   0  -sin(y) 0
	m->matrix[0][0] = (float)cos(angley);
	m->matrix[0][1] = 0;
	m->matrix[0][2] = -(float)sin(angley);
	m->matrix[0][3] = 0;
	//  0      1    0    0
	m->matrix[1][0] = 0;
	m->matrix[1][1] = 1;
	m->matrix[1][2] = 0;
	m->matrix[1][3] = 0;
	//-sin(y)  0  cos(y) 0
	m->matrix[2][0] = (float)sin(angley);
	m->matrix[2][1] = 0;
	m->matrix[2][2] = (float)cos(angley);
	m->matrix[2][3] = 0;
	//  0      0    0    1
	m->matrix[3][0] = 0;
	m->matrix[3][1] = 0;
	m->matrix[3][2] = 0;
	m->matrix[3][3] = 1;
    return (m);
}

/*     MATRIX
** cos(z)   sin(z) 0 0
** -sin(z)  cos(z) 0 0
**   0       0     1 0
**   0       0     0 1
*/
t_matrix4f *eulerAngleZ(const float anglez)
{
    t_matrix4f  *m;

    m = new_matrix4f();
	//cos(z) sin(z) 0 0
	m->matrix[0][0] = (float)cos(anglez);
	m->matrix[0][1] = -(float)sin(anglez);
	m->matrix[0][2] = 0;
	m->matrix[0][3] = 0;
	//-sin(z)  cos(z) 0 0
	m->matrix[1][0] = -(float)sin(anglez);
	m->matrix[1][1] = (float)cos(anglez);
	m->matrix[1][2] = 0;
	m->matrix[1][3] = 0;
	//  0       0    1 0
	m->matrix[2][0] = 0;
	m->matrix[2][1] = 0;
	m->matrix[2][2] = 1;
	m->matrix[2][3] = 0;
	//  0       0    0 1
	m->matrix[3][0] = 0;
	m->matrix[3][1] = 0;
	m->matrix[3][2] = 0;
	m->matrix[3][3] = 1;
    return (m);
}

/*     MATRIX
** cosY,   -sinX * -sinY,  cosX * -sinY,   0
** 0,           cosX    ,       sinX   ,   0
** sinY,    -sinX * cosY,   cosX * cosY,   0
** 0                   0              0    1
*/
t_matrix4f *eulerAngleXY(const float anglex, const float angley)
{
    t_matrix4f  *m;

    m = new_matrix4f();
    //cosY,   -sinX * -sinY,  cosX * -sinY,   0
    m->matrix[0][0] = (float)cos(angley);
    m->matrix[0][1] = -(float)sin(anglex) * -(float)sin(angley);
    m->matrix[0][2] = (float)cos(anglex) * -(float)sin(angley);
    m->matrix[0][3] = 0;
    //0,   cosX,           sinX,           0
    m->matrix[1][0] = 0;
    m->matrix[1][1] = (float)cos(anglex);
    m->matrix[1][2] = (float)sin(anglex);
    m->matrix[1][3] = 0;
    //sinY,   -sinX * cosY,   cosX * cosY,   0
    m->matrix[2][0] = (float)sin(angley);
    m->matrix[2][1] = -(float)sin(anglex) * (float)cos(angley);
    m->matrix[2][2] = (float)cos(anglex) * (float)cos(angley);
    m->matrix[2][3] = 0;
    //0    0       0    1
    m->matrix[3][0] = 0;
    m->matrix[3][1] = 0;
    m->matrix[3][2] = 0;
    m->matrix[3][3] = 1;
    return (m);
}

/*     MATRIX
** cosY,   -sinX * -sinY,  cosX * -sinY,   0
** 0,           cosX    ,       sinX   ,   0
** sinY,    -sinX * cosY,   cosX * cosY,   0
** 0                   0              0    1
*/
t_matrix4f *eulerAngleYX(const float angley, const float anglex)
{
    t_matrix4f  *m;

    m = new_matrix4f();
    //cosY,  0,  -sinY,   0
    m->matrix[0][0] = (float)cos(angley);
    m->matrix[0][1] = 0;
    m->matrix[0][2] = -(float)sin(angley);
    m->matrix[0][3] = 0;
    //sinY * sinX,  cosX, cosY * sinX, 0
    m->matrix[1][0] = (float)sin(angley) * (float)sin(anglex);
    m->matrix[1][1] = (float)cos(anglex);
    m->matrix[1][2] = (float)cos(angley) * (float)sin(anglex);
    m->matrix[1][3] = 0;
    //sinY * cosX, -sinX, cosY * cosX, 0
    m->matrix[2][0] = (float)sin(angley) * (float)cos(anglex);
    m->matrix[2][1] = -(float)sin(anglex);
    m->matrix[2][2] = (float)cos(angley) * (float)cos(anglex);
    m->matrix[2][3] = 0;
    //0    0       0    1
    m->matrix[3][0] = 0;
    m->matrix[3][1] = 0;
    m->matrix[3][2] = 0;
    m->matrix[3][3] = 1;
    return (m);
}

t_matrix4f *eulerAngleXZ(const float anglex, const float anglez)
{
    t_matrix4f  *eleurx;
    t_matrix4f  *eleurz;
    t_matrix4f  *result;

    eleurx = eulerAngleX(anglex);
    eleurz = eulerAngleZ(anglez);

    result = matrix4f_mul(eleurx, eleurz);
    destruct_matrix4f(eleurx);
    destruct_matrix4f(eleurz);
    return (result);
}

t_matrix4f *eulerAngleZX(const float anglez, const float anglex)
{
    t_matrix4f  *eleurx;
    t_matrix4f  *eleurz;
    t_matrix4f  *result;

    eleurx = eulerAngleX(anglex);
    eleurz = eulerAngleZ(anglez);

    result = matrix4f_mul(eleurz, eleurx);
    destruct_matrix4f(eleurx);
    destruct_matrix4f(eleurz);
    return (result);
}