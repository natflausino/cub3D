#ifndef CUB3D_H
# define CUB3D_H

/******************************************************************************
**	LIBRARIES
******************************************************************************/
# include <math.h>
# include <stdio.h>
# include <float.h>
# include <stdbool.h>
# include <fcntl.h>
# include "error.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"

/******************************************************************************
**	LINUX SCRIPT KEYCODES
******************************************************************************/
# define KEYPRESS 2
# define KEYRELEASE 3
# define ESC 0x00ff1b
# define WIN_BUTTON_X 33
# define MOUSE_1 1
# define W 0x0077
# define S 0x0073
# define D 0x0064
# define A 0x0061
# define UP 0x00ff52
# define DOWN 0x00ff54
# define RIGHT 0x00ff53
# define LEFT 0x00ff51

/******************************************************************************
**	MAP DEFNITIONS
******************************************************************************/
# define WALL 0
# define N_TEX 1
# define S_TEX 2
# define E_TEX 3
# define W_TEX 4
# define SP 5
# define PI 3.14159265
# define TWO_PI 6.28316530

/******************************************************************************
**	STRUCTS
******************************************************************************/
typedef struct s_file
{
	int		width;
	int		height;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*s_path;
	//char	*index;
	int		color_floor;
	int		color_ceiling;
	int		max_line;
	int		map_row;
	//char	*map;
	char	**tab;
	int		player_found;
	int		args;
}				t_file;

typedef struct s_data
{
	int		*buff;
	void	*mlx;
	void	*win;
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data;

typedef struct s_player
{
	double	x;
	double	y;
	double	width;
	double	height;
	double	radius;
	double	left_right;
	double	walk_direction;
	double	turn_direction;
	double	rotation_angle;
	double	walk_speed;
	double	turn_speed;
}				t_player;

typedef struct s_ray
{
	double		angle;
	int			*dist_wall;
	double		wall_hitx;
	double		wall_hity;
	double		wall_dist;
	double		hit_vx;
	double		hit_vy;
	double		hit_hx;
	double		hit_hy;
	int			was_hit_v;
	double		interc_x;
	double		interc_y;
	int			face_up;
	int			face_dw;
	int			face_ri;
	int			face_le;
	double		x_step;
	double		y_step;
}				t_ray;

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
}				t_color;

typedef struct s_tex
{
	int			*addr;
	int			bpp;
	int			l_len;
	int			endian;
	void		*img;
	int			tex_width;
	int			tex_height;
}				t_tex;

typedef struct s_bmp
{
	unsigned char	bmp_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_imported;
}					t_bmp;

typedef struct s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct s_sprite
{
	double		dist;
	double		angle;
	int			visible;
	t_coord		pos;

}				t_sprite;

typedef struct s_game
{
	double		fov;
	int			block;
	int			init;
	int			ident;
	int			num_sprite;
	double		dist2player;
	int			end;
	int			s_height;
	t_sprite	*sprite;
	t_data		data;
	t_tex		*tex;
	t_player	player;
	t_ray		ray;
	t_file		file;
	int			floor_bool;
	int			celling_bool;
}				t_game;

/******************************************************************************
**	FUNCTIONS
******************************************************************************/

void	set_param(t_game *game);
void	reset_path(t_game *game);
void	get_param(t_game *game, char *line);
int		check_param(char *line);
void	check_file(int	argc, char **argv, t_game *game);
void	read_file(t_game *game, char *file);
int		max_line_size(int fd);
void	is_map_closed(t_game *game, char **tab);
void	map_check(t_game *game, char **tab);
void	map_error(t_game *game);
void	map_extract(t_game *game, char *line, int fd);
void	along_map(char **tab);
int		get_color(char *line);
void	get_texture(char *line, char **texture);
void	get_resolution(t_game *game, char *line);
void	screen_resolution(t_game *game);
void	check_color(char **tab);
void	check_line(t_game *game, char *line, int fd);
int		find_map(char *line);
char	*full_line(t_game *game, char *line);
int		color_assemble(int red, int green, int blue);
void	player_facing(t_game *game);
void	player_position(t_game *game);
int		count_char(char *str, char c);
int		check_digit(char *tab, char *set);
void	table_free(char **tab);
double	normalize_angle(double angle);
double	dist2points(double x1, double y1, double x2, double y2);
void	image_header(t_bmp *bmp, int file);
void	fill_data(t_bmp *bmp, t_game *game);
void	image_create(t_game *game);
void	draw(t_game *game);
int		close_window(t_game *game);
int		press_key(int key, t_game *game);
int		release_key(int key, t_game *game);
void	image_put(t_game *game, t_bmp *bmp, int file);
void	move_player(t_game *game);
int		update(t_game *game);
void	dist2wall(t_game *game, double horz_dist, double vert_dist);
void	find_dist(t_game *game, int horz_hit, int vert_hit);
void	ray_facing(t_game *game, double ray);
void	raycast(t_game *game, double rayangle);
void	castrays(t_game *game);
void	check_horiz(t_game *game, int *horzhit);
void	horz_cast(t_game *game, int *horzhit);
void	check_vert(t_game *game, int *verthit);
void	vert_cast(t_game *game, int *verthit);
void	sprite_height(t_game *game, int *start, int *end, int *i);
void	draw_sprite(t_game *game, int x, int s_pos, int sp);
void	set_sprite(t_game *game, int i, int *s_pos);
void	sprite_param(t_game *game);
void	sprite_angle(t_game *game);
void	sort_sprite(t_game *game);
void	render_sprite(t_game *game);
void	sprite_visible(t_game *game, int x, int y);
void	find_sprite(t_game *game);
void	num_sprites(t_game *game);
void	texture_select(t_game *game);
void	texture_ident(t_game *game);
void	free_textures(t_game *game);
void	texture_load(t_game *game);
void	calculate_texture(t_game *game, int *x_tex, int side);
void	color_floor_ceiling(t_game *game, double wall_height, int i);
void	draw_strip(t_game *game, int x, int side, int strip_height);
void	render_projection_walls(t_game *game, int i);
int		is_wall(t_game *game, int x, int y);
int		check_wall(t_game *game, double new_x, double new_y);
void	return_error(int err);

#endif
