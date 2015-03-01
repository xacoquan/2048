/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twothousandfortyheight.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 10:03:43 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 17:28:58 by xacoquan         ###   ########.fr       */
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


int 	check_board(t_env *env);
int 	check_case(t_env *env, int index, int *r, int num);
int		put_nbr_in_case(t_env *env, int *r, int r2);
int		rand_num(void);
void 	tmp_board(t_env *env);
int 	rand_pop_each(void);
void	get_moove_keys(t_env *env, ch2);
void	print_board(t_env *env, int maX, int maY);
void	set_first_rand(t_env *env);
int 	no_z_case(t_env *env);
int 	check_board(t_env *env);
void	left_rec(int **board, int y);
void	move_left(int **board);
void	right_rec(int **board, int y);
void	move_right(int **board);
void	up_rec(int **board, int x);
void	move_up(int **board);
void	down_rec(int **board, int x);
void	move_down(int **board);

#endif
