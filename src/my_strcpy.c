/*
** my_strcpy.c for my_select in /home/brugue_m/PSU_2014_my_select
** 
** Made by bruguet Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Wed Jan  7 13:56:21 2015 bruguet Maxime
** Last update Mon Feb  9 16:44:07 2015 bruguet Maxime
*/

char		*my_strcpy(char *dest, char *src)
{
  int		i;

  i = -1;
  while (src[++i])
    dest[i] = src[i];
  dest[++i] = '\0';
  return (dest);
}
