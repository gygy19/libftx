/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_look_at.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 21:14:13 by jguyet            #+#    #+#             */
/*   Updated: 2017/10/08 21:14:15 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

#include <math.h>

t_matrix4f    	*transform_fps_view(t_vector3f *eye, float yaw, float pitch)
{
	t_matrix4f	*view;
	t_matrix4f	*rotation;
	t_vector3f	*copy_eye;


	rotation = eulerAngleYX( yaw, pitch );
	copy_eye = new_vector3f(eye->x, eye->y, eye->z);
	view = transform_translation(rotation, copy_eye);
	return inverse_4x4(view);
}

/*
// If the pitch and yaw angles are in degrees,
	// they need to be converted to radians. Here
	// I assume the values are already converted to radians.
	float cosPitch = cos(pitch);
	float sinPitch = sin(pitch);
	float cosYaw = cos(yaw);
	float sinYaw = sin(yaw);

	vec3 xaxis( cosYaw, 0, -sinYaw );
	vec3 yaxis( sinYaw * sinPitch, cosPitch, cosYaw * sinPitch );
	vec3 zaxis( sinYaw * cosPitch, -sinPitch, cosYaw * cosPitch );

	// Create a 4x4 view matrix from the right, up, forward and eye position vectors
	mat4 viewMatrix(
		vec4(       xaxis.x,            yaxis.x,            zaxis.x,      0 ),
		vec4(       xaxis.y,            yaxis.y,            zaxis.y,      0 ),
		vec4(       xaxis.z,            yaxis.z,            zaxis.z,      0 ),
		vec4( -dot( xaxis, eye ), -dot( yaxis, eye ), -dot( zaxis, eye ), 1 )
		);

	//return viewMatrix;

	mat4 rotX = eulerAngleX( pitch );
	mat4 rotY = eulerAngleY( yaw );
	//mat4 rotation = rotY * rotX;
	mat4 rotation = eulerAngleYX( yaw, pitch );
	mat4 translation = translate(eye);

	return inverse( translation * rotation );
*/
