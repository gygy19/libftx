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

t_model	*new_model(void)
{
	t_model	*t;

	if (!(t = (t_model*)malloc(sizeof(struct s_model))))
		return (NULL);
	t->translation = NULL;
	t->rotation = NULL;
	t->scale = NULL;
	t->vpos = NULL;
	t->vrot = NULL;
	t->vscale = NULL;
	t->matrix = NULL;
	return (t);
}

void		destruct_model(t_model *t)
{
	if (t->translation != NULL)
		destruct_matrix4f(t->translation);
	if (t->rotation != NULL)
		destruct_matrix4f(t->rotation);
	if (t->scale != NULL)
		destruct_matrix4f(t->scale);
	if (t->matrix != NULL)
		destruct_matrix4f(t->matrix);
	free(t);
}
