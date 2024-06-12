/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_delta_dist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:17:35 by gberthol          #+#    #+#             */
/*   Updated: 2024/06/12 13:17:35 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calcul.h"

void	calc_delta_dist(t_ray *ray)
{
	if (!ray->dir.x)
		ray->delta_dist.x = 1e30;
	else
		ray->delta_dist.x = (-((1 / ray->dir.x) < 0)
				+ ((1 / ray->dir.x) > 0)) * ((1 / ray->dir.x));
	if (!ray->dir.y)
		ray->delta_dist.y = 1e30;
	else
		ray->delta_dist.y = (-((1 / ray->dir.y) < 0)
				+ ((1 / ray->dir.y) > 0)) * ((1 / ray->dir.y));
}
