/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 18:57:18 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/08 18:57:19 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

#include <stdlib.h>

t_view	*new_view(void)
{
	t_view	*t;

	if (!(t = (t_view*)malloc(sizeof(struct s_view))))
		return (NULL);
	t->translation = NULL;
	t->rotation = NULL;
	t->orientation = NULL;
	t->vpos = NULL;
	t->vrot = NULL;
	//t->vorientation = NULL;
	return (t);
}

void		destruct_view(t_view *t)
{
	if (t->translation != NULL)
		destruct_matrix4f(t->translation);
	if (t->rotation != NULL)
		destruct_matrix4f(t->rotation);
	if (t->orientation != NULL)
		destruct_matrix4f(t->orientation);
	if (t->matrix != NULL)
		destruct_matrix4f(t->matrix);
	free(t);
}
