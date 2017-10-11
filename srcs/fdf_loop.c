/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:16:12 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/09 14:16:13 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_loop(t_fdf *fdf, void **env)
{
	mlx_hook(fdf->window, 2, 0, key_event, env);
	mlx_hook(fdf->window, 6, 0, mouse_event, env);
	mlx_hook(fdf->window, 4, 0, scroll_event, env);
	mlx_loop(fdf->mlx);
}
