/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 13:36:37 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/09 13:36:38 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	load_mesh_size(t_fdf *fdf, char *file)
{
	int		i;
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

BOOLEAN	load_mesh_vertex(t_fdf *fdf)
{
	int		y;
	int		x;

	if (!(fdf->sgrid = (t_vector3f***)malloc(sizeof(t_vector3f**) * (fdf->size.y + 1))))
		return (0);
	y = 0;
	while (y < fdf->size.y)
	{
		if (!(fdf->sgrid[y] = (t_vector3f**)malloc(sizeof(t_vector3f*) * (fdf->size.x + 1))))
			return (0);
		x = 0;
		while (x < fdf->size.x)
		{
			fdf->sgrid[y][x] = NULL;
			x++;
		}
		fdf->sgrid[y][x] = NULL;
		y++;
	}
	fdf->sgrid[y] = NULL;
	return (1);
}

void	set_mesh_vertex(t_fdf *fdf, char *file)
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
			fdf->sgrid[y][x] = new_vector3f(x, 0, y);
			fdf->sgrid[y][x]->y = -ft_atoi(splitnumber[x]);
			x++;
		}
		free_array(splitnumber);
		y++;
	}
	fdf->size.y = array_length(splitline);
	free_array(splitline);
}

void	copy_mesh(t_fdf *fdf)
{
	int		y;
	int		x;

	if (!(fdf->grid = (t_vector3f***)malloc(sizeof(t_vector3f**) * (fdf->size.y + 1))))
		return ;
	y = 0;
	while (y < fdf->size.y)
	{
		if (!(fdf->grid[y] = (t_vector3f**)malloc(sizeof(t_vector3f*) * (fdf->size.x + 1))))
			return ;
		x = 0;
		while (x < fdf->size.x)
		{
			if (fdf->sgrid[y][x])
			{
				fdf->grid[y][x] = new_vector3f(fdf->sgrid[y][x]->x,\
					fdf->sgrid[y][x]->y, fdf->sgrid[y][x]->z);
			}
			else
				fdf->grid[y][x] = NULL;
			x++;
		}
		fdf->grid[y][x] = NULL;
		y++;
	}
	fdf->grid[y] = NULL;
}
