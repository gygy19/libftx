/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:09:50 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/09 14:09:51 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	scroll_event(int keycode, int x, int y, void **env)
{
	t_fdf	*fdf;
	
	fdf = (t_fdf*)env[0];
	(void)x;
	(void)y;
	if (keycode == 5)
	{
		fdf->camera.scale.x++;
		fdf->camera.scale.y++;
		fdf->camera.scale.z++;
	}
	else if (keycode == 4)
	{
		fdf->camera.scale.x--;
		fdf->camera.scale.y--;
		fdf->camera.scale.z--;
	}
	key_event(0, env);
	return (0);
}
