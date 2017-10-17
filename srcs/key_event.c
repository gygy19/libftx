/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:09:55 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/09 14:09:56 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <math.h>
#include <stdio.h>

void	move(t_camera *camera)
{
	camera->pos.x += camera->a.x;
	camera->pos.y += camera->a.y;
	camera->pos.z += camera->a.z;
}

int	key_event(int keycode, void **env)
{
	t_fdf	*fdf;
	float	speed;

	speed = 5.0f;
	fdf = (t_fdf*)env[0];

	fdf->camera.dir.x = 0;
	fdf->camera.dir.y = 0;
	fdf->camera.dir.z = 0;
	ft_printf("key event %d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		fdf->camera.rot.x += 0.1f;
	else if (keycode == 125)
		fdf->camera.rot.x -= 0.1f;
	else if (keycode == 123)
		fdf->camera.rot.y += 0.1f;
	else if (keycode == 124)
		fdf->camera.rot.y -= 0.1f;
	else if (keycode == 18)
		fdf->camera.scale.x -= 0.1f;
	else if (keycode == 19)
		fdf->camera.scale.x += 0.1f;
	else if (keycode == 13)//w
		fdf->camera.pos.y -= speed;
	else if (keycode == 1)//s
		fdf->camera.pos.y += speed;
	else if (keycode == 0)//a
		fdf->camera.pos.x -= speed;
	else if (keycode == 2)//d
		fdf->camera.pos.x += speed;

	printf("cam pos x%f, y%f, z%f\n", fdf->camera.pos.x, fdf->camera.pos.y, fdf->camera.pos.z);

	/*if (fdf->camera.rot.x > 90)
		fdf->camera.rot.x = 90;
	if (fdf->camera.rot.x < -90)
		fdf->camera.rot.x = -90;*/

	/*fdf->camera.a.x += fdf->camera.dir.x * cos(ft_radians(fdf->camera.rot.y))\
		 - fdf->camera.dir.z * sin(ft_radians(fdf->camera.rot.y));
	fdf->camera.a.y += fdf->camera.dir.y;
	fdf->camera.a.z += fdf->camera.dir.z * cos(ft_radians(fdf->camera.rot.y))\
	- fdf->camera.dir.x * sin(ft_radians(fdf->camera.rot.y));*/

	//move(&fdf->camera);
	
	mlx_clear_window(fdf->mlx, fdf->window);
	copy_mesh(fdf);
	fdf->img = libx_new_img(fdf->mlx, fdf->window_size.x, fdf->window_size.y);
	update_vectors(fdf);
	render(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->img->img_ptr, 0, 0);

	//fdf->camera.a.x *= 0.9f;
	//fdf->camera.a.y *= 0.9f;
	//fdf->camera.a.z *= 0.9f;

	fdf_loop(fdf, env);
	return (0);
}

