/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:17:42 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/05 15:24:37 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx_int.h"
# include "../libft/incs/libft.h"
# include "../mlx_linux/mlx.h"
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdbool.h>

// # define WIDTH 1920
// # define HEIGHT 1080

# define WIDTH 920
# define HEIGHT 720

# define ROTATE_SPEED 0.05

# define ERROR_MALLOC "Cub3D: Malloc failed\n"
# define ERROR_ARG "Cub3D: Try : ./cube3D <map.cub>\n"
# define ERROR_FILE "Cub3D: File not found\n"
# define ERROR_FILE_EXT "Cub3D: File extension not valid\n" 
# define ERROR_FILE_NAME "Cub3D: File name not valid\n" 
# define ERROR_FILE_OPEN "Cub3D: File can't be opened\n"
# define ERROR_NO_PATH "Cub3D: NO path for NO texture\n"
# define ERROR_SO_PATH "Cub3D: NO path for SO texture\n"
# define ERROR_WE_PATH "Cub3D: NO path for WE texture\n"
# define ERROR_EA_PATH "Cub3D: NO path for EA texture\n"
# define ERROR_C_COLOR "Cub3D: NO color for Ceiling\n"
# define ERROR_F_COLOR "Cub3D: NO color for Floor\n"
# define ERROR_MAP_CHAR "Cub3D: Map contains invalid characters\n"
# define ERROR_MAP_NL "Cub3D: Map contains empty lines\n"
# define ERROR_FILE_CONTENT "Cub3D: File content is not valid\n"
# define ERROR_MAP_BORDER "Cub3D: Map is not surrounded by walls\n"
# define ERROR_FILE_REPETITION "Cub3D: Repetition of data in file\n"
# define ERROR_MLX "Cub3D: Mlx failed\n"

/*****************************************************************************/
/*                                   COLOR                                   */
/*****************************************************************************/
# define BLUE			0x3a8399
# define RED			0xFF0000
# define YELLOW			0xffff00
# define YELLOW_SIDE	0xa67924
# define BROWN			0x7a5631
# define BLACK			0x000000
# define WHITE			0xffffff
/*****************************************************************************/
/*                                   DIR                                     */
/*****************************************************************************/
# define NO_DIR 0
# define NORTH 1
# define SOUTH 2
# define WEST 3
# define EAST 4
# define FLOOR 5
# define CEILING 6
/*****************************************************************************/
/*                                   ENUM                                    */
/*****************************************************************************/

/*****************************************************************************/
/*                                  STRUCT                                   */
/*****************************************************************************/

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_player
{
	t_vector	dir;
	t_vector	pos;
	t_vector	plane;
	double		mov_speed;
	double		rot_speed;
	double		angle;
}	t_player;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	rgb;
}	t_color;

typedef struct s_map
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	t_vector	player_pos;
	t_player	*player;
	int			player_dir;
	t_color		f;
	t_color		c;
	t_vector	window;
	char		**map;
	int			zoom;
}	t_map;

typedef	struct s_im
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_im;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_im	*img;
}	t_mlx;

typedef struct s_mm
{
	int		xt;
	int		yl;
	int		xb;
	int		yr;
	char	**map;
	int		psize;
	int		wsize;
}	t_mm;

typedef struct s_data
{
	t_mlx	*g;
	t_map	*map;
	t_mm	*mm;
	bool	mv_up;
	bool	mv_down;
	bool	mv_left;
	bool	mv_right;
	bool	rot_left;
	bool	rot_right;
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
void	free_mlx(t_mlx *g);
/*****************************************************************************/
/*                                   MAIN                                    */
/*****************************************************************************/
//	main_loop.c
int		main_loop(t_data *data, t_mlx *cub);
/*****************************************************************************/
/*                                  PARSING                                  */
/*****************************************************************************/
//	parse_map.c
int		parse_map(char *path, t_data *data);
//	setup.c
void	ft_setup_map(t_data *data);
int		rgb_to_int(double r, double g, double b);
//	check_file.c
int		ft_check_file(char *path, t_data *data);
int		check_path_exist(char *path);
int		check_path_type(char *path, char *type);
//	parse_line.c
void	ft_parse_line(char *line, t_data *data, char **lines);
//	check_data.c
int		check_data(t_data *data);
int		is_map(char *line);
// read_file.c
char	*get_file(char *path);
// parse_texture.c
void	parse_texture(char **split, t_data *data, int dir, char **lines);
int		check_texture(t_data *data);
/*****************************************************************************/
/*                                   UTILS                                   */
/*****************************************************************************/
//	mlx_utils.c
void	mlx_destroyer(t_mlx *g);
int		close_window(t_mlx *g);
//	parse_line_utils.c
int		ft_tablen(char **tab);
int		ft_add_to_map(char *line, t_data *data);
int		ft_striscolor(char *str);
// check_map_utils.c
int		check_position(char **map, size_t i, size_t j);
int		check_border(char **map, size_t i, size_t j);
int		ft_check_if_is_player(t_data *data, size_t i, size_t j, int	b);

/*****************************************************************************/
/*                                 MINI_MAPS                                 */
/*****************************************************************************/

void	display_minimap(t_map *map, t_data *data);

/*****************************************************************************/
/*                                 MOVEMENT                                  */
/*****************************************************************************/

void	ft_move_u(t_data *data);
void	ft_move_d(t_data *data);
void	ft_move_l(t_data *data);
void	ft_move_r(t_data *data);
void	ft_rotate_l(t_data *data);
void	ft_rotate_r(t_data *data);

/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
#endif