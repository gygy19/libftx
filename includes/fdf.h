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
	t_vector3f		dir;
	t_vector3f		a;
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

/*
** FILE
*/
char		*load_file(char *filename);

/*
** RENDER
*/
void        render(t_fdf *fdf);
void        update_vectors(t_fdf *fdf);

/*
** MESH
*/
void		load_mesh_size(t_fdf *fdf, char *file);
BOOLEAN		load_mesh_vertex(t_fdf *fdf);
void		set_mesh_vertex(t_fdf *fdf, char *file);
void		copy_mesh(t_fdf *fdf);

/*
** EVENTS
*/
int			key_event(int keycode, void **env);
int			mouse_event(int x, int y, void **env);
int			scroll_event(int keycode, int x, int y, void **env);

/*
** LOOP
*/
void		fdf_loop(t_fdf *fdf, void **env);

/*
** FDF
*/
t_fdf		*new_fdf(char *filename);

#endif
