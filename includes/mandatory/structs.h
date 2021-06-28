#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct s_file
{
	int		width;
	int		height;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*s_path;
	int		color_floor;
	int		color_ceiling;
	int		map_col;
	int		map_row;
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
	int			s_hei;
	t_sprite	*sprite;
	t_data		data;
	t_tex		*tex;
	t_player	player;
	t_ray		ray;
	t_ray		*rays;
	t_file		file;
	int			floor_bool;
	int			celling_bool;
}				t_game;

#endif
