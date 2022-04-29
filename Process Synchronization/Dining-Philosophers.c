#include<stdio.h>
#include<stdlib.h>
#define size 5

int eat (int *tble, int *c_stick, int p)
{

  if (c_stick[p] == 1 && c_stick[(p + 1) % size] == 1)
    {
      printf ("Philosopher %d eating!\n", p + 1);
      tble[p] = 1;
      c_stick[p] = 0;
      c_stick[(p + 1) % size] = 0;

      return 0;
    }
  else
    {
      return -1;
    }

}

int think (int *tble, int *c_stick, int p)
{
  if (c_stick[p] != 0 || c_stick[(p + 1) % size] != 0)
    {
      return -1;
    }
  else
    {
      c_stick[p] = 1;
      c_stick[(p + 1) % size] = 1;
      tble[p] = 0;

      printf ("chopstick %d and %d placed!\n", p+1 ,(p + 2) % size);
      printf("Philosopher %d is thinking\n",p+1);
      return 0;
    }
}

int main ()
{
  int tble[5] = { 0, 0, 0, 0, 0 }, c_stick[5] =
  {
  1, 1, 1, 1, 1}, hungry_queue[10] ={0}, j = -1, s_q[5], j1 = -1;
  for (int i = 0; i < 5; i++)
    {
      int x = eat (tble, c_stick, i);
      if (x == -1)
 hungry_queue[++j] = i + 1;
      else
 s_q[++j1] = i + 1;
    }
  printf ("Hunger queue: ");
  for (int i = 0; i <= j; i++)
    printf ("%d ", hungry_queue[i]);
  printf ("\n");
  while (j1 > -1)
    {
      think (tble, c_stick, s_q[j1] - 1);
      j1--;
    }
  int count = 0;
  while (count <= j)
    {
      for (int i = 0; i <= j; i++)
 {
   if (hungry_queue[i] != 0)
     {
       int x = eat (tble, c_stick, hungry_queue[i] - 1);
       if (x == 0)
  {
    s_q[++j1] = hungry_queue[i];
    hungry_queue[i] = 0;
    count++;
  }
     }
 }
      for (int k = 0; k <= j1; k++)
 think (tble, c_stick, s_q[k] - 1);
    }
  return 0;
}
