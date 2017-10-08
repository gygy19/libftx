/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:27:38 by jguyet            #+#    #+#             */
/*   Updated: 2016/08/21 00:37:38 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTX_H
# define LIBFTX_H

# include <unistd.h>

# define MATHF_PI 3.14159

/*
**STRUCT libx
*/
typedef struct	s_vector2f
{
	float		x;
	float		y;
}				t_vector2f;

typedef struct	s_vector3f
{
	float		x;
	float		y;
	float		z;
}				t_vector3f;

typedef struct	s_vector4f
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_vector4f;

typedef struct	s_matrix4f
{
	float		matrix[4][4];
}				t_matrix4f;

typedef struct	s_transform
{
/*
** PROJECTION SECTION
*/
	t_matrix4f	*projection;
	float		fov;
	float		aspect_ratio;
	float		near;
	float		far;
/*
** TRANSLATION SECTION
*/
	t_matrix4f	*translation;
	t_vector3f	*vpos;
/*
** ROTATION SECTION
*/
	t_matrix4f	*rotation;
	t_vector3f	*vrot;
/*
**	SCALE SECTION
*/
	t_matrix4f	*scale;
	t_vector3f	*vscale;
/*
** FINAL MATRICIAL
*/
	t_matrix4f	*matrix;
}				t_transform;

typedef struct	s_libx_img
{
	void		*img_ptr;
	int			width;
	int			height;
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_libx_img;

typedef struct	s_libx_line
{
	t_libx_img	*img;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			color;
}				t_libx_line;

t_libx_img		*libx_new_img(void *mlx, int width, int height);
t_libx_line		*libx_new_line(t_libx_img *img, t_vector3f *v1,
				t_vector3f *v2, int color);
void			libx_draw_line_to_img(t_libx_line *line);
void			libx_put_pixel_to_img(t_libx_img *img, int x,\
				int y, int color);

/*
** Vector2f
*/
t_vector2f		*new_vector2f(float x, float y);
void			destruct_vector2f(t_vector2f *v);
float			v2f_sqrt(t_vector2f *v);
float			v2f_magnitude(t_vector2f *v);
t_vector2f		*v2f_normalize(t_vector2f *v);

/*
** Vector3f
*/
t_vector3f		*new_vector3f(float x, float y, float z);
void			destruct_vector3f(t_vector3f *v);
float			v3f_sqrt(t_vector3f *v);
float			v3f_magnitude(t_vector3f *v);
t_vector3f		*v3f_normalize(t_vector3f *v);

/*
** Vector4f
*/
t_vector4f		*new_vector4f(float x, float y, float z, float w);
void			destruct_vector4f(t_vector4f *v);
float			v4f_sqrt(t_vector4f *v);
float			v4f_magnitude(t_vector4f *v);
t_vector4f		*v4f_normalize(t_vector4f *v);

/*
** Matrix4f
*/
t_matrix4f		*new_matrix4f(void);
void			destruct_matrix4f(t_matrix4f *m);
t_matrix4f		*matrix4f_identity(void);
t_matrix4f		*copy_matrix4f(t_matrix4f *origin);
t_matrix4f		*matrix4f_mul(t_matrix4f *m, t_matrix4f *m2);
t_vector3f  	*apply_matrix4f_to_vertex(t_matrix4f *m, t_vector3f *v);

/*
**	Mathf
*/
float			ft_radians(float degrees);

/*
** Transform
*/

/*
** DOCUMENTATION FRERE !!!!
** ########################################################### DEFAULT
** t->fov = 70.0f;
** t->near = 0.1f;
** t->far = 1000.0f;
** t->aspect_ratio = 0;
** ########################################################### UTILISATION
** set_transform_window_size(t, window.width, window.height);
** t->vpos = new_vector3f(0,0,0);
** t->vscale = new_vector3f(1,1,1);
** t->vrot = new_vector3f(0,0,0);
** build_transform(t);
** ########################################################### APPLY ON ALL VERTEX
** apply_transform(t, vector3f);
** ###########################################################
** PRINT ALL VERTEX
*/
t_transform		*new_transform(void);
void			destruct_transform(t_transform *t);
void			set_transform_window_size(t_transform *t, float width,\
				float height);
t_transform		*build_transform(t_transform *t);
t_vector3f  	*apply_transform(t_transform *t, t_vector3f *v);
t_matrix4f		*init_perspective(float fov, float aspect_ratio,\
				float near, float far);
t_matrix4f		*init_translation(float x, float y, float z);
t_matrix4f		*init_rotation(float x, float y, float z);
t_matrix4f		*init_scale(float x, float y, float z);

#endif
