/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 00:51:11 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 19:32:18 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twothousandfortyheight.h"



void    ft_bzero(void *s, size_t n)
{
    size_t      i;
    char        *chg;

    chg = s;
    i = 0;
    while (i < n)
    {
        chg[i] = 0;
        i++;
    }
}

void    *ft_memalloc(size_t size)
{
    void    *new;

    new = malloc(sizeof(void*) * size);
    if (new == NULL || size == 0)
        return (NULL);
    ft_bzero(new, size);
    return (new);
}

int 	no_z_case(int **board)
{
	int y;
	int x;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (board[y][x] == 0)
				return (1);
		}
	}
	return (0);
}

int 	check_board(int **board, int **tmp)
{
	int y;
	int x;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (board[y][x] != tmp[y][x])
				return (1);
		}
	}
	return (0);
}

int check_move(int **board, int **tmp)
{
	move_down(board);
	if (check_board(board, tmp))
	{
		tmp_board(board, tmp);
		return (1);
	}
	tmp_board(board, tmp);
	move_up(board);
	if (check_board(board, tmp))
	{
		tmp_board(board, tmp);
		return (1);
	}
	tmp_board(board, tmp);
	move_left(board);
	if (check_board(board, tmp))
	{
		tmp_board(board, tmp);
		return (1);
	}
	tmp_board(board, tmp);
	move_right(board);
	if (check_board(board, tmp))
	{
		tmp_board(board, tmp);
		return (1);
	}
	tmp_board(board, tmp);
	return (0);
}


int		put_nbr_in_case(int **board, int r, int r2)
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
			if (board[y][x] == 0)
			{
				i = 1;
				if (r > 0)
					(r--);
				else
				{
					board[y][x] = r2;	
					return (1);
				}
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

void 	tmp_board(int **board, int **tmp)
{
	int x;
	int y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			tmp[y][x] = board[y][x];
	}
}

int 	rand_pop_each(void)
{
	int r;
	srand(time(NULL));
	r = rand() % 100;
    if (r <= 10)
        return (4);
    return (2);
}

void	get_moove_keys(int **board, int ch2)
{
	t_env *env;

	while (ch2 != 27)
	{	
		if (ch2 == 68)
			move_left(board);
		else if (ch2 == 67)
			move_right(board);
		else if (ch2 == 65)
			move_up(board);
		else if (ch2 == 66)
			move_down(board);
		if (check_board(board, env->tmp))
			put_nbr_in_case(board, rand_num(), rand_pop_each());
		else if (!check_board(board, env->tmp) && !no_z_case(board) && !check_move(board, env->tmp))
		{
			mvprintw(50, 50 , "TA LOSE SALE MERDE");
			break;
		}
	}
}

void    show_board(int **board, int maX, int maY)
{
    int x;
    int y;

    y = -1;
    while (++y < 4)
    {
        x = -1;
        while (++x < 4)
        {
            if (board[y][x])
                mvprintw((y * 2 + 1) * maY, (x * 2 + 1) * maX, "%d", board[y][x]);
        }
    }
}

void	print_board(int **board, int maX, int maY)
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
	show_board(board, maX / 8, maY / 8);
}

void	set_first_rand(int **board)
{
	int x;
	int	y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			board[y][x] = 0;
	}
	srand(time(NULL));
	board[rand() % 4][rand() % 4] = 2;
	put_nbr_in_case(board, rand_num(), rand_pop_each());
}

int 	main(int argc, char *argv[]) 
{
	int x;
	int y;
	int ch;
	initscr();
	t_env *env;

//	env = (t_env *)ft_memalloc(sizeof(t_env));

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
