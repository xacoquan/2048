/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:32:32 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 18:58:53 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twothousandfortyheight.h"

void	up_rec(int **board, int x)
{
	int y;

	y = 0;
	while (++y < 4)
	{
		if (board[y - 1][x] == 0)
		{
			board[y - 1][x] = board[y][x];
			board[y][x] = 0;
		}
	}
}

void 	move_up(int **board)
{
	int x;
	int y;

	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
		{
			if (y != 3 && board[y + 1][x] == 0 && board[y + 2][x] == 0
				&& board[y][x] == board[y + 3][x])
				board[y][x] *= 2, board[y + 3][x] = 0;
			else if (y < 2 && board[y + 1][x] == 0
				&& board[y][x] == board[y + 2][x])
				board[y][x] *= 2, board[y + 2][x] = 0;
			else if (y < 1 && board[y][x] == board[y + 1][x])
				board[y][x] *= 2, board[y + 1][x] = 0;
		}
		up_rec(board, x);
		up_rec(board, x); 
		up_rec(board, x);
	}
}

void	down_rec(int **board, int x)
{
	int y;

	y = 3;
	while (--y > -1)
	{
		if (board[y + 1][x] == 0)
		{
			board[y + 1][x] = board[y][x];
			board[x][y] = 0;
		}
	}
}

void	move_down(int **board)
{
	int x;
	int y;

	x = -1;
	while (++x < 4)
	{
		y = 4;
		while (--y > -1)
		{
			if (y > 2 && board[y - 1][x] == 0 && board[y - 2][x] == 0
				&& board[y][x] == board[y - 3][x])
				board[y][x] *= 2, board[y - 3][x] = 0;
			else if (y > 1 && board[y - 1][x] == 0
				&& board[y][x] == board[y - 2][x])
				board[y][x] *= 2, board[y - 2][x] = 0;
			else if (y != 0 && board[y][x] == board[y - 1][x])
				board[y][x] *= 2, board[y - 1][x] = 0;
		}
		down_rec(board, x);
		down_rec(board, x);
		down_rec(board, x);
	}
}
