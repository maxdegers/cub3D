/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:17:42 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/23 18:43:05 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx_int.h"
# include "../libft/incs/libft.h"
# include "../mlx_linux/mlx.h"

# define ERROR_ARG "   Error:\nTry : ./cube3D <map.cub>\n"
# define ERROR_FILE "   Error:\nFile not found\n"
# define ERROR_FILE_EXT "   Error:\nFile extension not valid\n" 
# define ERROR_FILE_NAME "   Error:\nFile name not valid\n" 
# define ERROR_FILE_OPEN "   Error:\nFile can't be opened\n"
/*****************************************************************************/
/*                                   DIR                                     */
/*****************************************************************************/
# define NO_DIR 0
# define NORTH 1
# define SOUTH 2
# define WEST 3
# define EAST 4
/*****************************************************************************/
/*                                   ENUM                                    */
/*****************************************************************************/

/*****************************************************************************/
/*                                  STRUCT                                   */
/*****************************************************************************/
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_map
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	t_vector	player;
	int			player_dir;
	t_color		f;
	t_color		c;
	t_vector	window;
	char		**map;
}	t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_data
{
	t_mlx	*mlx;
	t_map	*map;
}	t_data;

/*****************************************************************************/
/*                                   ERROR                                   */
/*****************************************************************************/
//	error.c
void	ft_puterror(char *message);
void	ft_perror(void);
void	free_all(t_data *data);
void	exit_error(char *message, t_data *data);
//	free.c
void	ft_free_map(t_map *map);
/*****************************************************************************/
/*                                   MAIN                                    */
/*****************************************************************************/
//	main.c

/*****************************************************************************/
/*                                  PARSING                                  */
/*****************************************************************************/
//	parse_map.c
int		parse_map(char *path, t_data *data);
//	setup.c
void	ft_setup_map(t_data *data);
//	check_file.c
int		ft_check_file(char *path, t_data *data);
/*****************************************************************************/
/*                                   UTILS                                   */
/*****************************************************************************/

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
#endif