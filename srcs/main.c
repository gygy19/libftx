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

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char	*load_file(char *filename)
{
	int		fd;
	int		ret;
	char	buffer[100];
	char	*result;

	if ((fd = open(filename, O_RDWR)) < 3)
		return (NULL);
	if (!(result = ft_strnew(0)))
		return (NULL);
	while ((ret = read(fd, buffer, 99)) > 0)
	{
		buffer[ret] = '\0';
		result = ft_dstrjoin(result, buffer, 1);
	}
	close(fd);
	return (result);
}

void	load_size(t_fdf *fdf, char *file)
{
	int i;
	char 	**splitline;
	char	**splitnumber;

	splitline = ft_strsplit(file, '\n');
	i = 0;
	while (splitline[i])
	{
		splitnumber = ft_strsplit(splitline[i], ' ');
		if (array_length(splitnumber) > fdf->size.x)
			fdf->size.x = array_length(splitnumber);
		free_array(splitnumber);
		i++;
	}
	fdf->size.y = array_length(splitline);
	free_array(splitline);
}

BOOLEAN	load_points(t_fdf *fdf)
{
	int		y;
	int		x;

	if (!(fdf->sgrid = (t_vector3f***)malloc(sizeof(t_vector3f**) * fdf->size.y)))
		return (0);
	y = 0;
	while (y < fdf->size.y)
	{
		if (!(fdf->sgrid[y] = (t_vector3f**)malloc(sizeof(t_vector3f*) * fdf->size.x)))
			return (0);
		x = 0;
		while (x < fdf->size.x)
		{
			fdf->sgrid[y][x] = new_vector3f(x, 0, y);
			x++;
		}
		y++;
	}
	return (1);
}

void	set_points(t_fdf *fdf, char *file)
{
	int		y;
	int		x;
	char 	**splitline;
	char	**splitnumber;

	splitline = ft_strsplit(file, '\n');
	y = 0;
	while (splitline[y])
	{
		x = 0;
		splitnumber = ft_strsplit(splitline[y], ' ');
		while (splitnumber[x])
		{
			fdf->sgrid[y][x]->y = -ft_atoi(splitnumber[x]);
			x++;
		}
		free_array(splitnumber);
		y++;
	}
	fdf->size.y = array_length(splitline);
	free_array(splitline);
}

void	copy_grid(t_fdf *fdf)
{
	int		y;
	int		x;

	if (!(fdf->grid = (t_vector3f***)malloc(sizeof(t_vector3f**) * fdf->size.y)))
		return ;
	y = 0;
	while (y < fdf->size.y)
	{
		if (!(fdf->grid[y] = (t_vector3f**)malloc(sizeof(t_vector3f*) * fdf->size.x)))
			return ;
		x = 0;
		while (x < fdf->size.x)
		{
			fdf->grid[y][x] = fdf->sgrid[y][x];
			x++;
		}
		y++;
	}
}

t_fdf	*loadfdf(char *filename)
{
	t_fdf	*f;
	char	*file;

	if (!(f = (t_fdf*)malloc(sizeof(struct s_fdf))))
		return (NULL);
	f->filename = ft_strdup(filename);
	f->size.x = 0;
	f->size.y = 0;
	f->camera.rot.x = 11.7f;
	f->camera.rot.y = 5.5f;
	f->camera.rot.z = 0;
	f->camera.pos.x = -1.0f;
	f->camera.pos.y = 0;
	f->camera.pos.z = 3.0f;
	f->camera.scale.x = 9.0f;
	f->camera.scale.y = 9.0f;
	f->camera.scale.z = 9.0f;
	f->mouse.lastpos.x = -1;
	f->mouse.lastpos.y = -1;
	f->mouse.diff.x = 0;
	f->mouse.diff.y = 0;
	file = load_file(filename);
	ft_printf("%s", file);
	load_size(f, file);
	printf("size x: %f, size y: %f\n", f->size.x, f->size.y);
	load_points(f);
	set_points(f, file);
	ft_strdel(&file);
	return (f);
}

