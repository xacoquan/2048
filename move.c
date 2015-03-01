/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:32:32 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/01 18:43:44 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twothousandfortyheight.h"

void	left_rec(int **board, int y)
{
	int x;

	x = 0;
	while (++x < 4)
	{
		if (board[y][x - 1] == 0)
		{
			board[y][x - 1] = board[y][x];
			board[y][x] = 0;
		}
	}
}

void	move_left(int **board)
{
	int x;
	int y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (x < 1 && board[y][x + 1] == 0 && board[y][x + 2] == 0
				&& board[y][x] == board[y][x + 3])
				board[y][x] *= 2, board[y][x + 3] = 0;
			else if (x < 2 && board[y][x + 1] == 0
				&& board[y][x] == board[y][x + 2])
				board[y][x] *= 2, board[y][x + 2] = 0;
			else if (x != 3 && board[y][x] == board[y][x + 1])
				board[y][x] *= 2, board[y][x + 1] = 0;
		}
		left_rec(board, y);
		left_rec(board, y);
		left_rec(board, y);
	}
}

void	right_rec(int **board, int y)
{
	int x;

	x = 3;
	while (--x > -1)
	{
		if (board[y][x + 1] == 0)
		{
			board[y][x + 1] = board[y][x];
			board[y][x] = 0;
		}
	}
}

void	move_right(int **board)
{
	int x;
	int y;

	y = -1;
	while (++y < 4)
	{
		x = 4;
		while(--x >= 0)
		{
			if (x > 2 && board[y][x - 1] == 0 && board[y][x - 2] == 0
 				&& board[y][x] == board[y][x - 3])
				board[y][x] *= 2, board[y][x - 3] = 0;
			else if (x > 1 && board[y][x - 1] == 0
				&& board[y][x] == board[y][x - 2])
				board[y][x] *= 2, board[y][x - 2] = 0;
			else if (x != 0 && board[y][x] == board[y][x - 1])
				board[y][x] *= 2, board[y][x - 1] = 0;
		}
		right_rec(board, y);
		right_rec(board, y);
		right_rec(board, y);
	}
}
