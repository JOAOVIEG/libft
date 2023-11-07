/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:45:37 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/07 18:08:19 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

#define SO_LONG_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "../libs/minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include "../libs/libft/libft.h"
#include "../libs/get_next_line/get_next_line.h"
#include <limits.h>
#include "../libs/ft_printf/ft_printf.h"
#include <stdlib.h>

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct		s_pos_list
{
    t_pos				pos;
    struct s_pos_list	*next;
}						t_pos_list;

typedef struct s_map
{
	int			width;
	int			height;
	t_pos		player;
	t_pos 		exit;
	t_pos_list	*collectibles;
}			t_map;

typedef struct s_img
{
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
}			t_img;

typedef	struct s_win
{
	char	**file_map;
	char	**map_copy;
	//void	*mlx_ptr;
	//void	*win_ptr;
	//int		n_moves;
	t_map	map;
	//t_img	*img;
}			t_win;

void	so_long(char *file);
void	game_error_msg(char *message, t_win *game);
void    shut_game_down(t_win *game);
void	shut_game(t_win *game);
void	game_build(char *file, t_win *game);
int		check_file_ext(char *file);
void	read_map(int fd, t_win *game);
void	map_init(t_win *game, int fd, char *line);
void	copy_lines(t_win *game, int fd, char *line);
int		resize_map(t_win *game, int map_size);
int		map_checks(t_win *game);
void	free_strdup(char **str);
int		is_rectangular(char **map, int height, int witdth);
int		is_closed(char **map, int height, int width);
int		is_valid_chars(char **map, int height, int width);
int		check_duplicate_char(char **map, int height, int width);
int		count_exit(char **map, int height, int width);
int		count_player(char **map, int height, int width);
int		check_nbr_chrs(char **map, int height, int width);
int		check_path_to_exit(t_win *game, int height, int width);
int		check_path_to_collectibles(t_win *game, int height, int width);
char	**copy_map(t_win *game);
t_pos	get_player_pos(char **map, int height, int width);
t_pos	get_exit_pos(char **map, int height, int width);
t_pos_list	*get_collectible_pos(char **map, int height, int width);
void		flood_fill(t_win map, t_pos start, t_pos target);
int		listed_flood_fill(t_win	game, t_pos_list *collectibles, t_pos target);
void	free_pos_list(t_pos_list *list);
int 	check_if_visited(t_win game, t_pos target);
int 	mark_if_visited(t_win game, t_pos target);
#endif