int	key_hook(int keycode, void **env)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)env[0];
	ft_printf("key event %d\n", keycode);
	if (keycode == 53)
	{
		exit(0);
	}
	if (keycode == 126)
		fdf->camera.rot.z += 0.1f;
	else if (keycode == 125)
		fdf->camera.rot.z -= 0.1f;
	else if (keycode == 123)
		fdf->camera.rot.y += 0.1f;
	else if (keycode == 124)
		fdf->camera.rot.y -= 0.1f;
	else if (keycode == 18)
		fdf->camera.scale.y -= 0.1f;
	else if (keycode == 19)
		fdf->camera.scale.y += 0.1f;
	else if (keycode == 13)
	{
		fdf->camera.pos.z++;
	}
	else if (keycode == 1)
	{
		fdf->camera.pos.z--;
	}
	else if (keycode == 0)
		fdf->camera.pos.x++;
	else if (keycode == 2)
		fdf->camera.pos.x--;
	else
	{
		return (0);
	}

	mlx_clear_window(fdf->mlx, fdf->window);
	copy_grid(fdf);
	fdf->img = libx_new_img(fdf->mlx, fdf->window_size.x, fdf->window_size.y);
	update_vectors(fdf);
	render(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->img->img_ptr, 0, 0);
	printf("rot x: %f y: %f z: %f\n", fdf->camera.rot.x, fdf->camera.rot.y, fdf->camera.rot.z);
	printf("scale x: %f y: %f z: %f\n", fdf->camera.scale.x, fdf->camera.scale.y, fdf->camera.scale.z);
	mlx_hook(fdf->window, 2, 0, key_hook, env);
	mlx_loop(fdf->mlx);
	return (0);
}

int mouse_hook(int x, int y, void **env)
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
	fdf->mouse.diff.x = fdf->mouse.lastpos.x - x;
	fdf->mouse.diff.y = fdf->mouse.lastpos.y - y;
	fdf->mouse.lastpos.x = x;
	fdf->mouse.lastpos.y = y;
	if (fdf->mouse.diff.y != 0)
		fdf->camera.rot.x -= fdf->mouse.diff.y * 0.1f;
	if (fdf->mouse.diff.x != 0)
		fdf->camera.rot.y += fdf->mouse.diff.x * 0.1f;
	printf("new mouse event x: %d, y: %d | diff x: %f, y:%f\n", x, y, fdf->mouse.diff.x, fdf->mouse.diff.y);
	
	mlx_clear_window(fdf->mlx, fdf->window);
	copy_grid(fdf);
	fdf->img = libx_new_img(fdf->mlx, fdf->window_size.x, fdf->window_size.y);
	update_vectors(fdf);
	render(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->img->img_ptr, 0, 0);
	printf("rot x: %f y: %f z: %f\n", fdf->camera.rot.x, fdf->camera.rot.y, fdf->camera.rot.z);
	printf("scale x: %f y: %f z: %f\n", fdf->camera.scale.x, fdf->camera.scale.y, fdf->camera.scale.z);
	mlx_hook(fdf->window, 2, 0, key_hook, env);
	mlx_loop(fdf->mlx);
	return (0);
}

int	scrool_hook(int keycode, int x, int y, void **env)
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
	mlx_clear_window(fdf->mlx, fdf->window);
	copy_grid(fdf);
	fdf->img = libx_new_img(fdf->mlx, fdf->window_size.x, fdf->window_size.y);
	update_vectors(fdf);
	render(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->img->img_ptr, 0, 0);
	printf("rot x: %f y: %f z: %f\n", fdf->camera.rot.x, fdf->camera.rot.y, fdf->camera.rot.z);
	printf("scale x: %f y: %f z: %f\n", fdf->camera.scale.x, fdf->camera.scale.y, fdf->camera.scale.z);
	mlx_hook(fdf->window, 2, 0, key_hook, env);
	mlx_loop(fdf->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	void	**env;

	if (argc == 2)
	{
		fdf = loadfdf(argv[1]);
		fdf->mlx = mlx_init();
		fdf->window_size.x = 1000;
		fdf->window_size.y = 1000;
		fdf->window = mlx_new_window(fdf->mlx, fdf->window_size.x, fdf->window_size.y, "title");
		fdf->img = libx_new_img(fdf->mlx, fdf->window_size.x, fdf->window_size.y);

		copy_grid(fdf);
		update_vectors(fdf);
		render(fdf);
		//free_array(fdf->grid);
		mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->img->img_ptr, 0, 0);

		env = (void **)malloc(sizeof(void *));
		env[0] = fdf;
		//mlx_mouse_hook(fdf->window, mouse_hook, env);
		mlx_hook(fdf->window, 2, 0, key_hook, env);
		mlx_hook(fdf->window, 6, 0, mouse_hook, env);
		mlx_hook(fdf->window, 4, 0, scrool_hook, env);
		mlx_loop(fdf->mlx);
	}
	return (0);
}
