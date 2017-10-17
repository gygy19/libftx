/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:10:01 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/09 14:10:02 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <math.h>

int mouse_event(int x, int y, void **env)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)env[0];
	if (x < 0 || x > fdf->window_size.x)
		return (0);
	if (y < 0 || y > fdf->window_size.y)
		return (0);
	if (fdf->mouse.lastpos.x == -1 && fdf->mouse.lastpos.y == -1)
	{
		fdf->mouse.lastpos.x = x;
		fdf->mouse.lastpos.y = y;
		return (0);
	}
	fdf->mouse.diff.x = x - fdf->mouse.lastpos.x;
	fdf->mouse.diff.y = y - fdf->mouse.lastpos.y;

	fdf->camera.a.y += fdf->mouse.diff.y * 0.2f;
	fdf->camera.a.x += fdf->mouse.diff.x * 0.2f;

	//fdf->camera.a.y = ft_clamp( fdf->camera.a.y, -90.0f, 90.0f );
	//fdf->camera.a.x = fmod(fdf->camera.a.x, 360.0f);

	fdf->mouse.lastpos.x = x;
	fdf->mouse.lastpos.y = y;
	/*if (fdf->mouse.diff.y != 0)
		fdf->camera.rot.y -= fdf->mouse.diff.y * 0.01f;
	if (fdf->mouse.diff.x != 0)
		fdf->camera.rot.x += fdf->mouse.diff.x * 0.01f;*/
	
	/*if (fdf->camera.rot.x > 90)
		fdf->camera.rot.x = 90;
	if (fdf->camera.rot.x < -90)
		fdf->camera.rot.x = -90;*/

	//key_event(0, env);

	mlx_clear_window(fdf->mlx, fdf->window);
	copy_mesh(fdf);
	fdf->img = libx_new_img(fdf->mlx, fdf->window_size.x, fdf->window_size.y);
	update_vectors(fdf);
	render(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->img->img_ptr, 0, 0);
	fdf_loop(fdf, env);
	return (0);
}
