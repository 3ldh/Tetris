/*
** display_help.c for display_help in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Feb 27 23:53:52 2016 maud marel
** Last update Thu Mar  3 13:23:30 2016 maud marel
*/

#include <unistd.h>
#include "tetris.h"

void	display_space(int i)
{
  while (++i < 25)
    write(1, " ", 1);
}

void	display_help_end()
{
  write(1, "  -kd --key-drop={K}", 20);
  display_space(19);
  write(1, "Set default DROP on key K\n", 26);
  write(1, "  -kq --key-quit={K}", 20);
  display_space(19);
  write(1, "Quit program when press key K\n", 30);
  write(1, "  -kp --key-pause={K}", 21);
  display_space(20);
  write(1, "Pause and restart game when press key K\n", 40);
  write(1, "  --map-size={row,col}", 22);
  display_space(21);
  write(1, "Set game size at row, col\n", 26);
  write(1, "  -w --without-next", 19);
  display_space(18);
  write(1, "Hide next tetrimino\n", 20);
  write(1, "  -d --debug", 12);
  display_space(11);
  write(1, "Debug mode\n", 11);
}

void	display_help()
{
  write(1, "Usage: ./tetris [options]\n", 26);
  write(1, "Options:\n", 9);
  write(1, "  --help", 8);
  display_space(7);
  write(1, "Display this help\n", 18);
  write(1, "  -l --level={num}", 18);
  display_space(17);
  write(1, "Start Tetris at level num\n", 26);
  write(1, "  -kl --key-left={K}", 20);
  display_space(19);
  write(1, "Move tetrimino on LEFT with key K\n", 34);
  write(1, "  -kr --key-right={K}", 21);
  display_space(20);
  write(1, "Move tetrimino on RIGHT with key K\n", 35);
  write(1, "  -kt --key-turn={K}", 20);
  display_space(19);
  write(1, "Turn tetrimino with key K\n", 26);
  display_help_end();
}
