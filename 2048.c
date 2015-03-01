/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:51:11 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 17:42:58 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twothousandfortyheight.h"


int 	no_z_case(t_env *env)
{
	int y;
	int x;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (env->board[y][x] == 0)
				return (1);
		}
	}
	return (0);
}

int 	check_board(t_env *env, int **tmp)
{
	int y;
	int x;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (env->board[y][x] != tmp[y][x])
				return (1);
		}
	}
	return (0);
}

int check_move(t_env *env)
{
	move_down(env->board);
	if (check_board(env->board, env->tmp))
	{
		tmp_board(env->board, env->tmp);
		return (1);
	}
	tmp_board(env->board, env->tmp);
	move_up(env->board);
	if (check_board(env->board, env->tmp))
	{
		tmp_board(env->board, env->tmp);
		return (1);
	}
	tmp_board(env->board, env->tmp);
	move_left(env->board);
	if (check_board(env->board, env->tmp))
	{
		tmp_board(env->board, env->tmp);
		return (1);
	}
	tmp_board(env->board, env->tmp);
	move_right(env->board);
	if (check_board(env->board, env->tmp))
	{
		tmp_board(env->board, env->tmp);
		return (1);
	}
	tmp_board(env->board, env->tmp);
	return (0);
}

int 	check_case(t_env *env, int index, int *r, int num )
{
	index = 1;
	if (*r > 0)
		return (*r--);
	else
	{
		env->board[y][x] = num;
		return (1);
	}
}

int		put_nbr_in_case(t_env *env, int *r, int r2)
{
	int x;
	int y;
	int i;

	i = 0;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (env->board[y][x] == 0 && (check_case([y][x], i, &r, r2)))
			{
				return (1);
			}	
		}
		if (y == 3 && i == 1)
		{
			y = -1;
			x = -1;
		}
	}
	return (0);
}

int		rand_num(void)
{
	srand(time(NULL));
	return (rand() % 24);
}

void 	tmp_board(t_env *env, t_env *env)
{
	int x;
	int y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			env->tmp[y][x] = env->board[y][x];
	}
}

int 	rand_pop_each(void)
{
	int r;
	srand(time(null));
	r = rand() % 2 + 1 ;
	return (r);
}

void	get_moove_keys(t_env *env, int ch2)
{
	while (ch2 != 27)
	{	
		if (ch2 == 68)
			move_left(env->board);
		else if (ch2 == 67)
			move_right(env->board);
		else if (ch2 == 65)
			move_up(env->board);
		else if (ch2 == 66)
			move_down(env->board);
		if (check_board(env->board, env->tmp))
			put_nbr_in_case(env->board, rand_num(), rand_pop_each());
		else if (!check_board(env->board, env->tmp) /
				&& !no_z_case(env->board) && !check_move(env->board, env->tmp))
		{
			mvprintw(50, 50 , "TA LOSE SALE MERDE");
			break;
		}
	}
}

void	print_board(t_env *env, int maX, int maY)
{
	getmaxyx(stdscr, maY, maX);
	wclear(stdscr);
	box(stdscr, 0, 0);
	mvwhline(stdscr, (maY / 4) * 1, 1, 0, maX - 2);
	mvwhline(stdscr, (maY / 4) * 2, 1, 0, maX - 2);
	mvwhline(stdscr, (maY / 4) * 3, 1, 0, maX - 2);
	mvwvline(stdscr, 1, (maX / 4) * 1, 0, maY - 2);
	mvwvline(stdscr, 1, (maX / 4) * 2, 0, maY - 2);
	mvwvline(stdscr, 1, (maX / 4) * 3, 0, maY - 2);
	show_board(env->board, maX / 8, maY / 8);
}

void	set_first_rand(t_env *env)
{
	int x;
	int	y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			env->board[y][x] = 0;
	}
	srand(time(NULL));
	env->board[rand() % 4][rand() % 4] = 2;
	put_nbr_in_case(env->board, rand_num(), rand_pop_each());
}

int 	main(int argc, char *argv[]) 
{
	int x;
	int y;
	int ch;
	initscr();
	t_env *env;

	set_first_rand(env->board);
	getmaxyx(stdscr, y, x);
	while (ch != 27)
	{
		print_board(env->board, x, y);
		tmp_board(env->board, env->tmp);
		ch = getch();
		get_moove_keys(env->board, ch);
	}
	endwin();
	return (0);
}
