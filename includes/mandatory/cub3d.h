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
# include "../../libraries/minilibx-linux/mlx.h"
# include "../../libraries/libft/includes/libft.h"
# include "defines.h"
# include "structs.h"

/******************************************************************************
**	CUB3D
******************************************************************************/

void	set_param(t_game *game);
void	check_file(int	argc, char **argv, t_game *game);
void	read_file(t_game *game, char *file);
void	check_paths(t_game *game);

/******************************************************************************
**	ERROR
******************************************************************************/

void	return_free_error(int err, char **tab);
void	return_error(int err);
void	print_error_1(int err);
void	print_error_2(int err);

/******************************************************************************
**	BITMAP
******************************************************************************/

void	image_create(t_game *game);
void	fill_data(t_bmp *bmp, t_game *game);
void	image_header(t_bmp *bmp, int file);

/******************************************************************************
**	EVENTS
******************************************************************************/

int		release_key(int key, t_game *game);
int		press_key(int key, t_game *game);
int		close_window(t_game *game);
void	table_free(char **tab);

/******************************************************************************
**	GET PARAM
******************************************************************************/

void	get_param(t_game *game, char *line);
int		check_param(char *line);
void	get_texture(char *line, char **texture);
void	get_resolution(t_game *game, char *line);
int		check_digit(char *tab, char *set);

/******************************************************************************
**	GRAPHICS
******************************************************************************/

void	screen_resolution(t_game *game);
void	draw(t_game *game);
int		update(t_game *game);

/******************************************************************************
**	PARSING COLOR
******************************************************************************/

void	check_color(char **tab);
int		color_assemble(int red, int green, int blue);
int		get_color(char *line);
void	image_put(t_game *game, t_bmp *bmp, int file);
int		count_char(char *str, char c);

/******************************************************************************
**	PARSING FILE
******************************************************************************/

char	*full_line(t_game *game, char *line);
void	check_line(t_game *game, char *line, int fd);
int		map_col_size(int fd);
void	reset_path(t_game *game);
int		find_map(char *line);

/******************************************************************************
**	PARSING MAP & PARSING MAP 2
******************************************************************************/

void	count_arg(t_game *game, int fd);
void	map_extract(t_game *game, char *line, int fd);
void	map_check(t_game *game);
void	map_check2(t_game *game, char **tab);
void	inside_map(char **tab);
void	is_map_closed(t_game *game, char **tab);
void	check_f_c(t_game *game, char *line);

/******************************************************************************
**	PLAYER
******************************************************************************/

void	move_player(t_game *game);
void	player_position(t_game *game);
void	player_facing(t_game *game);
double	normalize_angle(double angle);

/******************************************************************************
**	RAYCATSTING & RAYCASTING 2
******************************************************************************/

double	dist2points(double x1, double y1, double x2, double y2);
void	dist2wall(t_game *game, double horz_dist, double vert_dist);
void	find_dist(t_game *game, int horz_hit, int vert_hit);
void	ray_facing(t_game *game, double ray);
void	raycast(t_game *game, double rayangle);
void	cast_all_rays(t_game *game);
void	check_horiz(t_game *game, int *horzhit);
void	horz_cast(t_game *game, int *horzhit);
void	check_vert(t_game *game, int *verthit);
void	vert_cast(t_game *game, int *verthit);

/******************************************************************************
**	SPRITES
******************************************************************************/

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

/******************************************************************************
**	TEXTURES
******************************************************************************/

void	texture_select(t_game *game);
void	texture_ident(t_game *game);
void	free_textures(t_game *game);
void	texture_load(t_game *game);
void	calculate_texture(t_game *game, int *x_tex, int side);

/******************************************************************************
**	WALLS
******************************************************************************/

void	draw_strip(t_game *game, int x, int side, int strip_height);
void	render_projection_walls(t_game *game, int i);
int		is_wall(t_game *game, int x, int y);
int		check_wall(t_game *game, double new_x, double new_y);
void	color_floor_ceiling(t_game *game, double wall_height, int i);

#endif
