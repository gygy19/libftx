/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 13:30:32 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/09 13:30:33 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_default_camera_settings(t_fdf *fdf)
{
	fdf->camera.rot.x = 11.7f;
	fdf->camera.rot.y = 5.5f;
	fdf->camera.rot.z = 0;
	fdf->camera.pos.x = -100;
	fdf->camera.pos.y = -100;
	fdf->camera.pos.z = 0;
	fdf->camera.scale.x = 9.0f;
	fdf->camera.scale.y = 9.0f;
	fdf->camera.scale.z = 9.0f;
	fdf->camera.dir.x = 0;
	fdf->camera.dir.y = 0;
	fdf->camera.dir.z = 0;
	fdf->camera.a.x = 0;
	fdf->camera.a.y = 0;
	fdf->camera.a.z = 0;
}

static void set_default_mouse_settings(t_fdf *fdf)
{
	fdf->mouse.lastpos.x = -1;
	fdf->mouse.lastpos.y = -1;
	fdf->mouse.diff.x = 0;
	fdf->mouse.diff.y = 0;
}

t_fdf	*new_fdf(char *filename)
{
	t_fdf	*f;
	char	*file;

	if (!(f = (t_fdf*)malloc(sizeof(struct s_fdf))))
		return (NULL);
	f->filename = ft_strdup(filename);
	f->size.x = 0;
	f->size.y = 0;
	set_default_camera_settings(f);
	set_default_mouse_settings(f);
	file = load_file(filename);
	load_mesh_size(f, file);
	load_mesh_vertex(f);
	set_mesh_vertex(f, file);
	ft_strdel(&file);
	return (f);
}
