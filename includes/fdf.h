/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:33:02 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/07 15:33:20 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <printf.h>
# include <libftx.h>
# include <mlx.h>

typedef struct		s_camera
{
	t_vector3f		rot;
	t_vector3f		pos;
	t_vector3f		scale;
}					t_camera;

typedef struct		s_mouse
{
	t_vector2f		lastpos;
	t_vector2f		diff;
}					t_mouse;

typedef struct		s_fdf
{
	void			*mlx;
	void			*window;
	t_vector2f		window_size;
	t_libx_img		*img;
	t_vector3f		***sgrid;
	t_vector3f		***grid;
	t_vector2f		size;
	t_camera		camera;
	t_mouse			mouse;
	char			*filename;
}					t_fdf;

void        render(t_fdf *fdf);
void        update_vectors(t_fdf *fdf);

#endif
