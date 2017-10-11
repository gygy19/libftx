/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:31:16 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/07 15:32:06 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	void	**env;

	if (argc == 2)
	{
		fdf = new_fdf(argv[1]);
		fdf->mlx = mlx_init();
		fdf->window_size.x = 1500;
		fdf->window_size.y = 1000;
		fdf->window = mlx_new_window(fdf->mlx, fdf->window_size.x, fdf->window_size.y, "title");
		fdf->img = libx_new_img(fdf->mlx, fdf->window_size.x, fdf->window_size.y);

		copy_mesh(fdf);
		update_vectors(fdf);
		render(fdf);
		//free_array(fdf->grid);
		mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->img->img_ptr, 0, 0);

		env = (void **)malloc(sizeof(void *));
		env[0] = fdf;
		fdf_loop(fdf, env);
	}
	return (0);
}
