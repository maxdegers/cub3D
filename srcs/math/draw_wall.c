/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:06:03 by gberthol          #+#    #+#             */
/*   Updated: 2024/06/13 14:06:03 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calcul.h"
#include "cub3D.h"
#include <math.h>

int	get_tex_num(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step.x > 0)
			return (0);
		else
			return (1);
	}
	else
	{
		if (ray->step.y > 0)
			return (2);
		else
			return (3);
	}
}

void	calc_where_draw(int *draw, t_ray *ray)
{
	draw[0] = (-ray->line_height * 0.5) + (HEIGHT * 0.5);
	if (draw[0] < 0)
		draw[0] = 0;
	draw[1] = (ray->line_height * 0.5) + (HEIGHT * 0.5);
	if (draw[1] >= HEIGHT)
		draw[1] = HEIGHT - 1;
}

int	calc_tex_x(t_data *data, t_ray *ray)
{
	double	wall_x;
	int		result;

	if (ray->side == 0)
		wall_x = data->map->player->pos.y + ray->perm_wall_dist * ray->dir.y;
	else
		wall_x = data->map->player->pos.x + ray->perm_wall_dist * ray->dir.x;
	wall_x -= floor((wall_x));
	result = (int)(wall_x * (double)TEX_WIDTH);
	if (ray->side == 0 && ray->dir.x > 0)
		result = TEX_WIDTH - result - 1;
	if (ray->side == 1 && ray->dir.y < 0)
		result = TEX_WIDTH - result - 1;
	return (result);
}

void	draw_line(t_data *data, t_ray *ray, int *tex, int *draw)
{
	double		step;
	double		texPos;
	int			y;
	uint32_t	color;
	int			i;

	y = draw[0];
	i = 0;
	step = (double)TEX_HEIGHT / ray->line_height;
	texPos = step * (draw[0] - (HEIGHT * 0.5) + (ray->line_height * 0.5));
	while (i < y)
		my_mlx_pixel_put(data, draw[2], i++, data->map->c.rgb);
	while (y < draw[1])
	{
		tex[2] = (int)texPos & (TEX_HEIGHT - 1);
		texPos += step;
		color = data->tex[tex[0]].data[TEX_WIDTH * tex[2] + tex[1]];
		my_mlx_pixel_put(data, draw[2], y, color);
		y++;
	}
	while (y < HEIGHT)
		my_mlx_pixel_put(data, draw[2], y++, data->map->f.rgb);
}

void	draw_wall(t_data *data, t_ray *ray, int x)
{
	int draw[3];
	int tex[3];

	calc_where_draw(draw, ray);
	draw[2] = x;
	tex[0] = get_tex_num(ray);
	tex[1] = calc_tex_x(data, ray);
	draw_line(data, ray, tex, draw);
}