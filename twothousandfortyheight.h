/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twothousandfortyheight.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:03:43 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 20:18:56 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWOTHOUSANDFORTYHEIGHT_H
# define TWOTHOUSANDFORTYHEIGHT_H
# define NBR 4
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <termios.h>
# include <stdbool.h>
# include <stdint.h>
# include <time.h>
# include <signal.h>
# include <ncurses.h>


typedef struct s_env
{
	 int	**board;
	 int	**tmp;

}				t_env;


int 	no_z_case(int **board);
int 	check_board(int **board, int **tmp);
int 	chheck_move(int **board, int **tmp);
int		put_nbr_in_case(int **board, int r, int r2);
int		rand_num(void);
void 	tmp_board(int **board, int **tmp);
int 	rand_pop_each(void);
void	get_moove_keys(int **board, int ch2, int **tmp);
void    show_board(int **board, int maX, int maY);
void	print_board(int **board, int maX, int maY);
void	set_first_rand(int **board);
void	left_rec(int **board, int y);
void	move_left(int **board);
void	right_rec(int **board, int y);
void	move_right(int **board);
void	up_rec(int **env, int x);
void 	move_up(int **board);
void	down_rec(int **board, int x);
void	move_down(int **board);
void    ft_bzero(void *s, size_t n);
void    *ft_memalloc(size_t size);


#endif
