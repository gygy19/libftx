/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 18:52:43 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/08 18:52:51 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

float	ft_clamp(float value, float max, float min)
{
    if (value > max)
        return (max);
    if (value < min)
        return (min);
    return (value);
}
