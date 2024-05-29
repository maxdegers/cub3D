/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:51:38 by gberthol          #+#    #+#             */
/*   Updated: 2024/05/28 13:51:38 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCUL_H
# define CALCUL_H
# include "cub3D.h"

typedef struct s_vector_i
{
	int	x;
	int	y;
}	t_vector_i;

typedef struct s_player
{
	t_vector	dir;
	t_vector	pos;
	t_vector	plane;
	double		angle;
}	t_player;

typedef struct s_ray
{
	t_vector	dir;
	t_vector	side_dist;
	t_vector	delta_dist;
	t_vector_i	step;
	t_vector_i	pos;
	double		perm_wall_dist;
	int			hit;
	int			side;
	int			line_height;
}	t_ray;

#endif