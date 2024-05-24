/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:17:42 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/24 13:15:54 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H



# include "../mlx_linux/mlx_int.h"
# include "../libft/incs/libft.h"
# include "../mlx_linux/mlx.h"

# define WIDTH 800
# define HEIGHT 600

# define ERROR_ARG "   Error:\nTry : ./cube3D <map.cub>\n"
# define ERROR_FILE "   Error:\nFile not found\n"
# define ERROR_FILE_EXT "   Error:\nFile extension not valid\n" 
# define ERROR_FILE_NAME "   Error:\nFile name not valid\n" 
# define ERROR_FILE_OPEN "   Error:\nFile can't be opened\n"
# define ERROR_NO_PATH "   Error:\nNO path for NO texture\n"
# define ERROR_SO_PATH "   Error:\nNO path for SO texture\n"
# define ERROR_WE_PATH "   Error:\nNO path for WE texture\n"
# define ERROR_EA_PATH "   Error:\nNO path for EA texture\n"
# define ERROR_C_COLOR "   Error:\nNO color for Ceiling\n"
# define ERROR_F_COLOR "   Error:\nNO color for Floor\n"
# define ERROR_MAP_CHAR "   Error:\nMap contains invalid characters\n"
# define ERROR_MAP_NL "   Error:\nMap contains empty lines\n"
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
	t_mlx	*g;
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
//	main_loop.c
int		main_loop(t_data *data, t_mlx *cub);
/*****************************************************************************/
/*                                  PARSING                                  */
/*****************************************************************************/
//	parse_map.c
int		parse_map(char *path, t_data *data);
//	setup.c
void	ft_setup_map(t_data *data);
//	check_file.c
int		ft_check_file(char *path, t_data *data);
//	parse_line.c
void	ft_parse_line(char *line, t_data *data);
//	check_data.c
int		check_data(t_data *data);
int		is_map(char *line);
/*****************************************************************************/
/*                                   UTILS                                   */
/*****************************************************************************/
//	mlx_utils.c
void	mlx_destroyer(t_mlx *g);
int		close_window(t_mlx *g);
/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/
#endif