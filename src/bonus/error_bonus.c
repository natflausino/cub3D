#include "../../includes/bonus/cub3d_bonus.h"

void	print_error_1(int err)
{
	if (err == -10)
		ft_putendl("Error\nFile must have .cub extension.\n");
	if (err == -11)
		ft_putendl("Error\nInvalid file .cub.\n");
	if (err == -12)
		ft_putendl("Error\nTry cub3D <file>.cub --save(optional).\n");
	if (err == -13)
		ft_putendl("Error\nMLX unable to load game.\n");
	if (err == -14)
		ft_putendl("Error\nUnable to create bmp file.\n");
	if (err == -15)
		ft_putendl("Error\nUnable to open <file>.cub.\n");
	if (err == -16)
		ft_putendl("Error\nMap must be surrounded by walls.\n");
	if (err == -17)
		ft_putendl("Error\nMap not found in provided file.\n");
	if (err == -18)
		ft_putendl("Error\nMisconfiguration on file.\n");
	if (err == -19)
		ft_putendl(
			"Error\nWrong number of player. Choose one: N, S, E or W in map.\n");
}

void	print_error_2(int err)
{
	if (err == -20)
	{
		ft_putendl("Error\nWrong resolution.\n");
		ft_putendl("R: 720 480 (positive integers).\n");
	}
	if (err == -21)
		ft_putendl("Error\nTexture path not found.\n");
	if (err == -22)
		ft_putendl("Error\nSprite texture not found.\n");
	if (err == -23)
		ft_putendl("Error\nExpected a <file>.xpm.\n");
	if (err == -24)
	{
		ft_putendl("Error\nWrong color parameter for ceiling or floor");
		ft_putendl("Expected R,G,B color between 0-255. Try: 0, 255, 255.\n");
	}
}

void	return_error(int err)
{
	if (err <= -10 && err >= -19)
		print_error_1(err);
	else if (err <= -20 && err >= -24)
		print_error_2(err);
	exit(err);
}

void	return_free_error(int err, char **tab)
{
	table_free(tab);
	if (err <= -10 && err >= -19)
		print_error_1(err);
	else if (err <= -20 && err >= -24)
		print_error_2(err);
	exit(err);
}
