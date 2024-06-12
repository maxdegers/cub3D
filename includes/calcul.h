/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:51:38 by gberthol          #+#    #+#             */
/*   Updated: 2024/05/29 14:20:43 by mbrousse         ###   ########.fr       */
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
	int			x;
}	t_ray;

void	display_column(t_map *map, t_data *data);
void	calc_delta_dist(t_ray *ray);
#endif