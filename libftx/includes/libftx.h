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

typedef struct	s_model
{
	t_matrix4f	*translation;
	t_vector3f	*vpos;
	t_matrix4f	*rotation;
	t_vector3f	*vrot;
	t_matrix4f	*scale;
	t_vector3f	*vscale;
	t_matrix4f	*matrix;
}				t_model;

typedef struct	s_view
{
	t_matrix4f	*translation;
	t_vector3f	*vpos;
	t_matrix4f	*rotation;
	t_vector3f	*vrot;
	t_matrix4f	*orientation;
	
	t_vector3f	*eye;//the position of the viewer
	t_vector3f	*center;//the point where we the camera aims
	t_vector3f	*up;//defines the direction of the up for the viewer.

	t_matrix4f	*matrix;
}				t_view;

typedef struct	s_transform
{
/*
** PROJECTION
*/
	t_matrix4f	*projection;
	float		fov;
	float		aspect_ratio;
	float		near;
	float		far;
/*
** MODEL
*/
	t_model		*model;
/*
** VIEW
*/
	t_view		*view;
/*
** FINAL MATRICIAL P*(M*V)
*/
	t_matrix4f	*matrix;
	t_matrix4f	*mv;
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
t_vector3f		*v3f_cross(t_vector3f *v1, t_vector3f *v2);
t_vector3f		*v3f_mul(t_vector3f *v1, t_vector3f *v2);
float			ft_dot(t_vector3f *r1, t_vector3f *r2);

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
t_vector3f  	*apply_matrix4f_to_vertex4f(t_matrix4f *m, t_vector3f *src);
t_matrix4f		*matrix4f_translate(t_vector3f *v);

/*
**	Mathf
*/
float			ft_radians(float degrees);
float			ft_clamp(float value, float max, float min);

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
t_matrix4f		*init_view_orientation(t_vector3f *side, t_vector3f *up, t_vector3f *forward);

t_matrix4f		*transform_rotatef(t_matrix4f *matrix, float angle, t_vector3f *type);
t_matrix4f		*transform_translation(t_matrix4f *matrix, t_vector3f *pos);
t_matrix4f		*transform_scale(t_matrix4f *matrix, t_vector3f *scale);
t_matrix4f		*transform_scale_fixed(t_matrix4f *matrix, t_vector3f *scale, t_vector3f *fixed);

t_matrix4f    	*transform_look_at(t_vector3f *eye3d, t_vector3f *center3d, t_vector3f *up3d);
/*
** MODEL
*/
t_model			*new_model(void);
void			destruct_model(t_model *t);

/*
** VIEW
*/
t_view			*new_view(void);
void			destruct_view(t_view *t);


t_matrix4f *eulerAngleX(const float anglex);
t_matrix4f *eulerAngleY(const float angley);
t_matrix4f *eulerAngleZ(const float anglez);
t_matrix4f *eulerAngleXY(const float anglex, const float angley);
t_matrix4f *eulerAngleYX(const float angley, const float anglex);
t_matrix4f *eulerAngleXZ(const float anglex, const float anglez);
t_matrix4f *eulerAngleZX(const float anglez, const float anglex);

t_matrix4f		*inverse_4x4(t_matrix4f *m);

t_matrix4f    	*transform_fps_view(t_vector3f *eye, float yaw, float pitch);

#endif
