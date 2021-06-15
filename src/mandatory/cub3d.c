#include "../../includes/mandatory/cub3d.h"

void	check_paths(t_game *game)
{
	if (!game->file.map_row)
	{
		return_error(-17);
	}
	if (!game->file.so_path || !game->file.s_path || !game->file.we_path
		|| !game->file.no_path || !game->file.ea_path)
	{
		free_textures(game);
		return_error(-21);
	}
}

void	read_file(t_game *game, char *file)
{
	int		fd;
	int		fd1;
	int		gnl;
	char	*line;

	gnl = 1;
	game->file.args = 0;
	reset_path(game);
	fd = open(file, O_RDONLY);
	fd1 = open(file, O_RDONLY);
	game->file.map_col = map_col_size(fd1);
	while (gnl != 0)
	{
		gnl = get_next_line(fd, &line);
		check_line(game, line, fd);
		free(line);
	}
	check_paths(game);
}

void	check_file(int	argc, char **argv, t_game *game)
{
	char	**split;
	char	*extension;

	game->init = 0;
	if (argc == 1 || argc > 3)
		return_error(-12);
	split = ft_split(argv[1], '.');
	extension = split[c_split(argv[1], '.') - 1];
	if (ft_strcmp(extension, "cub") != 0)
		return_free_error(-10, split);
	if (open(argv[1], O_RDONLY) == -1)
		return_free_error(-15, split);
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save") != 0)
			return_free_error(-12, split);
		else
			game->init = 1;
	}
	table_free(split);
	read_file(game, argv[1]);
}

void	set_param(t_game *game)
{
	game->fov = PI / 3;
	game->block = 64;
	game->file.player_found = 0;
	game->ray.dist_wall = (int *)ft_calloc(1, sizeof(int) * game->file.width);
	num_sprites(game);
	game->sprite = ft_calloc(1, sizeof(t_sprite) * (game->num_sprite + 1));
	game->tex = ft_calloc(7, sizeof(t_tex));
	texture_load(game);
	player_position(game);
	player_facing(game);
	game->dist2player = (game->file.width / 2) / tan(game->fov / 2);
	game->player.radius = 5;
	game->player.turn_direction = 0;
	game->player.walk_direction = 0;
	game->player.left_right = 0;
	game->player.walk_speed = 2;
	game->player.turn_speed = 1.3 * (PI / 180);
	game->floor_bool = 0;
	game->celling_bool = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	game.data.mlx = mlx_init();
	check_file(argc, argv, &game);
	set_param(&game);
	if (game.init == 0)
		game.data.win = mlx_new_window(game.data.mlx,
				game.file.width, game.file.height, "Cub3D");
	game.data.img = mlx_new_image(game.data.mlx,
			game.file.width, game.file.height);
	game.data.addr = (int *)mlx_get_data_addr(game.data.img,
			&game.data.bpp, &game.data.line_len, &game.data.endian);
	draw(&game);
	if (game.init == 0)
	{
		mlx_hook(game.data.win, KEYPRESS, (1l << 0), press_key, &game);
		mlx_hook(game.data.win, KEYRELEASE, (1l << 1), release_key, &game);
		mlx_hook(game.data.win, WIN_BUTTON_X, (1l << 17), close_window, &game);
		mlx_loop_hook(game.data.mlx, update, &game);
		mlx_loop(game.data.mlx);
	}
	return (0);
}
